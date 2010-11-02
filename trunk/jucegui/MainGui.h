/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  24 May 2009 2:54:57 pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.11

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_MAINGUI_MAINGUI_408B28EF__
#define __JUCER_HEADER_MAINGUI_MAINGUI_408B28EF__

//[Headers]     -- You can add your own extra header files here --
#include "juce.h"
//[/Headers]

#include "OscGroupEditor.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainGui  : public Component,
                 public SliderListener,
                 public ButtonListener
{
public:
    //==============================================================================
    MainGui ();
    ~MainGui();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);

    // Binary resources:
    static const char* screenshot_png;
    static const int screenshot_pngSize;

    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    OscGroupEditor* component;
    OscGroupEditor* component2;
    OscGroupEditor* component3;
    OscGroupEditor* component4;
    Slider* stereoDepth;
    TextButton* oneOsc;
    TextButton* fiveOsc;
    TextButton* threeOsc;
    TextButton* textButton4;
    Slider* frequency;
    Slider* resonance;
    Slider* filterEffect;
    Slider* filterAttack;
    Slider* filterDecay;
    Slider* filterSustain;
    Slider* filterRelease;
    Label* label;
    Label* label2;
    Label* label3;
    Label* label4;
    Label* label5;
    Label* label6;
    Label* label7;
    Slider* volAttack;
    Slider* volDecay;
    Slider* volSustain;
    Slider* volRelease;
    Label* label9;
    Label* label10;
    Label* label11;
    Label* label12;
    Slider* masterVolume;
    Label* label13;
    Slider* panning;
    Label* label8;
    Label* label14;
    Label* label15;
    Label* label16;
    Label* label17;
    Label* label18;
    Label* label19;
    Label* label20;
    Image* internalCachedImage1;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    MainGui (const MainGui&);
    const MainGui& operator= (const MainGui&);
};


#endif   // __JUCER_HEADER_MAINGUI_MAINGUI_408B28EF__
