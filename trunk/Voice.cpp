#include "Voice.h"
	
Voice::Voice(){
	vbuf = new Buffer(1024);
}

Voice::~Voice(){
	delete vbuf;
}

void Voice::process(Buffer *buf, Parameters *p){
	vbuf->clear();
	vbuf->size = buf->size;
	// Center oscillator
	Osc &o = osc[0];
	
	o.type = (OscType)p->vp.g[0].type;
	o.detune = p->vp.g[0].octave * 12;
	o.vol = p->vp.g[0].vol;

	o.process(vbuf, p);
	
	// Other layers (come in pairs)
	int layers = ((p->vp.numosc - 1) / 2);
	for(int i = 0; i < layers; i++){
		Osc &lo = osc[2 * i + 1];
		Osc &ro = osc[2 * i + 2];
		OscGroupParameters ogp = p->vp.g[i + 1];
		
		// Type same for both osc
		ro.type = lo.type = (OscType)ogp.type;

		// Volume same for both osc
		ro.vol = lo.vol = ogp.vol;
		
		// Panning
		ro.pan = p->vp.stereoSpread / layers * (i + 1);
		lo.pan = -ro.pan;
		
		float detune = p->vp.detune * (0.3 * (i + 1));

		if(i % 2){
			lo.detune = detune + (ogp.octave * 12);
			ro.detune = -detune + (ogp.octave * 12);
		} else {
			lo.detune = -detune + (ogp.octave * 12);
			ro.detune = detune + (ogp.octave * 12);
		}

		lo.process(vbuf, p);
		ro.process(vbuf, p);
	}

	adsr.process(vbuf, p);
	if(!adsr.isActive()){
		active = false; // Deactivate
	}

	filter.process(vbuf, p);

	buf->mixFrom(vbuf);
}

void Voice::note(Note n){
	adsr.note(n);
	filter.note(n);

	if(n.type == Note::NOTE_ON){
		curNote = n;
		active = true;
		filter.reset();
	}

	for(int i = 0; i < NUM_OSC; i++){
		osc[i].note(n);
	}
}
