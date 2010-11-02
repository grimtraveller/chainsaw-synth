#include "MoogVCF.h"

// Constructor
MoogVCF::MoogVCF(){
	reset();
}

void MoogVCF::reset(){
	for(int pole = 0; pole < 4; pole++){
		for(int channel = 0; channel < 2; channel++){
			out[channel][pole] = 0;
			in[channel][pole] = 0;
		}
	}
}

void MoogVCF::process(Buffer *buf, Parameters *p)
{
	float fc = p->vp.filterCutoff * 0.95 + 0.05; // * (p->sFreq / 2);
	float res = p->vp.filterResonance * 4;
	float input[2];
 	for(int i = 0; i < buf->size; i++){
		
		input[0] = buf->dataL[i];
		input[1] = buf->dataR[i];

		double f = fc * 1.16;
		double fb = res * (1.0 - 0.15 * f * f);
		
		input[0] -= out[0][3] * fb;
		input[1] -= out[1][3] * fb;
		
		input[0] *= 0.35013 * (f*f)*(f*f);
		input[1] *= 0.35013 * (f*f)*(f*f);
		
		#define OUT out[channel][pole]
		#define IN in[channel][pole]
		#define INPUT input[channel]
		for(int channel = 0; channel < 2; channel++){
			for(int pole = 0; pole < 4; pole++){
				OUT = INPUT + 0.3 * IN + (1 - f) * OUT;
				IN = INPUT;
				INPUT = OUT;
			}
		}
		buf->dataL[i] = out[0][3];
		buf->dataR[i] = out[1][3];
	}
}

