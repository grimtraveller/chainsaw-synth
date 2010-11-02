HEADERS=\
	ADSR.h\
	alsamidi.h\
	Buffer.h\
	Note.h\
	AnalogueOsc.h\
	SoundProcessor.h\
	synthinit.h\
	Voice.h\
	VoiceManager.h\
	synthui.h\
	VoiceParameters.h\
	Parameters.h\
	MoogVCF.h\
	Osc.h\
	blo/blo.h\
	blo/ladspa-util.h

SOURCES=\
	ADSR.cpp\
	alsamidi.cpp\
	Buffer.cpp\
	jackclient.cpp\
	AnalogueOsc.cpp\
	Osc.cpp\
	SoundProcessor.cpp\
	synthinit.cpp\
	Voice.cpp\
	VoiceManager.cpp\
	MoogVCF.cpp\
	blo/ladspa-util.c\
	blo/blo.c

FORMS=synth.ui
QMAKE_LFLAGS=-lasound -ljack
CONFIG+=UI
QMAKE_CXXFLAGS_WARN_ON=-Wall -Wno-unused
