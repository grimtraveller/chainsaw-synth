#ifndef BUFFER_H
#define BUFFER_H 1

class Buffer {
	public: 
	float *dataL;
	float *dataR;
	int size;
	
	Buffer(int size);
	~Buffer();
	void copyFrom(Buffer *buf);
	void mixFrom(Buffer *buf);
	void clear();
};

#endif
