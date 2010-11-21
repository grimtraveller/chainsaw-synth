#include "ADSR.h"
#include "util.h"
#include <stdio.h>

ADSR::ADSR(){
	state = ATTACK;
	prevpar = -1;
	prevcalc = 0;
}

inline float ADSR::adsrStep(float param, Parameters *p) {
	if (prevpar!=param){
		prevcalc = 1 / (p->sFreq * linToLog(param) * 10 + 100);
	}
	return prevcalc;
}

void ADSR::process(Buffer *buf, Parameters *p){

	for(int i = 0; i < buf->size; i++){
		if (delay > 0) delay--;
		switch(state){
			case ATTACK:
		 		if(delay > 0) continue; // Don't process until delay has finished
				vol += adsrStep(p->vp.volAttack, p);
				if(vol >= 1){
					vol = 1;
					state = DECAY;
				}
				curvol = linToLog2(vol);
				break;
			case DECAY:
				vol -= adsrStep(p->vp.volDecay, p);
				if(vol <= p->vp.volSustain){
					vol = p->vp.volSustain;
					state = SUSTAIN;
				}
				if(vol <= 0){
					vol = 0;
					active = false;
				}
				curvol = linToLog(vol);
				break;
			case RELEASE:
				if(delay > 0) break; // Don't start release until delay has finished
				vol -= adsrStep(p->vp.volRelease, p);
				if(vol <= 0){
					vol = 0;
					active = false;
				}
				curvol = linToLog(vol);
				break;
			case SUSTAIN:
				break; // do nothing
		}

		buf->dataL[i] *= curvol;
		buf->dataR[i] *= curvol;

	}
}

void ADSR::note(Note n){
	if(n.type == Note::NOTE_ON){
		delay = n.delay;
		state = ATTACK;
		vol = 0;
		active = true;
	} else {
		state = RELEASE;
		delay = n.delay;
	}
}

