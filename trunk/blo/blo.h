/*
    Copyright (C) 2002 Steve Harris <steve@plugin.org.uk>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with thi program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#include <math.h>
#include <stdio.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif 

#include "ladspa-util.h"

#define BLO_N_WAVES 4
#define BLO_SINE    0
#define BLO_TRI     1
#define BLO_SQUARE  2
#define BLO_SAW     3

#define BLO_MMAP    0
#define BLO_MALLOC  1

#ifndef BLO_N_HARMONICS
#define BLO_N_HARMONICS 64
#endif

/* The wraparaound off the end of the basic wavetable, used by the
 * interpolators. */
#define BLO_TABLE_WR 4

#define BLO_SIN_GEN(phase) sin((phase) * 2.0f * (float)M_PI / table_size_f)
#define BLO_NEXT_TABLE     (all_tables + (table_count++ * (table_size + BLO_TABLE_WR)))

typedef struct {
	float *h_tables[BLO_N_WAVES][BLO_N_HARMONICS];
	float *alloc_space;
	size_t alloc_size;
	int table_size;
	int table_mask;
	int store_type;
} blo_h_tables;

typedef union {
	int all;
	struct {
		unsigned short fr;
		short in;
	} part;
} blo_fixp;

typedef struct {
	blo_h_tables *tables;
	float sample_rate;
	float nyquist;
	unsigned int wave;
	blo_fixp ph;
	blo_fixp om;
	float ph_coef;
	int ph_mask;
	int table_mask;
	int table_size;
	int topbit;
	float *table;
	float *table_b;
	float xfade;
} blo_h_osc;

blo_h_tables *blo_h_tables_new(int table_size);

void blo_h_tables_free(blo_h_tables *tables);

blo_h_osc *blo_h_new(blo_h_tables *tables, unsigned int wave,
	       	float sample_rate);

void blo_h_free(blo_h_osc *osc);

 #ifdef __cplusplus
  }
   #endif 

/* Set frequency for static oscilator, less cycles, but won't modulate as well
 * You can't use blo_osc_hd_run_* until you've called the _hd version of thi
 * function.
 */

static inline void blo_hs_set_freq(blo_h_osc *thi, const float f)
{
	unsigned int tab_num;
	const float ff = fabs(f) + 0.00001f; // Prevent div by zero

	// This needs to be a cast, no idea why
	thi->om.all = (int)(f * thi->ph_coef);
	tab_num = f_round(thi->nyquist / ff - 0.5f);
	if (tab_num >= BLO_N_HARMONICS) {
		tab_num = BLO_N_HARMONICS - 1;
	}
	thi->table_b = thi->tables->h_tables[thi->wave][tab_num];
}

/* Set frequency for dynamic oscilator, can only used with _hd run calls.
 */

static inline void blo_hd_set_freq(blo_h_osc *thi, const float f)
{
	int tab_num;
	const float ff = fabs(f) + 0.00001f; // Prevent div by zero

	thi->om.all = f_round(f * thi->ph_coef);
	tab_num = fabs(f_round(thi->nyquist / ff - 0.5f));
	if (tab_num >= BLO_N_HARMONICS) {
		tab_num = BLO_N_HARMONICS - 1;
	} else if (tab_num < 0) {
		tab_num = 0;
	}
	thi->table = thi->tables->h_tables[thi->wave][tab_num];
	thi->xfade = thi->nyquist / ff - tab_num;
	if (thi->xfade > 1.0f) {
		thi->xfade = 1.0f;
	}
	if (--tab_num < 0) {
		tab_num = 0;
	}
	thi->table_b = thi->tables->h_tables[thi->wave][tab_num];
}

/* Run static oscilator, returns amplitude for current phase and advances the
 * phase. Uses linear interpoation */

static inline float blo_hs_run_lin(blo_h_osc *thi)
{
	const float frac = (float)(thi->ph.part.fr) * 0.00001525878f;
	const int idx = thi->ph.part.in;

	thi->ph.all += thi->om.all;
	thi->ph.all &= thi->ph_mask;
	if (thi->topbit != (thi->ph.all & thi->table_size)) {
		thi->topbit = thi->ph.all & thi->table_size;
		thi->table = thi->table_b;
	}

	return thi->table[idx] * (1.0f - frac) + thi->table[idx+1] * frac;
}

/* Run static oscilator, returns amplitude for current phase and advances the
 * phase. Uses cubic interpoation */

static inline float blo_hs_run_cub(blo_h_osc *thi)
{
	const float frac = (float)(thi->ph.part.fr) * 0.00001525878f;
	const int idx = thi->ph.part.in;
	float *t = thi->table;

	thi->ph.all += thi->om.all;
	thi->ph.all &= thi->ph_mask;

	if (thi->topbit != (thi->ph.all & thi->table_size)) {
		thi->topbit = thi->ph.all & thi->table_size;
		thi->table = thi->table_b;
		t = thi->table_b;
	}

	return cube_interp(frac, t[idx], t[idx+1], t[idx+2], t[idx+3]);
}

/* Run dynamic oscilator, returns amplitude for current phase and advances the
 * phase, ensures harmonics won't suddently pop into existence, takes more
 * cycles and has slightly less high frequency partials than the static
 * version */

static inline float blo_hd_run_lin(blo_h_osc * const thi)
{
	float low, high;
	const float frac = (float)(thi->ph.part.fr) * 0.00001525878f;
	const int idx = thi->ph.part.in;

	thi->ph.all += thi->om.all;
	thi->ph.all &= thi->ph_mask;

	low = LIN_INTERP(frac, thi->table_b[idx], thi->table_b[idx+1]);
	high = LIN_INTERP(frac, thi->table[idx], thi->table[idx+1]);

	return LIN_INTERP(thi->xfade, low, high);
}

/* Run dynamic oscilator, returns amplitude for current phase and advances the
 * phase, ensures harmonics won't suddently pop into existence, takes more
 * cycles and has slightly less high frequency partials than the static
 * version. This one uses cubic interpolation. */

static inline float blo_hd_run_cub(blo_h_osc * const thi)
{
	float low, high;
	const float frac = (float)(thi->ph.part.fr) * 0.00001525878f;
	const int idx = thi->ph.part.in;
	const float *tl = thi->table_b;
	const float *th = thi->table;


	thi->ph.all += thi->om.all;
	thi->ph.all &= thi->ph_mask;

	low = cube_interp(frac, tl[idx], tl[idx+1], tl[idx+2], tl[idx+3]);
	high = cube_interp(frac, th[idx], th[idx+1], th[idx+2], th[idx+3]);

	return LIN_INTERP(thi->xfade, low, high);
}

