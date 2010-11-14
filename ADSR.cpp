#include "ADSR.h"
#include "util.h"

ADSR::ADSR(){
	state = ATTACK;
}

#define ADSR_STEP(param) (1 / (p->sFreq * (param * 2) + 100))

void ADSR::process(Buffer *buf, Parameters *p){
	for(int i = 0; i < buf->size; i++){
		if (delay > 0) delay--;
		switch(state){
			case ATTACK:
		 		if(delay > 0) continue; // Don't process until delay has finished
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
				if(delay > 0) break; // Don't start release until delay has finished
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
		delay = n.delay;
		state = ATTACK;
		vol = 0;
		active = true;
	} else {
		state = RELEASE;
	}
}

