#ifndef MOOGVCF_H
#define MOOGVCF_H 1

#include "SoundProcessor.h"

class MoogVCF : public SoundProcessor {
	double in[2][4];
	double out[2][4];

	public:
	
	MoogVCF();
	void reset();

	void process(Buffer *buf, Parameters *p);
//	void note(Note n);

	// double run(double input, double fc, double res);
};

#endif
