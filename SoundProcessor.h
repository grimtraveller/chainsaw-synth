#ifndef SOUNDPROCESSOR_H
#define SOUNDPROCESSOR_H 1

#include "Buffer.h"
#include "Note.h"
#include "Parameters.h"

class SoundProcessor {
	
	protected:
	bool active;

	public:
	virtual void process(Buffer *buf, Parameters *p) { };
	virtual void note(Note note) {};

	bool isActive();

	SoundProcessor();
};

#endif
