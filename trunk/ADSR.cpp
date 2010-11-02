#include "ADSR.h"
#include <math.h>

double linToLog(double v) {
        return 1 - log10((1 - v) * 9.0 + 1.0);
}


ADSR::ADSR(){
	state = ATTACK;
}

#define ADSR_STEP(param) (1 / (p->sFreq * (param * 2) + 100))

void ADSR::process(Buffer *buf, Parameters *p){
	for(int i = 0; i < buf->size; i++){
		switch(state){
			case ATTACK:
				vol += ADSR_STEP(p->vp.volAttack);
				if(vol >= 1){
					vol = 1;
					state = DECAY;
				}
				break;
			case DECAY:
				vol -= ADSR_STEP(p->vp.volDecay);
				if(vol <= p->vp.volSustain){
					vol = p->vp.volSustain;
					state = SUSTAIN;
				}
				break;
			case RELEASE:
				vol -= ADSR_STEP(p->vp.volRelease);
				if(vol <= 0){
					vol = 0;
					active = false;
				}
				break;
			case SUSTAIN:
				break; // Do nothing
		}
		buf->dataL[i] *= linToLog(vol);
		buf->dataR[i] *= linToLog(vol);

	}
}

void ADSR::note(Note n){
	if(n.type == Note::NOTE_ON){
		state = ATTACK;
		vol = 0;
		active = true;
	} else {
		state = RELEASE;
	}
}

