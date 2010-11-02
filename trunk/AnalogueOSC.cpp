
#include "AnalogueOSC.h"
#include <math.h>
#include <stdlib.h>

#define PI 3.1415926535897932384626433832795

AnalogueOsc::AnalogueOsc(){
      tables = blo_h_tables_new(512);
      osc = blo_h_new(tables, BLO_SINE, (float)44100); // FIXME!!!
      fs = (float)44100;
      itm1 = 0.0f;
      otm1 = 0.0f;
      otm2 = 0.0f;
      rnda = 43437;
      rndb = 111145;
      warm = 0.03; // FIXME: add to voice params
      instab = 0.01; // ditto

}

AnalogueOsc::~AnalogueOsc(){
      blo_h_tables_free(tables);
      blo_h_free(this->osc);
}

void AnalogueOsc::process(Buffer *buf, Parameters *p) {

      int pos;
      float x, y;
      int wave;
      const float q = warm - 0.999f;
      const float leak = 1.0f - warm * 0.02f;
      const unsigned int max_jump = (unsigned int)f_round(instab * 30000.0f) + 1;

	//  We don't need to recalculate frequency and oscStep every time
	if(oldNote != pressedNote.note or oldDetune != detune){
		frequency = 440 * pow(2, (((pressedNote.note + detune)-69)/12));
		oldNote = pressedNote.note;
		oldDetune = detune;
	}

	wave = 0;
      switch(type){
      	case SINE: 	wave = 1; break;
	case TRIANGLE:	wave = 2; break;
	case SQUARE:	wave = 3; break;
	case SAWTOOTH: 	wave = 4; break;
      }

      osc->wave = LIMIT(f_round(wave) - 1, 0, BLO_N_WAVES-1);
      osc->nyquist = fs * (0.47f - f_clamp(warm, 0.0f, 1.0f) * 0.41f);
      blo_hd_set_freq(osc, frequency);

      tables = tables; // So gcc doesn't think it's unused

      for (pos = 0; pos < buf->size; pos++) {
	x = blo_hd_run_cub(osc);
        rnda += 432577;
        rnda *= 47;
	rndb += 7643113;
        rnda *= 59;
        osc->ph.all += (((rnda + rndb)/2) % max_jump) - max_jump/2;
        osc->ph.all &= osc->ph_mask;
	y = (x - q) / (1.0f - f_exp(-1.2f * (x - q))) +
              q / (1.0f - f_exp(1.2f * q));
	/* Catch the case where x ~= q */
	if (fabs(y) > 1.0f) {
		y = 0.83333f + q / (1.0f - f_exp(1.2f * q));
	}
	otm2 = otm1;
        otm1 = leak * otm1 + y - itm1;
        itm1 = y;

	float s = (otm1 + otm2) * 0.5f;
	buf->dataL[pos] += s * ((pan + 1) / 2) * vol * (pressedNote.velocity / 128.0);
	buf->dataR[pos] += s * (1 - ((pan + 1) / 2)) * vol * (pressedNote.velocity / 128.0);

      }

      this->itm1 = itm1;
      this->otm1 = otm1;
      this->otm2 = otm2;
      this->rnda = rnda;
      this->rndb = rndb;	
}

void AnalogueOsc::note(Note n){
	if(n.type == Note::NOTE_ON){
		pressedNote = n;
		active = true;
	} 
}
