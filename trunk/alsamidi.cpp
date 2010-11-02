#include <alsa/asoundlib.h>
#include "alsamidi.h"


snd_seq_t *AlsaMidi::openClient()
{
        snd_seq_t *handle;
        int err;
        err = snd_seq_open(&handle, "default", SND_SEQ_OPEN_DUPLEX, 0);
        if (err < 0)
                return NULL;
        snd_seq_set_client_name(handle, "Synth");
        return handle;
}


int AlsaMidi::getWritePort()
{
        return snd_seq_create_simple_port(seq, "input",
                        SND_SEQ_PORT_CAP_WRITE|SND_SEQ_PORT_CAP_SUBS_WRITE,
                        SND_SEQ_PORT_TYPE_MIDI_GENERIC);
}

void AlsaMidi::filterData() { 
	snd_seq_event_t *ev;
	Note note;
	while (snd_seq_event_input(seq, &ev) >= 0) {

		if(ev->type == SND_SEQ_EVENT_NOTE){
			printf("Note?\n");
		}

		if(ev->type == SND_SEQ_EVENT_NOTEON or 
		   ev->type == SND_SEQ_EVENT_NOTEOFF
		){
			snd_seq_ev_note nte;
			nte = ev->data.note;
			note.note = nte.note;
			note.velocity = nte.velocity;
			if(ev->type == SND_SEQ_EVENT_NOTEOFF){
				note.type = Note::NOTE_OFF;
			} else {
				note.velocity = nte.velocity;
				note.type = Note::NOTE_ON;
			}
			sproc->note(note);
		}
	}
}

// Constructor
AlsaMidi::AlsaMidi(SoundProcessor *proc){
	printf("Constructing...\n");
	sproc = proc;
	seq = openClient();
	iport = getWritePort();
}
