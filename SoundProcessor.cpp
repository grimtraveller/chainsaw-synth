#include "SoundProcessor.h"

bool SoundProcessor::isActive() 
{ 
	return active;
}

SoundProcessor::SoundProcessor() 
{ 
	active = false;
}

