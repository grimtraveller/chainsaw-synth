#ifndef OSC_H
#define OSC_H 1

#include "SoundProcessor.h"
#include "blo/blo.h"

enum AnalogueOscType {
	SAWTOOTH,
	SINE,
	SQUARE,
	TRIANGLE
};

class AnalogueOsc : public SoundProcessor {

	float frequency;
	float oscPos;
	float oscStep;
	Note pressedNote;

	blo_h_tables * tables;
	blo_h_osc *osc;
	float fs;
	float itm1;
	float otm1;
	float otm2;
	unsigned int rnda;
	unsigned int rndb;

	float warm;
	float instab;

	// Old stuff, so we don't have to recalculate note every time
	float oldNote;
	float oldDetune;

	public:
	AnalogueOscType type;
	float pan;
	float detune;
	float vol;
	
	void process(Buffer *buf, Parameters *p);
	void note(Note note);
	void setType(AnalogueOscType t);

	AnalogueOsc();
	~AnalogueOsc();
};


#endif
