#ifndef VOICEMANAGER_H
#define VOICEMANAGER_H 1
#include "Voice.h"
#include "SoundProcessor.h"

#define NUM_VOICE 16

class VoiceManager : public SoundProcessor {
	Voice voice[NUM_VOICE];

	public:
	void process(Buffer *buf, Parameters *p);
	void note(Note n);
	VoiceManager();
	~VoiceManager();
};

#endif
