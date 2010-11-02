#ifndef ADSR_H
#define ADSR_H 1
#include "SoundProcessor.h"

class ADSR : public SoundProcessor {
	
	float vol;

	enum State {
		ATTACK,
		DECAY,
		SUSTAIN,
		RELEASE
	};

	State state;

	public:
	ADSR();
	void process(Buffer *buf, Parameters *p);
	void note(Note n);
};

#endif
