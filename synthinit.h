#ifndef SYNTHINIT_H
#define SYNTHINIT_H 1

#include "SoundProcessor.h"

void synthInit();
void setOutputProcessor(SoundProcessor *p);
int getMaxBufferSize();

#endif
