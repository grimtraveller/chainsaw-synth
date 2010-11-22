#ifndef VOICE_H
#define VOICE_H 1
#include "Osc.h"
#include "SoundProcessor.h"
#include "ADSR.h"
#include "MoogVCF.h"

#define NUM_OSC 8

class Voice : public SoundProcessor {
	Osc osc[NUM_OSC];
	ADSR adsr;
	MoogVCF filter;
	
	Buffer *vbuf;
	Note curNote;

	public:
	void process(Buffer *buf, Parameters *p);
	void note(Note n);
	float getNote() { return curNote.note; };
	Voice();
	~Voice();
};

#endif
