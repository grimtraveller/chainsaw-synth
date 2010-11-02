/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  24 May 2009 2:50:02 pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.11

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_OSCGROUPEDITOR_OSCGROUPEDITOR_F2A77112__
#define __JUCER_HEADER_OSCGROUPEDITOR_OSCGROUPEDITOR_F2A77112__

//[Headers]     -- You can add your own extra header files here --
#include <juce/juce_amalgamated.h>
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class OscGroupEditor  : public Component,
                        public ComboBoxListener,
                        public SliderListener,
                        public ButtonListener
{
public:
    //==============================================================================
    OscGroupEditor ();
    ~OscGroupEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);


    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ComboBox* oscType;
    Slider* volume;
    Slider* octave;
    TextButton* analog;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    OscGroupEditor (const OscGroupEditor&);
    const OscGroupEditor& operator= (const OscGroupEditor&);
};


#endif   // __JUCER_HEADER_OSCGROUPEDITOR_OSCGROUPEDITOR_F2A77112__
