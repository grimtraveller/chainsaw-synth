#ifndef VOICEPARAMETERS_H
#define VOICEPARAMETERS_H 1

#define NUM_OSC_GROUPS 4

// Keeping the struct opaque
struct OscGroupParameters {
	int type;
	float vol;
	int octave;
};

struct VoiceParameters {
	float stereoSpread;
	float detune;
	float octaveSpread;
	int numosc;
	OscGroupParameters g[NUM_OSC_GROUPS];
	float volAttack;
	float volDecay;
	float volSustain;
	float volRelease;
	float filterCutoff;
	float filterResonance;
};

#endif