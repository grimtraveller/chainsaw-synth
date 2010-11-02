#ifndef DREAMSCULPT_ALSAMIDI_H
#define DREAMSCULPT_ALSAMIDI_H 1
#include <alsa/asoundlib.h>
#include "SoundProcessor.h"

class AlsaMidi {
	private:
	snd_seq_t *seq;
	
	SoundProcessor *sproc;

	int iport, oport;
	
	int newnote;

	snd_seq_t *openClient();
	int getWritePort();
	public:
	void noteOn(int channel, int note, int velocity);
	void noteOff(int channel, int note);
	double updateArpeggiators();
	void filterData();
	AlsaMidi(SoundProcessor *proc);
};

#endif
