#include "Osc.h"
#include <math.h>
#include <stdlib.h>

#define PI 3.1415926535897932384626433832795

/**
 * Initializer.
 * 
 * Sets the default values.
 */
Osc::Osc(){
	type = SINE; // Oscillator type (see enum in Osc.h)
	pan = 0; // Panning. 0 means center.
	phase = 0; // Phase (0.0 -- 1.0 means one oscillation)
	oldNote = 0; // Remembers last played note, so it wouldn't 
		     // need to recalculate the pitch on every cycle
	oldDetune = 0; // Old detune, ditto
	delay = 0;
}

void Osc::process(Buffer *buf, Parameters *p) {
	if(!active) return; // Not really neccesary, but let's keep it
	                    // Don't do any processing when the osc is marked inactive

	//  We don't need to recalculate frequency and oscStep every time
	if(oldNote != pressedNote.note or oldDetune != detune){
		// Calculate pitch 
		frequency = 440 * pow(2, (((pressedNote.note + detune)-69)/12));
		oscStep = frequency / p->sFreq; // How much do we need to increase phase per sample.
		oldNote = pressedNote.note; // Remember the note and detune so we wouldn't need 
		oldDetune = detune;         // to come back here later.
	}

	// MAIN LOOP
	// Iterates over the buffer and fills it with oscillator output
	for(int i = 0; i < buf->size; i++){
		if(delay > 0) {
			delay--;
			continue; // Don't start OSC delay has finished
		}

		float s; // One sample, we put the calculated sample in thi variable
		
		phase += oscStep; // Increase phase by one oscilator step.
		if(phase >= 1.0){ // If we have gone over 1.0
			phase = phase - floorf(phase); // Recalculate it (phase = 1.1, phase = 1.1 - 1 = 0.1)
		}

		// Switch to select the oscillator type.
		// All implementations are naive and not counting with possibility of aliasing
		switch(type){
			case SINE: // Sine wave, simple sine function
				s = sin(phase * (2 * PI));
				break;
			case SAWTOOTH: // Sawtooth wave, translates phase (0 ... 1) into (-1 ... 1)
				s = phase * 2 - 1;
				break;
			case TRIANGLE: // Triangle wave, if phase < 0.5 go up, else go down
				if(phase <= 0.5){
					s = phase * 4 - 1;
				} else {
					s = 1 - ((phase - 0.5) * 4);
				}
				break;
			case SQUARE: // Square wave if phase < 0.5 we get -1, else we get 1
				 s = (phase > 0.5)?1:-1;
				break;
			default: // Unknown osc type, filling with silence
				s = 0; // Should never reach here on normal operation
				break;
		}
		
		// Copy the calculated sample into buffer by appling velocity, panning and volume
		// transformations.
		// Panning variable is between -1 (left), 0 (center), 1 (right).
		// To apply it correctly we want 50% volume on both channels when centered
		// and 100% volume in one channel when panned to either left or right.
		//
		//                   panning_______    vol   velocity_____________________
		buf->dataL[i] += s * ((pan + 1) / 2) * vol * (pressedNote.velocity / 128.0);
		buf->dataR[i] += s * (1 - ((pan + 1) / 2)) * vol * (pressedNote.velocity / 128.0);
	}	
}

/**
 * Note event.
 *
 * When user presses note on keyboard this function is called and it updates the variables in
 * OSC object.
 *
 * @param Note n Note object containing note number, velocity, note on/note off info.
 */
void Osc::note(Note n){
	if(n.type == Note::NOTE_ON){ // In case the event is a note on
		phase = rand() / (double)RAND_MAX;
		pressedNote = n; // Remember the pressed note in object 
		active = true; // Mark this oscillator active (not really needed as Voice keeps track of this)
		delay = n.delay; // If note on has delay, use it to make sound start precise
		// Nothing else is going on in here, rest is done in processing function
	} 
}
