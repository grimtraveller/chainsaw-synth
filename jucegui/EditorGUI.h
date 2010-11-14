/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  14 Nov 2010 7:15:13pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_EDITORGUI_EDITORGUI_529600A9__
#define __JUCER_HEADER_EDITORGUI_EDITORGUI_529600A9__

//[Headers]     -- You can add your own extra header files here --
#include "../juce/juce_amalgamated.h"
#include "JuceProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class EditorGUI  : public AudioProcessorEditor,
                   public SliderListener,
                   public ComboBoxListener,
                   public ButtonListener
{
public:
    //==============================================================================
    EditorGUI (ChainsawAudioProcessor* ownerFilter);
    ~EditorGUI();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);
    void buttonClicked (Button* buttonThatWasClicked);


    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    ChainsawAudioProcessor* getProcessor() const {
		return static_cast<ChainsawAudioProcessor*> (getAudioProcessor());
	}

    String OscTypes[4];

    int OscType[4];

    //[/UserVariables]

    //==============================================================================
    Slider* stereoSpread;
    Label* label;
    Label* label2;
    Slider* detune;
    ComboBox* numOsc;
    Label* numOsc2;
    Slider* filterCutoff;
    Label* label3;
    Slider* filterCutoff2;
    Label* label4;
    TextButton* oscType1;
    TextButton* oscType2;
    TextButton* oscType3;
    TextButton* oscType4;
    Label* label5;
    Slider* oscVolume1;
    Slider* oscVolume2;
    Slider* oscVolume3;
    Slider* oscVolume4;
    Label* label6;
    Slider* oscOctave1;
    Slider* oscOctave2;
    Slider* oscOctave3;
    Slider* oscOctave4;
    Label* volADSR;
    Slider* volumeAttack;
    Slider* volumeDecay;
    Slider* volumeSustain;
    Slider* volumeRelease;
    Slider* filterAttack;
    Slider* filterDecay;
    Slider* filterSustain;
    Slider* filterRelease;
    Slider* filterADSREffect;
    Label* filterADSR;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    EditorGUI (const EditorGUI&);
    const EditorGUI& operator= (const EditorGUI&);
};


#endif   // __JUCER_HEADER_EDITORGUI_EDITORGUI_529600A9__
