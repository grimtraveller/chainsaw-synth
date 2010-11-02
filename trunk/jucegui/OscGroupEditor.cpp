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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "OscGroupEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
OscGroupEditor::OscGroupEditor ()
    : Component (T("OscGroupEditor")),
      oscType (0),
      volume (0),
      octave (0),
      analog (0)
{
    addAndMakeVisible (oscType = new ComboBox (T("Oscillator type")));
    oscType->setTooltip (T("Oscillator type"));
    oscType->setEditableText (false);
    oscType->setJustificationType (Justification::centredLeft);
    oscType->setTextWhenNothingSelected (String::empty);
    oscType->setTextWhenNoChoicesAvailable (T("(no choices)"));
    oscType->addItem (T("Sine"), 1);
    oscType->addItem (T("Sawtooth"), 2);
    oscType->addItem (T("Square"), 3);
    oscType->addItem (T("Triangle"), 4);
    oscType->addListener (this);

    addAndMakeVisible (volume = new Slider (T("Volume")));
    volume->setTooltip (T("Oscillator volume"));
    volume->setRange (0, 1, 0.01);
    volume->setSliderStyle (Slider::Rotary);
    volume->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    volume->setColour (Slider::rotarySliderFillColourId, Colour (0x7fffffff));
    volume->addListener (this);

    addAndMakeVisible (octave = new Slider (T("Octave")));
    octave->setTooltip (T("Octave"));
    octave->setRange (-5, 5, 1);
    octave->setSliderStyle (Slider::Rotary);
    octave->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    octave->setColour (Slider::thumbColourId, Colours::white);
    octave->setColour (Slider::rotarySliderFillColourId, Colour (0x7fffffff));
    octave->addListener (this);

    addAndMakeVisible (analog = new TextButton (T("Analog")));
    analog->setTooltip (T("Enable analog OSC"));
    analog->setButtonText (T("A"));
    analog->addButtonListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (200, 24);

    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

OscGroupEditor::~OscGroupEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (oscType);
    deleteAndZero (volume);
    deleteAndZero (octave);
    deleteAndZero (analog);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void OscGroupEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void OscGroupEditor::resized()
{
    oscType->setBounds (0, 0, 128, 24);
    volume->setBounds (128, 0, 24, 24);
    octave->setBounds (152, 0, 24, 24);
    analog->setBounds (176, 0, 23, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void OscGroupEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == oscType)
    {
        //[UserComboBoxCode_oscType] -- add your combo box handling code here..
        //[/UserComboBoxCode_oscType]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void OscGroupEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == volume)
    {
        //[UserSliderCode_volume] -- add your slider handling code here..
        //[/UserSliderCode_volume]
    }
    else if (sliderThatWasMoved == octave)
    {
        //[UserSliderCode_octave] -- add your slider handling code here..
        //[/UserSliderCode_octave]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void OscGroupEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == analog)
    {
        //[UserButtonCode_analog] -- add your button handler code here..
        //[/UserButtonCode_analog]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="OscGroupEditor" componentName="OscGroupEditor"
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="1" initialWidth="200" initialHeight="24">
  <BACKGROUND backgroundColour="ffffff"/>
  <COMBOBOX name="Oscillator type" id="95ba68e7f09dce01" memberName="oscType"
            virtualName="" explicitFocusOrder="0" pos="0 0 128 24" tooltip="Oscillator type"
            editable="0" layout="33" items="Sine&#10;Sawtooth&#10;Square&#10;Triangle"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="Volume" id="548d11eff6abc2e6" memberName="volume" virtualName=""
          explicitFocusOrder="0" pos="128 0 24 24" tooltip="Oscillator volume"
          rotarysliderfill="7fffffff" min="0" max="1" int="0.01" style="Rotary"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Octave" id="4f0d0120fce6710c" memberName="octave" virtualName=""
          explicitFocusOrder="0" pos="152 0 24 24" tooltip="Octave" thumbcol="ffffffff"
          rotarysliderfill="7fffffff" min="-5" max="5" int="1" style="Rotary"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="Analog" id="518620f3a08c102c" memberName="analog" virtualName=""
              explicitFocusOrder="0" pos="176 0 23 24" tooltip="Enable analog OSC"
              buttonText="A" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
