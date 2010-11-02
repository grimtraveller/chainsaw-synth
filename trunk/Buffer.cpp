#include "Buffer.h"
#include <string.h>

Buffer::Buffer(int size){
	dataL = new float[size];
	dataR = new float[size];
	this->size = size;
	clear();
}

void Buffer::clear(){
	memset(dataL, 0, size * sizeof(float)); 
	memset(dataR, 0, size * sizeof(float)); 
}

void Buffer::copyFrom(Buffer *buf){
	memcpy(dataL, buf->dataL, buf->size * sizeof(float));
	memcpy(dataR, buf->dataR, buf->size * sizeof(float));
	this->size = buf->size;
}

void Buffer::mixFrom(Buffer *buf){
	for(int i = 0; i < buf->size; i++){
		dataL[i] += buf->dataL[i];
		dataR[i] += buf->dataR[i];
	}
}
Buffer::~Buffer(){
	delete dataL;
	delete dataR;
}
