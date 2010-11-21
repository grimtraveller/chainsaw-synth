/*
 * util.cpp
 *
 *  Created on: Nov 14, 2010
 *      Author: suva
 */

#include <util.h>
#include <math.h>

double ltlLUT[1000];
double ltl2LUT[1000];

double _linToLog(double v) {
    return 1 - log10((1 - v) * 9.0 + 1.0);
}

double _linToLog2(double v) {
    return log10(v * 9.0 + 1.0);
}

double linToLog(double v) {
	return ltlLUT[(int)(v * 999)];
}

double linToLog2(double v) {
	return ltl2LUT[(int)(v * 999)];
}

void calculateLUTs(){
	for (int i = 0; i < 1000; i++) {
		ltlLUT[i] = _linToLog(i / 1000.0f);
		ltl2LUT[i] = _linToLog2(i / 1000.0f);
	}
}
