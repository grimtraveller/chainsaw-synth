/** @file simple_client.c
 *
 * @brief This simple client demonstrates the most basic features of JACK
 * as they would be used by many applications.
 */

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <jack/jack.h>

#include "synthinit.h"
#include "Parameters.h"

#include "alsamidi.h"

#include "synthui.h"

#include <QThread>

jack_port_t *output_portL;
jack_port_t *output_portR;
jack_client_t *client;
SoundProcessor *processor = 0;
Buffer *mainBuf;
static Parameters parameters;

SynthWindow *synthGUI = 0;

class MIDIProcessor : public QThread {
	AlsaMidi *mid;
	
        public:

	MIDIProcessor(){
		mid = new AlsaMidi(processor);
	}

	~MIDIProcessor(){
		delete mid;
	}

        void run() {
                mid->filterData();
        }
};



/**
 * The process callback for this JACK application is called in a
 * special realtime thread once for each audio cycle.
 *
 * This client does nothing more than copy data from its input
 * port to its output port. It will exit when stopped by 
 * the user (e.g. using Ctrl-C on a unix-ish operating system)
 */
int
process (jack_nframes_t nframes, void *arg)
{
	jack_default_audio_sample_t *outL;
	jack_default_audio_sample_t *outR;
	
	outL = (jack_default_audio_sample_t *)jack_port_get_buffer (output_portL, nframes);
	outR = (jack_default_audio_sample_t *)jack_port_get_buffer (output_portR, nframes);
	
	mainBuf->clear();
	mainBuf->size = nframes;
	
	// COPY the latest props from GUI
	if(synthGUI != 0){
		parameters.vp = synthGUI->vp;
	}

	processor->process(mainBuf, &parameters);

	memcpy (outL, mainBuf->dataL,
		sizeof (jack_default_audio_sample_t) * nframes);

	memcpy (outR, mainBuf->dataR,
		sizeof (jack_default_audio_sample_t) * nframes);


	return 0;      
}

/**
 * JACK calls this shutdown_callback if the server ever shuts down or
 * decides to disconnect the client.
 */
void
jack_shutdown (void *arg)
{
	exit (1);
}

void setOutputProcessor(SoundProcessor *p){
	processor = p;
}

int getMaxBufferSize(){
	return jack_get_buffer_size(client);
}

int
main (int argc, char *argv[])
{
	const char **ports;
	const char *client_name = "simple";
	const char *server_name = NULL;
	jack_options_t options = JackNullOption;
	jack_status_t status;




	/* open a client connection to the JACK server */

	client = jack_client_open (client_name, options, &status, server_name);

	synthInit();

	if (client == NULL) {
		fprintf (stderr, "jack_client_open() failed, "
			 "status = 0x%2.0x\n", status);
		if (status & JackServerFailed) {
			fprintf (stderr, "Unable to connect to JACK server\n");
		}
		exit (1);
	}
	if (status & JackServerStarted) {
		fprintf (stderr, "JACK server started\n");
	}
	if (status & JackNameNotUnique) {
		client_name = jack_get_client_name(client);
		fprintf (stderr, "unique name `%s' assigned\n", client_name);
	}

	/* tell the JACK server to call `process()' whenever
	   there is work to be done.
	*/

	jack_set_process_callback (client, process, 0);

	/* tell the JACK server to call `jack_shutdown()' if
	   it ever shuts down, either entirely, or if it
	   just decides to stop calling us.
	*/

	jack_on_shutdown (client, jack_shutdown, 0);

	/* display the current sample rate. 
	 */

	printf ("engine sample rate: %i\n",
		jack_get_sample_rate (client));

	parameters.sFreq = jack_get_sample_rate (client);
	
	mainBuf = new Buffer(jack_get_buffer_size(client));

	/* create two ports */

	output_portL = jack_port_register (client, "output L",
					  JACK_DEFAULT_AUDIO_TYPE,
					  JackPortIsOutput, 0);

	output_portR = jack_port_register (client, "output R",
					  JACK_DEFAULT_AUDIO_TYPE,
					  JackPortIsOutput, 0);



	/* Tell the JACK server that we are ready to roll.  Our
	 * process() callback will start running now. */

	if (jack_activate (client)) {
		fprintf (stderr, "cannot activate client");
		exit (1);
	}

	/* Connect the ports.  You can't do this before the client is
	 * activated, because we can't make connections to clients
	 * that aren't running.  Note the confusing (but necessary)
	 * orientation of the driver backend ports: playback ports are
	 * "input" to the backend, and capture ports are "output" from
	 * it.
	 */

	ports = jack_get_ports (client, NULL, NULL,
				JackPortIsPhysical|JackPortIsInput);
	if (ports == NULL) {
		fprintf(stderr, "no physical playback ports\n");
		exit (1);
	}

	if (jack_connect (client, jack_port_name (output_portL), ports[0]) or
	    jack_connect (client, jack_port_name (output_portR), ports[1])
	) {
		fprintf (stderr, "cannot connect output ports\n");
	}

	free (ports);

	/* keep running until stopped by the user */

	// Start ALSA Midi
	/*AlsaMidi mid(processor);
	mid.filterData();*/

	MIDIProcessor midp;
	midp.start();

	// Start up application

	QApplication app(argc, argv);
	synthGUI = new SynthWindow(0);
	synthGUI->show();
	return app.exec();

	/* this is never reached but if the program
	   had some other way to exit besides being killed,
	   they would be important to call.
	*/

	jack_client_close (client);
	exit (0);
}
