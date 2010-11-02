#ifndef SYNTHUI_H
#define SYNTHUI_H 1

#include <ui_synth.h>
#include "VoiceParameters.h"

class SynthWindow : public QMainWindow
{
     Q_OBJECT

 public:
     VoiceParameters vp;
     SynthWindow(QWidget *parent = 0){ 
     	ui.setupUi(this); 
 	vp.stereoSpread = 0;
	vp.detune = 0;
	vp.octaveSpread = 0;
	vp.numosc = 1;
	for(int i = 0; i < NUM_OSC_GROUPS; i++){
		vp.g[i].type = 0;
		vp.g[i].vol = 0.5;
		vp.g[i].octave = 0;

	}
	vp.volAttack = 0;
	vp.volDecay = 0;
	vp.volSustain = 1;
	vp.volRelease = 0;
	vp.filterResonance = 0;
	vp.filterCutoff = 1;
    
     }

 private slots:
 	void on_stereoSpread_valueChanged(int v) {
		vp.stereoSpread = v / 100.0;	
	}
	void on_detune_valueChanged(int v) {
		vp.detune = v / 100.0;	
	}
	void on_volAttack_valueChanged(int v) {
		vp.volAttack = v / 100.0;	
	}

	void on_volDecay_valueChanged(int v) {
		vp.volDecay = v / 100.0;	
	}

	void on_volSustain_valueChanged(int v) {
		vp.volSustain = v / 100.0;	
	}
	
	void on_volRelease_valueChanged(int v) {
		vp.volRelease = v / 100.0;	
	}

	void on_numosc_currentIndexChanged(int v){
		vp.numosc = v * 2 + 1;
		printf("Set number of oscillators to %i\n", vp.numosc);
	}
	
	void on_g1Type_currentIndexChanged(int v){
		vp.g[0].type = v;
	}

	void on_g2Type_currentIndexChanged(int v){
		vp.g[1].type = v;
	}

	void on_g3Type_currentIndexChanged(int v){
		vp.g[2].type = v;
	}

	void on_g4Type_currentIndexChanged(int v){
		vp.g[3].type = v;
	}

	void on_g1Octave_valueChanged(int v){
		vp.g[0].octave = v;
	}

	void on_g2Octave_valueChanged(int v){
		vp.g[1].octave = v;
	}

	void on_g3Octave_valueChanged(int v){
		vp.g[2].octave = v;
	}

	void on_g4Octave_valueChanged(int v){
		vp.g[3].octave = v;
	}

	void on_g1Vol_valueChanged(int v){
		vp.g[0].vol = v / 100.0;
	}

	void on_g2Vol_valueChanged(int v){
		vp.g[1].vol = v / 100.0;
	}

	void on_g3Vol_valueChanged(int v){
		vp.g[2].vol = v / 100.0;
	}

	void on_g4Vol_valueChanged(int v){
		vp.g[3].vol = v / 100.0;
	}

	void on_filterCutoff_valueChanged(int v) {
		vp.filterCutoff = v / 100.0;	
	}

	void on_filterResonance_valueChanged(int v) {
		vp.filterResonance = v / 100.0;	
	}
/*
	float octaveSpread;
*/
 private:
     Ui_MainWindow ui;
 };

#endif
