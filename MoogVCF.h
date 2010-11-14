#ifndef MOOGVCF_H
#define MOOGVCF_H 1

#include "SoundProcessor.h"

class MoogVCF : public SoundProcessor {
	double in[2][4];
	double out[2][4];

	enum State {
		ATTACK,
		DECAY,
		SUSTAIN,
		RELEASE,
		DONE
	};

	int state;
	float adsrFlt;

	public:
	
	MoogVCF();
	void reset();

	void process(Buffer *buf, Parameters *p);
	void note(Note n);

};

#endif
