#include "synthinit.h"
#include "VoiceManager.h"

void synthInit(){
	setOutputProcessor(new VoiceManager());
}
