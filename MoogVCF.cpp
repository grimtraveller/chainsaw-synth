#include "MoogVCF.h"
#include "util.h"

#define ADSR_STEP(param) (1 / (p->sFreq * (param * 2) + 100))

// Constructor
MoogVCF::MoogVCF(){
	state = DONE;
	delay = 0;
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
	float res = p->vp.filterResonance * 4;
	float input[2];
 	for(int i = 0; i < buf->size; i++){
 		if (delay > 0) delay--;
 		// ADSR processing
 		switch(state){
			case ATTACK:
		 		if(delay > 0) continue; // Don't process until delay has finished
				adsrFlt += ADSR_STEP(p->vp.filterAttack);
				if(adsrFlt >= 1){
					adsrFlt = 1;
					state = DECAY;
				}
				break;
			case DECAY:
				adsrFlt -= ADSR_STEP(p->vp.filterDecay);
				if(adsrFlt <= p->vp.filterSustain){
					adsrFlt = p->vp.filterSustain;
					state = SUSTAIN;
				}
				break;
			case RELEASE:
				if(delay > 0) break; // Don't start release until delay has finished
				adsrFlt -= ADSR_STEP(p->vp.filterRelease);
				if(adsrFlt <= 0){
					adsrFlt = 0;
					state = DONE;
				}
				break;
			case SUSTAIN:
			case DONE:
				break; // Do nothing
		}

 		float cutoff = p->vp.filterCutoff + (adsrFlt * p->vp.filterADSREffect);

 		if(cutoff < 0) {
 			cutoff = 0;
 		}
 		if(cutoff > 1) {
 			cutoff = 1;
 		}

 		// MOOG VCF algorithm
 		float fc = ( cutoff )* 0.95 + 0.05; // * (p->sFreq / 2);
		
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

void MoogVCF::note(Note n){
	if(n.type == Note::NOTE_ON){
		delay = n.delay;
		state = ATTACK;
		adsrFlt = 0;
	} else {
		delay = n.delay;
		state = RELEASE;
	}
}

