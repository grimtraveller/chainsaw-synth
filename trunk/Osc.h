#ifndef OSC_H
#define OSC_H 1

#include "SoundProcessor.h"
/**
 * Oscillator type enum
 */
enum OscType {
	SAWTOOTH,
	SINE,
	SQUARE,
	TRIANGLE
};

class Osc : public SoundProcessor {

	float frequency; // Frequency of the oscillator, not really important, oscStep is more important
	float phase; // Phase position between 0.0 ... 1.0
	float oscStep; // Phase step on every sample, this keeps the oscillator pitch
	Note pressedNote; // Note info which was pressed
	
	// Old stuff, so we don't have to recalculate note every time
	float oldNote; // Previous note number
	float oldDetune; // Detuning

	public:
	// Those variables are made public because Voice changes them
	OscType type; // Oscillator type
	float pan; // Panning
	float detune; 
	float vol; // Volume
	
	void process(Buffer *buf, Parameters *p); // Main processing function, this is where the sound comes
						  // from. Called by parent (Voice)
	void note(Note note); // Note event trigger, called by parent.

	Osc(); // Constructor, initializes the stuff
};


#endif
