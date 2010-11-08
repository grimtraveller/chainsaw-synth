/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  8 Nov 2010 9:19:26pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "EditorGUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
EditorGUI::EditorGUI (ChainsawAudioProcessor* ownerFilter)
    : AudioProcessorEditor (ownerFilter),
      stereoSpread (0),
      label (0),
      label2 (0),
      detune (0),
      numOsc (0),
      numOsc2 (0),
      filterCutoff (0),
      label3 (0),
      filterCutoff2 (0),
      label4 (0),
      oscType1 (0),
      oscType2 (0),
      oscType3 (0),
      oscType4 (0),
      label5 (0),
      oscVolume1 (0),
      oscVolume2 (0),
      oscVolume3 (0),
      oscVolume4 (0),
      label6 (0),
      oscOctave1 (0),
      oscOctave2 (0),
      oscOctave3 (0),
      oscOctave4 (0)
{
    addAndMakeVisible (stereoSpread = new Slider (T("Stereo Spread")));
    stereoSpread->setRange (0, 1, 0);
    stereoSpread->setSliderStyle (Slider::LinearHorizontal);
    stereoSpread->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    stereoSpread->addListener (this);

    addAndMakeVisible (label = new Label (T("new label"),
                                          T("Stereo spread")));
    label->setFont (Font (15.0000f, Font::plain));
    label->setJustificationType (Justification::centredRight);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label2 = new Label (T("new label"),
                                           T("Detune")));
    label2->setFont (Font (15.0000f, Font::plain));
    label2->setJustificationType (Justification::centredRight);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (detune = new Slider (T("Detune")));
    detune->setRange (0, 1, 0);
    detune->setSliderStyle (Slider::LinearHorizontal);
    detune->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    detune->addListener (this);

    addAndMakeVisible (numOsc = new ComboBox (T("Number of Oscillators")));
    numOsc->setEditableText (false);
    numOsc->setJustificationType (Justification::centredLeft);
    numOsc->setTextWhenNothingSelected (String::empty);
    numOsc->setTextWhenNoChoicesAvailable (T("(no choices)"));
    numOsc->addItem (T("1"), 1);
    numOsc->addItem (T("3"), 2);
    numOsc->addItem (T("5"), 3);
    numOsc->addItem (T("7"), 4);
    numOsc->addListener (this);

    addAndMakeVisible (numOsc2 = new Label (T("new label"),
                                            T("Number of OSC")));
    numOsc2->setFont (Font (15.0000f, Font::plain));
    numOsc2->setJustificationType (Justification::centredRight);
    numOsc2->setEditable (false, false, false);
    numOsc2->setColour (TextEditor::textColourId, Colours::black);
    numOsc2->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (filterCutoff = new Slider (T("Filter Cutoff")));
    filterCutoff->setRange (0, 1, 0);
    filterCutoff->setSliderStyle (Slider::Rotary);
    filterCutoff->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    filterCutoff->addListener (this);

    addAndMakeVisible (label3 = new Label (T("new label"),
                                           T("Filter")));
    label3->setFont (Font (15.0000f, Font::plain));
    label3->setJustificationType (Justification::centredRight);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (filterCutoff2 = new Slider (T("Filter Cutoff")));
    filterCutoff2->setRange (0, 1, 0);
    filterCutoff2->setSliderStyle (Slider::Rotary);
    filterCutoff2->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    filterCutoff2->addListener (this);

    addAndMakeVisible (label4 = new Label (T("new label"),
                                           T("OSC Type")));
    label4->setFont (Font (15.0000f, Font::plain));
    label4->setJustificationType (Justification::centredRight);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (oscType1 = new TextButton (T("OSC Type")));
    oscType1->setButtonText (T("Sine"));
    oscType1->addButtonListener (this);

    addAndMakeVisible (oscType2 = new TextButton (T("OSC Type")));
    oscType2->setButtonText (T("Sine"));
    oscType2->addButtonListener (this);

    addAndMakeVisible (oscType3 = new TextButton (T("OSC Type")));
    oscType3->setButtonText (T("Sine"));
    oscType3->addButtonListener (this);

    addAndMakeVisible (oscType4 = new TextButton (T("OSC Type")));
    oscType4->setButtonText (T("Sine"));
    oscType4->addButtonListener (this);

    addAndMakeVisible (label5 = new Label (T("new label"),
                                           T("OSC Volume")));
    label5->setFont (Font (15.0000f, Font::plain));
    label5->setJustificationType (Justification::centredRight);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (oscVolume1 = new Slider (T("OSC Volume")));
    oscVolume1->setRange (0, 1, 0);
    oscVolume1->setSliderStyle (Slider::Rotary);
    oscVolume1->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    oscVolume1->addListener (this);

    addAndMakeVisible (oscVolume2 = new Slider (T("OSC Volume")));
    oscVolume2->setRange (0, 1, 0);
    oscVolume2->setSliderStyle (Slider::Rotary);
    oscVolume2->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    oscVolume2->addListener (this);

    addAndMakeVisible (oscVolume3 = new Slider (T("OSC Volume")));
    oscVolume3->setRange (0, 1, 0);
    oscVolume3->setSliderStyle (Slider::Rotary);
    oscVolume3->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    oscVolume3->addListener (this);

    addAndMakeVisible (oscVolume4 = new Slider (T("OSC Volume")));
    oscVolume4->setRange (0, 1, 0);
    oscVolume4->setSliderStyle (Slider::Rotary);
    oscVolume4->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    oscVolume4->addListener (this);

    addAndMakeVisible (label6 = new Label (T("new label"),
                                           T("OSC Octave")));
    label6->setFont (Font (15.0000f, Font::plain));
    label6->setJustificationType (Justification::centredRight);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (oscOctave1 = new Slider (T("OSC Octave")));
    oscOctave1->setRange (-5, 5, 1);
    oscOctave1->setSliderStyle (Slider::Rotary);
    oscOctave1->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    oscOctave1->addListener (this);

    addAndMakeVisible (oscOctave2 = new Slider (T("OSC Octave")));
    oscOctave2->setRange (-5, 5, 1);
    oscOctave2->setSliderStyle (Slider::Rotary);
    oscOctave2->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    oscOctave2->addListener (this);

    addAndMakeVisible (oscOctave3 = new Slider (T("OSC Octave")));
    oscOctave3->setRange (-5, 5, 1);
    oscOctave3->setSliderStyle (Slider::Rotary);
    oscOctave3->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    oscOctave3->addListener (this);

    addAndMakeVisible (oscOctave4 = new Slider (T("OSC Octave")));
    oscOctave4->setRange (-5, 5, 1);
    oscOctave4->setSliderStyle (Slider::Rotary);
    oscOctave4->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    oscOctave4->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (335, 265);

    //[Constructor] You can add your own custom stuff here..
    OscTypes[0] = "Saw";
    OscTypes[1] = "Sin";
    OscTypes[2] = "Sqr";
    OscTypes[3] = "Tri";
    OscType[0] = 0;
    OscType[1] = 0;
    OscType[2] = 0;
    OscType[3] = 0;
    //[/Constructor]
}

EditorGUI::~EditorGUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (stereoSpread);
    deleteAndZero (label);
    deleteAndZero (label2);
    deleteAndZero (detune);
    deleteAndZero (numOsc);
    deleteAndZero (numOsc2);
    deleteAndZero (filterCutoff);
    deleteAndZero (label3);
    deleteAndZero (filterCutoff2);
    deleteAndZero (label4);
    deleteAndZero (oscType1);
    deleteAndZero (oscType2);
    deleteAndZero (oscType3);
    deleteAndZero (oscType4);
    deleteAndZero (label5);
    deleteAndZero (oscVolume1);
    deleteAndZero (oscVolume2);
    deleteAndZero (oscVolume3);
    deleteAndZero (oscVolume4);
    deleteAndZero (label6);
    deleteAndZero (oscOctave1);
    deleteAndZero (oscOctave2);
    deleteAndZero (oscOctave3);
    deleteAndZero (oscOctave4);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void EditorGUI::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void EditorGUI::resized()
{
    stereoSpread->setBounds (128, 16, 192, 24);
    label->setBounds (8, 16, 112, 24);
    label2->setBounds (8, 48, 112, 24);
    detune->setBounds (128, 48, 192, 24);
    numOsc->setBounds (136, 80, 72, 24);
    numOsc2->setBounds (8, 80, 112, 24);
    filterCutoff->setBounds (256, 80, 31, 24);
    label3->setBounds (208, 80, 48, 24);
    filterCutoff2->setBounds (288, 80, 31, 24);
    label4->setBounds (-32, 136, 150, 24);
    oscType1->setBounds (128, 136, 40, 24);
    oscType2->setBounds (176, 136, 40, 24);
    oscType3->setBounds (224, 136, 40, 24);
    oscType4->setBounds (272, 136, 40, 24);
    label5->setBounds (-32, 176, 150, 24);
    oscVolume1->setBounds (128, 168, 40, 40);
    oscVolume2->setBounds (176, 168, 40, 40);
    oscVolume3->setBounds (224, 168, 40, 40);
    oscVolume4->setBounds (272, 168, 40, 40);
    label6->setBounds (-32, 224, 150, 24);
    oscOctave1->setBounds (128, 216, 40, 40);
    oscOctave2->setBounds (176, 216, 40, 40);
    oscOctave3->setBounds (224, 216, 40, 40);
    oscOctave4->setBounds (272, 216, 40, 40);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void EditorGUI::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == stereoSpread)
    {
        //[UserSliderCode_stereoSpread] -- add your slider handling code here..
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::STEREO_SPREAD, (float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_stereoSpread]
    }
    else if (sliderThatWasMoved == detune)
    {
        //[UserSliderCode_detune] -- add your slider handling code here..
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::DETUNE, (float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_detune]
    }
    else if (sliderThatWasMoved == filterCutoff)
    {
        //[UserSliderCode_filterCutoff] -- add your slider handling code here..
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::FILTER_CUTOFF, (float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_filterCutoff]
    }
    else if (sliderThatWasMoved == filterCutoff2)
    {
        //[UserSliderCode_filterCutoff2] -- add your slider handling code here..
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::FILTER_RESONANCE, (float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_filterCutoff2]
    }
    else if (sliderThatWasMoved == oscVolume1)
    {
        //[UserSliderCode_oscVolume1] -- add your slider handling code here..
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::OSC1_VOLUME, (float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_oscVolume1]
    }
    else if (sliderThatWasMoved == oscVolume2)
    {
        //[UserSliderCode_oscVolume2] -- add your slider handling code here..
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::OSC2_VOLUME, (float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_oscVolume2]
    }
    else if (sliderThatWasMoved == oscVolume3)
    {
        //[UserSliderCode_oscVolume3] -- add your slider handling code here..
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::OSC3_VOLUME, (float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_oscVolume3]
    }
    else if (sliderThatWasMoved == oscVolume4)
    {
        //[UserSliderCode_oscVolume4] -- add your slider handling code here..
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::OSC4_VOLUME, (float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_oscVolume4]
    }
    else if (sliderThatWasMoved == oscOctave1)
    {
        //[UserSliderCode_oscOctave1] -- add your slider handling code here..
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::OSC1_OCTAVE, (float) (sliderThatWasMoved->getValue() + 5 / 10));
        //[/UserSliderCode_oscOctave1]
    }
    else if (sliderThatWasMoved == oscOctave2)
    {
        //[UserSliderCode_oscOctave2] -- add your slider handling code here..
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::OSC2_OCTAVE, (float) (sliderThatWasMoved->getValue() + 5 / 10));
        //[/UserSliderCode_oscOctave2]
    }
    else if (sliderThatWasMoved == oscOctave3)
    {
        //[UserSliderCode_oscOctave3] -- add your slider handling code here..
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::OSC3_OCTAVE, (float) (sliderThatWasMoved->getValue() + 5 / 10));
        //[/UserSliderCode_oscOctave3]
    }
    else if (sliderThatWasMoved == oscOctave4)
    {
        //[UserSliderCode_oscOctave4] -- add your slider handling code here..
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::OSC4_OCTAVE, (float) (sliderThatWasMoved->getValue() + 5 / 10));
        //[/UserSliderCode_oscOctave4]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void EditorGUI::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == numOsc)
    {
        //[UserComboBoxCode_numOsc] -- add your combo box handling code here..
    	int x = comboBoxThatHasChanged->getSelectedId();
    	int v;
    	switch(x){
			case 0: v = 1; break;
			case 1: v = 3; break;
			case 2: v = 5; break;
			case 3: v = 7; break;
    	}
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::NUM_OSCILLATORS, (float) (v / 7));
        //[/UserComboBoxCode_numOsc]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void EditorGUI::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == oscType1)
    {
        //[UserButtonCode_oscType1] -- add your button handler code here..
    	buttonThatWasClicked->setButtonText(OscTypes[OscType[0] = (OscType[0] + 1) % 4]);
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::OSC1_TYPE, (float)OscType[0] / 3);
        //[/UserButtonCode_oscType1]
    }
    else if (buttonThatWasClicked == oscType2)
    {
        //[UserButtonCode_oscType2] -- add your button handler code here..
    	buttonThatWasClicked->setButtonText(OscTypes[OscType[1] = (OscType[1] + 1) % 4]);
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::OSC2_TYPE, (float)OscType[1] / 3);
        //[/UserButtonCode_oscType2]
    }
    else if (buttonThatWasClicked == oscType3)
    {
        //[UserButtonCode_oscType3] -- add your button handler code here..
    	buttonThatWasClicked->setButtonText(OscTypes[OscType[1] = (OscType[1] + 1) % 4]);
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::OSC3_TYPE, (float)OscType[2] / 3);
        //[/UserButtonCode_oscType3]
    }
    else if (buttonThatWasClicked == oscType4)
    {
        //[UserButtonCode_oscType4] -- add your button handler code here..
    	buttonThatWasClicked->setButtonText(OscTypes[OscType[1] = (OscType[1] + 1) % 4]);
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::OSC4_TYPE, (float)OscType[3] / 3);
        //[/UserButtonCode_oscType4]
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

<JUCER_COMPONENT documentType="Component" className="EditorGUI" componentName=""
                 parentClasses="public AudioProcessorEditor" constructorParams="ChainsawAudioProcessor* ownerFilter"
                 variableInitialisers="AudioProcessorEditor (ownerFilter)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330000013" fixedSize="1"
                 initialWidth="335" initialHeight="265">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="Stereo Spread" id="69472c705df3ed25" memberName="stereoSpread"
          virtualName="" explicitFocusOrder="0" pos="128 16 192 24" min="0"
          max="1" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="34ba56f840cf0e12" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="8 16 112 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Stereo spread" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <LABEL name="new label" id="d5efe8ba34ee323a" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="8 48 112 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Detune" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="34"/>
  <SLIDER name="Detune" id="1e360cfb97913237" memberName="detune" virtualName=""
          explicitFocusOrder="0" pos="128 48 192 24" min="0" max="1" int="0"
          style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="Number of Oscillators" id="57b8fbc3d0a3cd79" memberName="numOsc"
            virtualName="" explicitFocusOrder="0" pos="136 80 72 24" editable="0"
            layout="33" items="1&#10;3&#10;5&#10;7" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="c67abeaa9e0ad8e1" memberName="numOsc2" virtualName=""
         explicitFocusOrder="0" pos="8 80 112 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Number of OSC" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <SLIDER name="Filter Cutoff" id="2728b5fbe3458993" memberName="filterCutoff"
          virtualName="" explicitFocusOrder="0" pos="256 80 31 24" min="0"
          max="1" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="2edf594c331ed0f9" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="208 80 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Filter" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="34"/>
  <SLIDER name="Filter Cutoff" id="53239bf0db7742e1" memberName="filterCutoff2"
          virtualName="" explicitFocusOrder="0" pos="288 80 31 24" min="0"
          max="1" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="c47f6dfc453c30cb" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="-32 136 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="OSC Type" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="34"/>
  <TEXTBUTTON name="OSC Type" id="6b1cdb1dd01fd63b" memberName="oscType1" virtualName=""
              explicitFocusOrder="0" pos="128 136 40 24" buttonText="Sine"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="OSC Type" id="628b5d03ff358b3" memberName="oscType2" virtualName=""
              explicitFocusOrder="0" pos="176 136 40 24" buttonText="Sine"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="OSC Type" id="f971fad504bffd18" memberName="oscType3" virtualName=""
              explicitFocusOrder="0" pos="224 136 40 24" buttonText="Sine"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="OSC Type" id="42648633940726e1" memberName="oscType4" virtualName=""
              explicitFocusOrder="0" pos="272 136 40 24" buttonText="Sine"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="8912b59e10343f54" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="-32 176 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="OSC Volume" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="34"/>
  <SLIDER name="OSC Volume" id="4d7c5223d9c58117" memberName="oscVolume1"
          virtualName="" explicitFocusOrder="0" pos="128 168 40 40" min="0"
          max="1" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="OSC Volume" id="3c73ab2abe7209ea" memberName="oscVolume2"
          virtualName="" explicitFocusOrder="0" pos="176 168 40 40" min="0"
          max="1" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="OSC Volume" id="2707830e44f89ba8" memberName="oscVolume3"
          virtualName="" explicitFocusOrder="0" pos="224 168 40 40" min="0"
          max="1" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="OSC Volume" id="c6a0252ba90fecce" memberName="oscVolume4"
          virtualName="" explicitFocusOrder="0" pos="272 168 40 40" min="0"
          max="1" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="7c4c75875acfb049" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="-32 224 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="OSC Octave" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="34"/>
  <SLIDER name="OSC Octave" id="98b876c58e07b658" memberName="oscOctave1"
          virtualName="" explicitFocusOrder="0" pos="128 216 40 40" min="-5"
          max="5" int="1" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="OSC Octave" id="1f363711a0525bc4" memberName="oscOctave2"
          virtualName="" explicitFocusOrder="0" pos="176 216 40 40" min="-5"
          max="5" int="1" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="OSC Octave" id="5b54b51848c70528" memberName="oscOctave3"
          virtualName="" explicitFocusOrder="0" pos="224 216 40 40" min="-5"
          max="5" int="1" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="OSC Octave" id="fc8d4b9cdbe871b3" memberName="oscOctave4"
          virtualName="" explicitFocusOrder="0" pos="272 216 40 40" min="-5"
          max="5" int="1" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
