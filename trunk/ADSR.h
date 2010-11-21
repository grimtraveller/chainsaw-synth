#ifndef ADSR_H
#define ADSR_H 1
#include "SoundProcessor.h"

class ADSR : public SoundProcessor {
	
	float vol;
	float curvol;
	float prevpar;
	float prevcalc;

	enum State {
		ATTACK,
		DECAY,
		SUSTAIN,
		RELEASE
	};

	State state;

	inline float adsrStep(float param, Parameters *p);

	public:
	ADSR();
	void process(Buffer *buf, Parameters *p);
	void note(Note n);
};

#endif
