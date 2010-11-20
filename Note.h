#ifndef NOTE_H
#define NOTE_H 1

class Note {
	public:

	enum Type {
		NOTE_ON,
		NOTE_OFF
	};

	float note;
	float velocity;
	int delay;
	Type type;

};

#endif 
