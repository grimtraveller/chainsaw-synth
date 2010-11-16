/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  15 Nov 2010 10:20:34pm

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
      oscOctave4 (0),
      volADSR (0),
      volumeAttack (0),
      volumeDecay (0),
      volumeSustain (0),
      volumeRelease (0),
      filterAttack (0),
      filterDecay (0),
      filterSustain (0),
      filterRelease (0),
      filterADSREffect (0),
      filterADSR (0),
      cachedImage_chainsawbg_png (0)
{
    addAndMakeVisible (stereoSpread = new Slider (T("Stereo Spread")));
    stereoSpread->setTooltip (T("Stereo Spread"));
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
    detune->setTooltip (T("Detune"));
    detune->setRange (0, 1, 0);
    detune->setSliderStyle (Slider::LinearHorizontal);
    detune->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    detune->addListener (this);

    addAndMakeVisible (numOsc = new ComboBox (T("Number of Oscillators")));
    numOsc->setTooltip (T("Number of Oscillators"));
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
    filterCutoff->setTooltip (T("Filter Cutoff"));
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

    addAndMakeVisible (filterCutoff2 = new Slider (T("Filter Resonance")));
    filterCutoff2->setTooltip (T("Filter Resonance"));
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
    oscType1->setTooltip (T("OSC1 Type"));
    oscType1->setButtonText (T("Saw"));
    oscType1->addButtonListener (this);

    addAndMakeVisible (oscType2 = new TextButton (T("OSC Type")));
    oscType2->setTooltip (T("OSC2 Type"));
    oscType2->setButtonText (T("Saw"));
    oscType2->addButtonListener (this);

    addAndMakeVisible (oscType3 = new TextButton (T("OSC Type")));
    oscType3->setTooltip (T("OSC3 Type"));
    oscType3->setButtonText (T("Saw"));
    oscType3->addButtonListener (this);

    addAndMakeVisible (oscType4 = new TextButton (T("OSC Type")));
    oscType4->setTooltip (T("OSC4 Type"));
    oscType4->setButtonText (T("Saw"));
    oscType4->addButtonListener (this);

    addAndMakeVisible (label5 = new Label (T("new label"),
                                           T("OSC Volume")));
    label5->setFont (Font (15.0000f, Font::plain));
    label5->setJustificationType (Justification::centredRight);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (oscVolume1 = new Slider (T("OSC Volume")));
    oscVolume1->setTooltip (T("OSC1 Volume"));
    oscVolume1->setRange (0, 1, 0);
    oscVolume1->setSliderStyle (Slider::Rotary);
    oscVolume1->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    oscVolume1->addListener (this);

    addAndMakeVisible (oscVolume2 = new Slider (T("OSC Volume")));
    oscVolume2->setTooltip (T("OSC2 Volume"));
    oscVolume2->setRange (0, 1, 0);
    oscVolume2->setSliderStyle (Slider::Rotary);
    oscVolume2->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    oscVolume2->addListener (this);

    addAndMakeVisible (oscVolume3 = new Slider (T("OSC Volume")));
    oscVolume3->setTooltip (T("OSC3 Volume"));
    oscVolume3->setRange (0, 1, 0);
    oscVolume3->setSliderStyle (Slider::Rotary);
    oscVolume3->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    oscVolume3->addListener (this);

    addAndMakeVisible (oscVolume4 = new Slider (T("OSC Volume")));
    oscVolume4->setTooltip (T("OSC4 Volume"));
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
    oscOctave1->setTooltip (T("OSC1 Octave"));
    oscOctave1->setRange (-5, 5, 1);
    oscOctave1->setSliderStyle (Slider::Rotary);
    oscOctave1->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    oscOctave1->addListener (this);

    addAndMakeVisible (oscOctave2 = new Slider (T("OSC Octave")));
    oscOctave2->setTooltip (T("OSC2 Octave"));
    oscOctave2->setRange (-5, 5, 1);
    oscOctave2->setSliderStyle (Slider::Rotary);
    oscOctave2->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    oscOctave2->addListener (this);

    addAndMakeVisible (oscOctave3 = new Slider (T("OSC Octave")));
    oscOctave3->setTooltip (T("OSC3 Octave"));
    oscOctave3->setRange (-5, 5, 1);
    oscOctave3->setSliderStyle (Slider::Rotary);
    oscOctave3->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    oscOctave3->addListener (this);

    addAndMakeVisible (oscOctave4 = new Slider (T("OSC Octave")));
    oscOctave4->setTooltip (T("OSC4 Octave"));
    oscOctave4->setRange (-5, 5, 1);
    oscOctave4->setSliderStyle (Slider::Rotary);
    oscOctave4->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    oscOctave4->addListener (this);

    addAndMakeVisible (volADSR = new Label (T("VolumeADSR"),
                                            T("Volume ADSR")));
    volADSR->setFont (Font (15.0000f, Font::plain));
    volADSR->setJustificationType (Justification::centredRight);
    volADSR->setEditable (false, false, false);
    volADSR->setColour (TextEditor::textColourId, Colours::black);
    volADSR->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (volumeAttack = new Slider (T("Volume Attack")));
    volumeAttack->setTooltip (T("Volume Attack"));
    volumeAttack->setRange (0, 1, 0);
    volumeAttack->setSliderStyle (Slider::Rotary);
    volumeAttack->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    volumeAttack->addListener (this);

    addAndMakeVisible (volumeDecay = new Slider (T("Volume Decay")));
    volumeDecay->setTooltip (T("Volume Decay"));
    volumeDecay->setRange (0, 1, 0);
    volumeDecay->setSliderStyle (Slider::Rotary);
    volumeDecay->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    volumeDecay->addListener (this);

    addAndMakeVisible (volumeSustain = new Slider (T("Volume Sustain")));
    volumeSustain->setTooltip (T("Volume Sustain"));
    volumeSustain->setRange (0, 1, 0);
    volumeSustain->setSliderStyle (Slider::Rotary);
    volumeSustain->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    volumeSustain->addListener (this);

    addAndMakeVisible (volumeRelease = new Slider (T("Volume Release")));
    volumeRelease->setTooltip (T("Volume Release"));
    volumeRelease->setRange (0, 1, 0);
    volumeRelease->setSliderStyle (Slider::Rotary);
    volumeRelease->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    volumeRelease->addListener (this);

    addAndMakeVisible (filterAttack = new Slider (T("Filter Attack")));
    filterAttack->setTooltip (T("Filter Attack"));
    filterAttack->setRange (0, 1, 0);
    filterAttack->setSliderStyle (Slider::Rotary);
    filterAttack->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    filterAttack->addListener (this);

    addAndMakeVisible (filterDecay = new Slider (T("Filter Decay")));
    filterDecay->setTooltip (T("Filter Decay"));
    filterDecay->setRange (0, 1, 0);
    filterDecay->setSliderStyle (Slider::Rotary);
    filterDecay->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    filterDecay->addListener (this);

    addAndMakeVisible (filterSustain = new Slider (T("Filter Sustain")));
    filterSustain->setTooltip (T("Filter Sustain"));
    filterSustain->setRange (0, 1, 0);
    filterSustain->setSliderStyle (Slider::Rotary);
    filterSustain->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    filterSustain->addListener (this);

    addAndMakeVisible (filterRelease = new Slider (T("Filter Release")));
    filterRelease->setTooltip (T("Filter Release"));
    filterRelease->setRange (0, 1, 0);
    filterRelease->setSliderStyle (Slider::Rotary);
    filterRelease->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    filterRelease->addListener (this);

    addAndMakeVisible (filterADSREffect = new Slider (T("Filter ADSR Effect")));
    filterADSREffect->setTooltip (T("Filter ADSR Effect"));
    filterADSREffect->setRange (-1, 1, 0);
    filterADSREffect->setSliderStyle (Slider::Rotary);
    filterADSREffect->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    filterADSREffect->addListener (this);

    addAndMakeVisible (filterADSR = new Label (T("Filter ADSR"),
                                               T("Filter ADSR")));
    filterADSR->setFont (Font (15.0000f, Font::plain));
    filterADSR->setJustificationType (Justification::centredRight);
    filterADSR->setEditable (false, false, false);
    filterADSR->setColour (TextEditor::textColourId, Colours::black);
    filterADSR->setColour (TextEditor::backgroundColourId, Colour (0x0));

    cachedImage_chainsawbg_png = ImageCache::getFromMemory (chainsawbg_png, chainsawbg_pngSize);

    //[UserPreSize]
    numOsc->setSelectedItemIndex(0, true);
    volumeSustain->setValue(1,false,false);
    oscVolume1->setValue(1,false,false);
    oscVolume2->setValue(1,false,false);
    oscVolume3->setValue(1,false,false);
    oscVolume4->setValue(1,false,false);
    filterCutoff->setValue(1,false,false);
    //[/UserPreSize]

    setSize (335, 420);

    //[Constructor] You can add your own custom stuff here..
    OscTypes[0] = "Saw";
    OscTypes[1] = "Sin";
    OscTypes[2] = "Sqr";
    OscTypes[3] = "Tri";
    OscType[0] = 0;
    OscType[1] = 0;
    OscType[2] = 0;
    OscType[3] = 0;

    // Base parameters
    detune->setValue(ownerFilter->p.vp.detune, false, false);
    stereoSpread->setValue(ownerFilter->p.vp.stereoSpread, false, false);
    numOsc->setSelectedItemIndex((ownerFilter->p.vp.numosc - 1) / 2, false);

    volumeAttack->setValue(ownerFilter->p.vp.volAttack, false, false);
    volumeDecay->setValue(ownerFilter->p.vp.volDecay, false, false);
    volumeSustain->setValue(ownerFilter->p.vp.volSustain, false, false);
    volumeRelease->setValue(ownerFilter->p.vp.volRelease, false, false);

    filterCutoff->setValue(ownerFilter->p.vp.filterCutoff, false, false);
    filterCutoff2->setValue(ownerFilter->p.vp.filterResonance, false, false);
    filterADSREffect->setValue(ownerFilter->p.vp.filterADSREffect, false, false);

    filterAttack->setValue(ownerFilter->p.vp.filterAttack, false, false);
    filterDecay->setValue(ownerFilter->p.vp.filterDecay, false, false);
    filterSustain->setValue(ownerFilter->p.vp.filterSustain, false, false);
    filterRelease->setValue(ownerFilter->p.vp.filterRelease, false, false);

    oscVolume1->setValue(ownerFilter->p.vp.g[0].vol, false, false);
    oscVolume2->setValue(ownerFilter->p.vp.g[1].vol, false, false);
    oscVolume3->setValue(ownerFilter->p.vp.g[2].vol, false, false);
    oscVolume4->setValue(ownerFilter->p.vp.g[3].vol, false, false);

    oscType1->setButtonText(OscTypes[ownerFilter->p.vp.g[0].type]);
	oscType2->setButtonText(OscTypes[ownerFilter->p.vp.g[1].type]);
	oscType3->setButtonText(OscTypes[ownerFilter->p.vp.g[2].type]);
	oscType4->setButtonText(OscTypes[ownerFilter->p.vp.g[3].type]);

	oscOctave1->setValue(ownerFilter->p.vp.g[0].octave, false, false);
	oscOctave2->setValue(ownerFilter->p.vp.g[1].octave, false, false);
	oscOctave3->setValue(ownerFilter->p.vp.g[2].octave, false, false);
	oscOctave4->setValue(ownerFilter->p.vp.g[3].octave, false, false);

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
    deleteAndZero (volADSR);
    deleteAndZero (volumeAttack);
    deleteAndZero (volumeDecay);
    deleteAndZero (volumeSustain);
    deleteAndZero (volumeRelease);
    deleteAndZero (filterAttack);
    deleteAndZero (filterDecay);
    deleteAndZero (filterSustain);
    deleteAndZero (filterRelease);
    deleteAndZero (filterADSREffect);
    deleteAndZero (filterADSR);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void EditorGUI::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setColour (Colours::black);
    g.drawImage (cachedImage_chainsawbg_png,
                 0, 0, 335, 420,
                 0, 0, cachedImage_chainsawbg_png.getWidth(), cachedImage_chainsawbg_png.getHeight());

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void EditorGUI::resized()
{
    stereoSpread->setBounds (132, 84, 192, 24);
    label->setBounds (12, 84, 112, 24);
    label2->setBounds (12, 116, 112, 24);
    detune->setBounds (132, 116, 192, 24);
    numOsc->setBounds (140, 148, 56, 24);
    numOsc2->setBounds (12, 148, 112, 24);
    filterCutoff->setBounds (244, 148, 31, 24);
    label3->setBounds (196, 148, 48, 24);
    filterCutoff2->setBounds (268, 148, 31, 24);
    label4->setBounds (-29, 294, 150, 24);
    oscType1->setBounds (131, 294, 40, 24);
    oscType2->setBounds (179, 294, 40, 24);
    oscType3->setBounds (227, 294, 40, 24);
    oscType4->setBounds (275, 294, 40, 24);
    label5->setBounds (-29, 334, 150, 24);
    oscVolume1->setBounds (131, 326, 40, 40);
    oscVolume2->setBounds (179, 326, 40, 40);
    oscVolume3->setBounds (227, 326, 40, 40);
    oscVolume4->setBounds (275, 326, 40, 40);
    label6->setBounds (-29, 374, 150, 24);
    oscOctave1->setBounds (131, 366, 40, 40);
    oscOctave2->setBounds (179, 366, 40, 40);
    oscOctave3->setBounds (227, 366, 40, 40);
    oscOctave4->setBounds (275, 366, 40, 40);
    volADSR->setBounds (12, 196, 112, 24);
    volumeAttack->setBounds (132, 188, 40, 40);
    volumeDecay->setBounds (180, 188, 40, 40);
    volumeSustain->setBounds (228, 188, 40, 40);
    volumeRelease->setBounds (276, 188, 40, 40);
    filterAttack->setBounds (132, 228, 40, 40);
    filterDecay->setBounds (180, 228, 40, 40);
    filterSustain->setBounds (228, 228, 40, 40);
    filterRelease->setBounds (276, 228, 40, 40);
    filterADSREffect->setBounds (292, 148, 31, 24);
    filterADSR->setBounds (12, 236, 112, 24);
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
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::OSC1_OCTAVE, (float) (sliderThatWasMoved->getValue() + 5) / 10.0f);
        //[/UserSliderCode_oscOctave1]
    }
    else if (sliderThatWasMoved == oscOctave2)
    {
        //[UserSliderCode_oscOctave2] -- add your slider handling code here..
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::OSC2_OCTAVE, (float) (sliderThatWasMoved->getValue() + 5) / 10.0f);
        //[/UserSliderCode_oscOctave2]
    }
    else if (sliderThatWasMoved == oscOctave3)
    {
        //[UserSliderCode_oscOctave3] -- add your slider handling code here..
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::OSC3_OCTAVE, (float) (sliderThatWasMoved->getValue() + 5) / 10.0f);
        //[/UserSliderCode_oscOctave3]
    }
    else if (sliderThatWasMoved == oscOctave4)
    {
        //[UserSliderCode_oscOctave4] -- add your slider handling code here..
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::OSC4_OCTAVE, (float) (sliderThatWasMoved->getValue() + 5) / 10.0f);
        //[/UserSliderCode_oscOctave4]
    }
    else if (sliderThatWasMoved == volumeAttack)
    {
        //[UserSliderCode_volumeAttack] -- add your slider handling code here..
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::VOL_ATTACK, (float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_volumeAttack]
    }
    else if (sliderThatWasMoved == volumeDecay)
    {
        //[UserSliderCode_volumeDecay] -- add your slider handling code here..
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::VOL_DECAY, (float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_volumeDecay]
    }
    else if (sliderThatWasMoved == volumeSustain)
    {
        //[UserSliderCode_volumeSustain] -- add your slider handling code here..
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::VOL_SUSTAIN, (float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_volumeSustain]
    }
    else if (sliderThatWasMoved == volumeRelease)
    {
        //[UserSliderCode_volumeRelease] -- add your slider handling code here..
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::VOL_RELEASE, (float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_volumeRelease]
    }
    else if (sliderThatWasMoved == filterAttack)
    {
        //[UserSliderCode_filterAttack] -- add your slider handling code here..
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::FILTER_ATTACK, (float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_filterAttack]
    }
    else if (sliderThatWasMoved == filterDecay)
    {
        //[UserSliderCode_filterDecay] -- add your slider handling code here..
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::FILTER_DECAY, (float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_filterDecay]
    }
    else if (sliderThatWasMoved == filterSustain)
    {
        //[UserSliderCode_filterSustain] -- add your slider handling code here..
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::FILTER_SUSTAIN, (float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_filterSustain]
    }
    else if (sliderThatWasMoved == filterRelease)
    {
        //[UserSliderCode_filterRelease] -- add your slider handling code here..
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::FILTER_RELEASE, (float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_filterRelease]
    }
    else if (sliderThatWasMoved == filterADSREffect)
    {
        //[UserSliderCode_filterADSREffect] -- add your slider handling code here..
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::FILTER_ADSR_EFFECT, (float)(sliderThatWasMoved->getValue() + 1) / 2.0f);
        //[/UserSliderCode_filterADSREffect]
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
			case 1: v = 1; break;
			case 2: v = 3; break;
			case 3: v = 5; break;
			case 4: v = 7; break;
    	}
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::NUM_OSCILLATORS, (float) (v / 7.0f));
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
    	buttonThatWasClicked->setButtonText(OscTypes[OscType[2] = (OscType[2] + 1) % 4]);
    	getProcessor()->setParameterNotifyingHost (ChainsawAudioProcessor::OSC3_TYPE, (float)OscType[2] / 3);
        //[/UserButtonCode_oscType3]
    }
    else if (buttonThatWasClicked == oscType4)
    {
        //[UserButtonCode_oscType4] -- add your button handler code here..
    	buttonThatWasClicked->setButtonText(OscTypes[OscType[3] = (OscType[3] + 1) % 4]);
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
                 initialWidth="335" initialHeight="420">
  <BACKGROUND backgroundColour="ffffffff">
    <IMAGE pos="0 0 335 420" resource="chainsawbg_png" opacity="1" mode="0"/>
  </BACKGROUND>
  <SLIDER name="Stereo Spread" id="69472c705df3ed25" memberName="stereoSpread"
          virtualName="" explicitFocusOrder="0" pos="132 84 192 24" tooltip="Stereo Spread"
          min="0" max="1" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="34ba56f840cf0e12" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="12 84 112 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Stereo spread" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <LABEL name="new label" id="d5efe8ba34ee323a" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="12 116 112 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Detune" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="34"/>
  <SLIDER name="Detune" id="1e360cfb97913237" memberName="detune" virtualName=""
          explicitFocusOrder="0" pos="132 116 192 24" tooltip="Detune"
          min="0" max="1" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="Number of Oscillators" id="57b8fbc3d0a3cd79" memberName="numOsc"
            virtualName="" explicitFocusOrder="0" pos="140 148 56 24" tooltip="Number of Oscillators"
            editable="0" layout="33" items="1&#10;3&#10;5&#10;7" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="c67abeaa9e0ad8e1" memberName="numOsc2" virtualName=""
         explicitFocusOrder="0" pos="12 148 112 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Number of OSC" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <SLIDER name="Filter Cutoff" id="2728b5fbe3458993" memberName="filterCutoff"
          virtualName="" explicitFocusOrder="0" pos="244 148 31 24" tooltip="Filter Cutoff"
          min="0" max="1" int="0" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="2edf594c331ed0f9" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="196 148 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Filter" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="34"/>
  <SLIDER name="Filter Resonance" id="53239bf0db7742e1" memberName="filterCutoff2"
          virtualName="" explicitFocusOrder="0" pos="268 148 31 24" tooltip="Filter Resonance"
          min="0" max="1" int="0" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="c47f6dfc453c30cb" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="-29 294 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="OSC Type" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="34"/>
  <TEXTBUTTON name="OSC Type" id="6b1cdb1dd01fd63b" memberName="oscType1" virtualName=""
              explicitFocusOrder="0" pos="131 294 40 24" tooltip="OSC1 Type"
              buttonText="Saw" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="OSC Type" id="628b5d03ff358b3" memberName="oscType2" virtualName=""
              explicitFocusOrder="0" pos="179 294 40 24" tooltip="OSC2 Type"
              buttonText="Saw" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="OSC Type" id="f971fad504bffd18" memberName="oscType3" virtualName=""
              explicitFocusOrder="0" pos="227 294 40 24" tooltip="OSC3 Type"
              buttonText="Saw" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="OSC Type" id="42648633940726e1" memberName="oscType4" virtualName=""
              explicitFocusOrder="0" pos="275 294 40 24" tooltip="OSC4 Type"
              buttonText="Saw" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="8912b59e10343f54" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="-29 334 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="OSC Volume" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="34"/>
  <SLIDER name="OSC Volume" id="4d7c5223d9c58117" memberName="oscVolume1"
          virtualName="" explicitFocusOrder="0" pos="131 326 40 40" tooltip="OSC1 Volume"
          min="0" max="1" int="0" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="OSC Volume" id="3c73ab2abe7209ea" memberName="oscVolume2"
          virtualName="" explicitFocusOrder="0" pos="179 326 40 40" tooltip="OSC2 Volume"
          min="0" max="1" int="0" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="OSC Volume" id="2707830e44f89ba8" memberName="oscVolume3"
          virtualName="" explicitFocusOrder="0" pos="227 326 40 40" tooltip="OSC3 Volume"
          min="0" max="1" int="0" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="OSC Volume" id="c6a0252ba90fecce" memberName="oscVolume4"
          virtualName="" explicitFocusOrder="0" pos="275 326 40 40" tooltip="OSC4 Volume"
          min="0" max="1" int="0" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="7c4c75875acfb049" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="-29 374 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="OSC Octave" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="34"/>
  <SLIDER name="OSC Octave" id="98b876c58e07b658" memberName="oscOctave1"
          virtualName="" explicitFocusOrder="0" pos="131 366 40 40" tooltip="OSC1 Octave"
          min="-5" max="5" int="1" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="OSC Octave" id="1f363711a0525bc4" memberName="oscOctave2"
          virtualName="" explicitFocusOrder="0" pos="179 366 40 40" tooltip="OSC2 Octave"
          min="-5" max="5" int="1" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="OSC Octave" id="5b54b51848c70528" memberName="oscOctave3"
          virtualName="" explicitFocusOrder="0" pos="227 366 40 40" tooltip="OSC3 Octave"
          min="-5" max="5" int="1" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="OSC Octave" id="fc8d4b9cdbe871b3" memberName="oscOctave4"
          virtualName="" explicitFocusOrder="0" pos="275 366 40 40" tooltip="OSC4 Octave"
          min="-5" max="5" int="1" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="VolumeADSR" id="6d7e4bcd97f6128" memberName="volADSR" virtualName=""
         explicitFocusOrder="0" pos="12 196 112 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Volume ADSR" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <SLIDER name="Volume Attack" id="408bb88faae2d2e3" memberName="volumeAttack"
          virtualName="" explicitFocusOrder="0" pos="132 188 40 40" tooltip="Volume Attack"
          min="0" max="1" int="0" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Volume Decay" id="4b4e4cc6d7121324" memberName="volumeDecay"
          virtualName="" explicitFocusOrder="0" pos="180 188 40 40" tooltip="Volume Decay"
          min="0" max="1" int="0" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Volume Sustain" id="70c9f30acf312f76" memberName="volumeSustain"
          virtualName="" explicitFocusOrder="0" pos="228 188 40 40" tooltip="Volume Sustain"
          min="0" max="1" int="0" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Volume Release" id="22843a492db23929" memberName="volumeRelease"
          virtualName="" explicitFocusOrder="0" pos="276 188 40 40" tooltip="Volume Release"
          min="0" max="1" int="0" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Filter Attack" id="f2089171cb77d0a4" memberName="filterAttack"
          virtualName="" explicitFocusOrder="0" pos="132 228 40 40" tooltip="Filter Attack"
          min="0" max="1" int="0" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Filter Decay" id="e439c23898120d21" memberName="filterDecay"
          virtualName="" explicitFocusOrder="0" pos="180 228 40 40" tooltip="Filter Decay"
          min="0" max="1" int="0" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Filter Sustain" id="fea6a36785a4309a" memberName="filterSustain"
          virtualName="" explicitFocusOrder="0" pos="228 228 40 40" tooltip="Filter Sustain"
          min="0" max="1" int="0" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Filter Release" id="8b87c55322d99a7e" memberName="filterRelease"
          virtualName="" explicitFocusOrder="0" pos="276 228 40 40" tooltip="Filter Release"
          min="0" max="1" int="0" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Filter ADSR Effect" id="84494311c8eff98c" memberName="filterADSREffect"
          virtualName="" explicitFocusOrder="0" pos="292 148 31 24" tooltip="Filter ADSR Effect"
          min="-1" max="1" int="0" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Filter ADSR" id="e3bd243d37cf5cc5" memberName="filterADSR"
         virtualName="" explicitFocusOrder="0" pos="12 236 112 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Filter ADSR" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: chainsawbg_png, 31053, "../../../chainsawbg.png"
static const unsigned char resource_EditorGUI_chainsawbg_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,1,79,0,0,1,164,8,6,0,0,0,177,78,167,179,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,
6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,12,235,0,0,12,235,1,229,214,68,210,0,0,0,7,116,73,77,69,7,218,11,15,19,36,2,81,68,41,13,0,0,0,25,116,69,88,116,67,111,109,109,
101,110,116,0,67,114,101,97,116,101,100,32,119,105,116,104,32,71,73,77,80,87,129,14,23,0,0,32,0,73,68,65,84,120,218,236,189,119,124,29,213,157,247,255,158,153,219,187,116,117,213,171,37,91,182,228,222,
13,6,227,24,59,196,166,5,131,89,74,32,36,164,109,26,41,155,100,179,100,91,200,179,217,13,201,38,217,77,2,105,148,0,134,0,161,216,96,140,141,11,238,85,178,101,89,86,239,210,149,116,123,111,51,243,251,67,
70,65,20,219,60,49,129,231,151,251,126,189,238,75,154,123,207,204,156,51,247,158,207,57,223,50,103,4,85,85,85,178,100,201,146,37,203,123,66,204,94,130,44,89,178,100,201,138,103,150,44,89,178,100,197,51,
75,150,44,89,178,226,153,37,75,150,44,89,241,204,146,37,75,150,172,120,102,201,146,37,75,150,172,120,102,201,146,37,75,86,60,179,100,201,146,37,43,158,89,178,100,201,146,21,207,44,23,157,221,187,119,243,
197,47,126,145,121,243,230,225,112,56,144,36,9,147,201,68,109,109,45,183,221,118,27,79,63,253,52,233,116,250,29,247,21,4,97,226,117,33,188,215,242,215,95,127,253,68,249,107,174,185,230,130,219,116,190,
243,188,249,115,81,20,105,104,104,248,139,235,157,72,36,120,248,225,135,185,246,218,107,41,47,47,199,100,50,161,211,233,112,58,157,204,155,55,143,219,111,191,157,95,252,226,23,116,116,116,92,112,59,222,
75,251,43,43,43,39,202,30,58,116,232,93,203,69,163,81,180,90,45,130,32,32,73,18,129,64,224,93,203,30,60,120,112,226,152,149,149,149,217,206,242,97,64,205,242,129,211,210,210,162,46,90,180,72,5,206,251,
170,168,168,80,159,126,250,233,73,251,111,220,184,113,82,153,243,241,94,203,191,248,226,139,170,36,73,19,229,53,26,141,234,118,187,255,226,243,188,245,115,64,93,189,122,245,95,84,239,99,199,142,169,149,
149,149,23,116,45,47,244,231,255,94,218,255,226,139,47,170,151,93,118,217,68,217,255,252,207,255,124,199,114,233,116,90,253,238,119,191,59,169,46,155,55,111,126,199,178,30,143,71,189,229,150,91,38,202,
221,121,231,157,217,78,243,33,64,147,29,62,62,88,182,108,217,194,250,245,235,137,199,227,0,212,215,215,179,106,213,42,166,77,155,134,195,225,64,150,101,134,135,135,57,118,236,24,219,182,109,163,183,183,
151,155,110,186,137,191,214,146,4,201,100,146,103,158,121,6,89,150,39,222,203,100,50,60,246,216,99,124,227,27,223,184,232,231,219,182,109,27,175,189,246,26,171,86,173,122,207,251,158,62,125,154,21,43,
86,16,137,68,0,88,176,96,1,107,214,172,97,202,148,41,152,76,38,34,145,8,237,237,237,236,223,191,159,131,7,15,162,40,202,69,111,191,203,229,98,198,140,25,236,217,179,103,194,154,248,214,183,190,245,182,
114,30,143,135,150,150,22,0,180,90,45,233,116,154,215,95,127,157,117,235,214,189,173,236,232,232,40,167,79,159,158,216,94,177,98,69,182,227,124,8,200,138,231,7,200,225,195,135,185,241,198,27,137,199,227,
8,130,192,215,191,254,117,190,242,149,175,144,151,151,135,209,104,68,81,20,194,225,48,131,131,131,212,214,214,178,118,237,90,30,121,228,17,118,237,218,245,87,171,99,79,79,207,59,158,239,145,71,30,121,
95,196,19,224,219,223,254,54,71,142,28,185,96,151,2,64,60,30,231,158,123,238,153,16,206,107,175,189,150,7,31,124,144,220,220,92,180,90,45,169,84,10,143,199,67,95,95,31,11,23,46,100,195,134,13,23,116,29,
223,107,251,243,243,243,169,171,171,155,216,222,187,119,47,178,44,35,73,210,164,114,99,99,99,19,226,121,197,21,87,176,109,219,182,9,193,125,43,195,195,195,180,182,182,78,108,95,113,197,21,217,206,147,
245,121,254,237,18,137,68,184,251,238,187,137,197,98,0,220,115,207,61,220,127,255,253,19,62,186,55,252,96,14,135,131,250,250,122,174,190,250,106,234,234,234,248,220,231,62,199,191,255,251,191,255,213,
234,185,125,251,118,250,250,250,38,102,72,122,189,30,128,166,166,38,142,29,59,118,81,207,165,213,106,1,56,118,236,24,127,252,227,31,223,211,190,205,205,205,147,234,243,243,159,255,156,194,194,66,116,58,
29,130,32,160,215,235,41,41,41,97,217,178,101,172,91,183,142,5,11,22,240,220,115,207,93,244,246,231,231,231,83,80,80,64,110,110,46,0,161,80,232,29,253,184,3,3,3,116,118,118,2,112,205,53,215,32,138,34,
199,142,29,155,176,64,222,228,86,227,240,225,195,36,18,9,0,74,74,74,168,170,170,202,118,160,172,120,254,237,242,216,99,143,209,212,212,52,209,33,126,244,163,31,157,219,68,208,104,88,188,120,49,179,102,
205,226,123,223,251,222,95,165,142,126,191,159,205,155,55,79,108,47,89,178,132,165,75,151,78,154,125,93,76,214,172,89,51,241,255,189,247,222,251,174,193,177,119,98,104,104,136,96,48,56,177,93,80,80,240,
174,101,45,22,11,203,151,47,127,95,218,111,177,88,48,153,76,147,102,159,187,119,239,158,84,70,81,20,142,28,57,66,58,157,166,190,190,158,252,252,124,42,42,42,72,165,82,28,60,120,240,109,117,56,117,234,
212,196,246,202,149,43,179,157,39,43,158,127,187,248,124,190,73,157,242,179,159,253,236,219,204,186,119,163,190,190,254,175,86,207,182,182,54,246,237,219,55,177,125,211,77,55,113,249,229,151,79,108,111,
220,184,241,61,9,220,249,184,238,186,235,48,26,141,0,116,116,116,240,235,95,255,250,130,247,77,36,18,152,205,230,137,237,231,159,127,254,3,107,127,126,126,62,51,102,204,152,216,126,171,217,239,245,122,
105,110,110,158,48,193,115,114,114,152,62,125,58,192,219,76,247,183,250,59,179,38,123,86,60,255,166,233,235,235,155,228,195,250,48,6,0,20,69,225,185,231,158,35,28,14,3,80,92,92,204,134,13,27,152,49,99,
6,121,121,121,192,120,208,99,211,166,77,23,237,156,185,185,185,147,2,38,223,255,254,247,137,70,163,23,180,175,78,167,155,52,176,124,242,147,159,228,171,95,253,42,251,246,237,35,153,76,254,85,219,255,70,
208,232,13,246,238,221,59,41,56,53,54,54,198,153,51,103,0,184,252,242,203,113,185,92,239,42,158,110,183,123,162,236,135,245,183,146,21,207,44,127,53,198,198,198,24,25,25,153,216,126,163,227,92,44,222,
156,11,249,78,175,91,110,185,229,130,204,224,237,219,183,79,18,163,194,194,66,44,22,203,164,217,215,195,15,63,124,209,234,61,125,250,116,214,173,91,135,213,106,5,96,100,100,132,31,255,248,199,23,180,111,
126,126,62,235,215,175,199,96,48,0,227,81,242,159,255,252,231,44,95,190,28,155,205,198,252,249,243,249,252,231,63,207,211,79,63,253,54,191,226,197,110,127,126,126,62,69,69,69,228,228,228,0,16,8,4,56,113,
226,196,36,65,108,107,107,123,71,241,60,112,224,0,153,76,6,24,247,119,30,57,114,100,162,190,69,69,69,212,212,212,100,59,80,86,60,255,118,137,68,34,19,81,97,0,135,195,241,161,171,99,67,67,3,141,141,141,
19,219,119,221,117,23,48,158,0,254,102,241,216,178,101,11,163,163,163,23,229,156,181,181,181,216,237,118,174,187,238,186,137,247,238,191,255,126,198,198,198,206,187,239,204,153,51,169,168,168,224,159,
255,249,159,41,47,47,159,244,89,42,149,162,161,161,129,7,31,124,144,13,27,54,80,92,92,204,253,247,223,127,206,84,165,191,164,253,86,171,21,163,209,248,142,166,251,27,130,152,72,36,168,174,174,166,176,
176,16,151,203,133,205,102,163,164,164,132,104,52,202,241,227,199,39,68,247,228,201,147,19,199,200,250,59,179,226,249,55,79,42,149,122,95,143,191,113,227,198,243,190,206,197,91,115,27,151,46,93,58,49,
227,169,170,170,162,160,160,128,218,218,90,96,60,231,241,241,199,31,191,40,245,214,104,52,212,213,213,177,102,205,154,137,104,117,56,28,230,190,251,238,59,239,190,54,155,141,85,171,86,49,111,222,60,126,
248,195,31,242,143,255,248,143,124,228,35,31,161,168,168,232,109,101,3,129,0,255,240,15,255,192,173,183,222,250,142,249,178,23,163,253,111,77,89,122,35,104,244,230,0,208,27,254,75,189,94,143,205,102,155,
56,230,235,175,191,14,140,251,59,223,72,103,202,154,236,31,62,178,121,158,31,16,22,139,101,194,159,22,8,4,206,25,29,126,175,252,221,223,253,221,57,63,127,242,201,39,207,249,249,91,115,27,63,253,233,79,
79,170,183,203,229,98,197,138,21,19,126,219,71,30,121,132,175,125,237,107,23,165,238,83,167,78,165,181,181,149,245,235,215,243,155,223,252,6,128,7,30,120,128,123,238,185,231,188,251,230,228,228,112,213,
85,87,225,118,187,169,169,169,225,210,75,47,37,28,14,19,139,197,232,238,238,230,196,137,19,236,218,181,107,226,186,63,245,212,83,172,93,187,150,59,238,184,227,162,183,255,173,65,163,61,123,246,160,170,
234,164,252,206,55,207,96,223,240,147,238,216,177,131,61,123,246,240,205,111,126,243,109,254,206,108,176,40,59,243,252,155,71,167,211,77,18,203,55,119,144,15,3,111,206,109,52,24,12,108,216,176,97,210,
231,85,85,85,44,89,178,4,157,78,7,192,137,19,39,206,123,79,250,5,255,32,69,145,250,250,122,86,172,88,65,97,97,225,196,76,253,222,123,239,189,224,99,20,22,22,178,104,209,34,214,173,91,199,250,245,235,185,
250,234,171,185,241,198,27,185,235,174,187,248,233,79,127,58,49,195,3,248,237,111,127,251,190,180,63,63,63,159,226,226,98,236,118,59,48,158,97,113,242,228,73,70,70,70,38,68,247,205,226,153,159,159,63,
225,247,124,35,192,116,244,232,209,137,128,89,65,65,1,211,166,77,203,118,158,172,120,102,103,157,111,238,192,111,152,105,31,6,222,154,219,152,72,36,176,219,237,147,2,78,213,213,213,124,250,211,159,158,
228,126,184,152,129,163,41,83,166,224,112,56,38,137,214,198,141,27,233,233,233,121,207,199,210,106,181,228,231,231,51,103,206,28,174,190,250,106,42,42,42,184,243,206,59,39,62,127,179,79,241,98,182,223,
106,181,98,48,24,38,205,62,119,239,222,205,241,227,199,137,68,34,148,148,148,76,90,224,195,229,114,145,151,151,135,203,229,194,231,243,113,224,192,129,172,191,51,43,158,89,222,138,203,229,98,217,178,101,
19,219,15,61,244,208,164,123,167,63,72,222,154,219,120,161,60,241,196,19,23,45,231,83,16,4,102,205,154,197,210,165,75,169,168,168,0,198,3,45,231,243,213,94,136,144,206,159,63,159,178,178,178,137,247,222,
184,195,235,253,104,255,91,253,158,219,183,111,159,184,49,226,173,38,184,201,100,194,108,54,79,12,170,219,182,109,203,250,59,63,228,100,125,158,31,0,229,229,229,84,87,87,83,95,95,79,115,115,51,221,221,
221,252,232,71,63,226,59,223,249,206,5,237,127,223,125,247,189,39,51,246,66,121,107,110,99,110,110,46,255,243,63,255,131,40,138,239,90,254,203,95,254,50,62,159,15,143,199,195,75,47,189,196,245,215,95,
127,209,174,81,75,75,11,55,223,124,51,255,245,95,255,245,142,179,196,255,27,236,118,59,94,175,119,146,137,255,126,181,255,157,238,115,127,67,28,223,108,178,191,121,80,157,62,125,58,123,247,238,101,207,
158,61,89,241,252,176,147,93,88,234,131,97,199,142,29,234,79,126,242,19,213,96,48,76,44,115,246,208,67,15,157,115,159,72,36,162,174,95,191,254,109,75,169,93,172,37,233,250,251,251,213,5,11,22,76,188,255,
221,239,126,247,93,143,161,40,138,250,194,11,47,168,215,95,127,253,68,249,235,174,187,238,47,90,146,238,173,12,14,14,170,27,55,110,84,107,107,107,47,104,57,185,181,107,215,170,141,141,141,231,108,123,
40,20,154,180,100,220,167,62,245,169,247,173,253,193,96,80,221,184,113,163,106,179,217,38,202,104,181,90,21,80,91,90,90,222,118,204,142,142,14,245,254,251,239,159,84,14,80,93,46,87,182,195,124,8,201,154,
237,31,16,11,23,46,164,172,172,140,111,126,243,155,232,245,122,50,153,12,119,221,117,23,171,87,175,230,233,167,159,102,96,96,128,76,38,67,34,145,160,169,169,137,31,252,224,7,84,86,86,242,236,179,207,190,
111,117,122,183,220,198,119,51,173,43,43,43,39,205,136,94,126,249,229,11,202,201,188,80,138,139,139,113,185,92,231,205,30,120,195,111,252,242,203,47,51,119,238,92,86,174,92,201,3,15,60,192,169,83,167,
136,197,98,200,178,204,200,200,8,47,190,248,34,43,87,174,156,184,139,199,104,52,78,154,193,95,236,246,219,108,182,183,249,61,211,233,52,121,121,121,239,120,99,132,203,229,162,164,164,4,155,205,54,201,
5,144,141,178,103,125,158,89,222,132,213,106,229,242,203,47,103,206,156,57,220,119,223,125,19,121,132,219,183,111,103,195,134,13,148,149,149,161,213,106,49,26,141,204,158,61,155,123,239,189,23,143,199,
67,94,94,222,251,34,160,231,202,109,124,55,166,76,153,66,97,97,225,68,20,56,157,78,95,180,156,207,55,152,61,123,54,211,167,79,103,206,156,57,231,44,55,52,52,52,241,255,174,93,187,248,194,23,190,192,172,
89,179,48,155,205,104,52,26,10,11,11,185,238,186,235,38,86,66,114,185,92,188,252,242,203,19,43,20,189,95,237,127,235,173,154,231,50,193,223,16,219,55,7,19,179,226,153,21,207,44,239,64,126,126,62,107,214,
172,97,206,156,57,124,255,251,223,231,222,123,239,229,202,43,175,164,188,188,28,163,209,136,32,8,104,181,90,10,11,11,89,190,124,57,223,249,206,119,56,114,228,8,55,220,112,195,69,175,203,185,114,27,223,
13,139,197,66,94,94,222,36,49,184,152,81,247,55,196,167,168,168,136,155,111,190,249,188,101,127,246,179,159,241,217,207,126,150,85,171,86,49,117,234,84,114,114,114,38,30,115,97,48,24,40,42,42,98,201,146,
37,124,237,107,95,163,177,177,113,146,40,189,95,237,127,171,223,243,221,252,157,111,144,151,151,119,193,98,155,229,131,69,80,255,90,75,146,103,57,39,163,163,163,244,245,245,225,241,120,136,70,163,100,
50,25,68,81,196,100,50,225,116,58,41,45,45,165,164,164,228,29,23,8,126,115,210,251,133,152,184,239,84,254,149,87,94,153,120,134,206,162,69,139,168,174,174,190,160,122,119,118,118,114,228,200,17,96,252,
54,211,171,174,186,234,130,235,117,161,245,246,251,253,108,221,186,117,210,123,111,45,31,141,70,25,25,25,193,231,243,17,8,4,136,70,163,164,82,41,20,69,65,146,36,140,70,35,14,135,131,146,146,18,202,203,
203,223,22,4,122,63,218,15,16,12,6,217,178,101,203,196,246,252,249,243,207,153,175,217,214,214,54,113,123,38,192,199,62,246,177,137,92,209,44,89,241,204,146,37,75,150,172,217,158,37,75,150,44,89,241,204,
146,37,75,150,44,89,241,204,146,37,75,150,172,120,102,201,146,37,75,86,60,179,100,201,146,37,43,158,89,178,100,201,146,21,207,44,89,178,100,201,146,21,207,44,89,178,100,201,138,231,7,201,185,30,22,150,
37,75,150,172,120,102,121,183,11,37,254,255,253,82,37,129,115,61,152,46,113,246,5,144,201,254,32,222,15,212,236,0,157,21,79,228,191,176,147,41,103,95,89,254,242,239,96,252,122,38,50,94,134,220,45,132,
194,195,147,250,234,153,150,182,179,91,250,115,94,243,174,211,167,105,220,191,143,152,167,143,120,200,67,38,18,250,224,219,167,196,222,210,206,255,199,17,178,115,153,255,167,190,174,139,119,111,187,10,
140,47,90,161,200,17,68,201,242,158,246,62,126,252,24,209,192,40,151,173,88,9,146,134,15,106,145,251,84,50,65,115,243,105,206,156,57,67,111,127,31,118,171,149,79,127,250,110,180,90,61,155,55,191,76,94,
94,46,203,46,89,122,222,227,36,194,97,12,86,203,196,53,249,96,218,18,228,244,169,38,154,78,158,98,104,100,16,143,223,207,103,63,243,247,76,173,169,227,84,83,27,219,182,239,224,133,23,159,231,161,135,126,
75,85,101,233,57,143,229,25,234,227,145,223,255,142,51,167,79,225,241,120,41,40,173,192,153,151,79,126,65,1,21,229,229,84,215,84,83,80,80,128,221,97,67,210,104,208,104,37,16,244,23,189,77,67,3,167,233,
104,107,99,112,112,144,190,129,126,28,182,2,110,248,248,13,164,83,10,127,248,195,99,84,86,85,114,243,237,159,56,119,91,60,30,68,81,196,104,52,162,211,233,144,36,233,3,236,130,10,160,162,100,50,40,169,
4,26,147,121,226,183,127,232,208,33,60,30,15,235,214,173,59,247,247,156,201,208,123,246,249,78,86,139,5,151,43,15,73,202,62,36,226,253,230,226,92,97,57,134,44,11,244,117,183,98,177,90,113,21,143,175,145,
168,38,130,60,246,200,35,44,189,98,37,83,107,103,157,123,10,44,136,108,221,188,153,253,175,109,35,147,206,144,155,147,131,213,102,163,168,160,136,138,170,74,138,11,11,16,181,122,68,189,14,209,96,71,212,
106,47,178,41,173,160,134,188,108,123,238,79,28,57,124,152,193,145,81,194,137,20,243,230,45,226,217,39,158,164,237,140,155,63,254,241,105,150,44,158,115,30,241,84,9,121,199,24,26,26,28,255,49,91,45,72,
26,45,26,73,131,197,106,69,167,213,34,234,76,40,225,36,162,70,2,211,123,248,10,20,21,53,157,28,151,99,189,97,242,87,16,246,34,153,76,32,25,1,8,143,13,242,226,179,207,210,211,221,67,48,20,196,104,177,114,
245,213,31,199,98,206,225,119,191,125,140,29,175,189,78,99,227,41,78,159,105,33,18,10,159,247,212,6,147,5,175,47,68,67,115,11,61,157,61,132,83,123,49,91,172,160,66,58,147,198,153,231,64,18,4,92,5,78,156,
185,185,92,191,254,6,62,243,169,191,63,167,113,147,244,122,24,234,31,64,210,73,56,236,118,108,133,133,32,233,64,206,224,237,239,37,17,143,83,82,61,21,116,122,144,51,28,221,183,157,151,182,110,193,61,226,
38,16,140,224,243,6,208,104,116,52,55,52,225,11,68,217,181,115,23,95,248,252,231,207,219,150,145,209,81,18,241,56,102,139,5,189,94,143,209,96,64,163,209,160,209,104,208,235,245,232,245,122,34,145,8,54,
155,237,125,237,124,195,189,29,52,54,54,208,214,222,129,40,8,168,64,113,81,17,149,149,83,232,234,119,243,236,115,207,18,143,167,206,43,158,162,156,230,208,222,157,28,63,126,156,76,58,77,65,97,62,21,229,
21,148,151,149,145,151,239,164,208,233,36,215,89,0,134,191,206,96,62,54,54,138,223,63,132,199,61,76,101,229,116,138,203,199,245,64,78,192,240,240,16,165,85,197,89,241,244,142,186,57,242,250,107,116,118,
118,224,30,26,38,17,143,115,239,191,252,51,40,9,14,188,178,149,231,95,124,129,7,30,124,132,7,126,255,107,166,212,212,35,73,239,222,145,114,114,114,48,155,44,252,246,151,191,194,239,15,35,8,32,72,144,147,
147,139,213,102,71,175,211,147,227,116,82,81,85,69,159,207,67,89,69,21,191,252,197,47,207,142,220,239,112,92,37,195,222,87,158,167,191,175,23,173,40,34,32,176,98,229,10,242,166,76,129,100,146,3,219,182,
211,114,166,133,217,51,231,176,240,170,171,192,231,227,208,206,87,217,183,229,121,82,105,25,109,6,202,242,11,241,122,253,108,122,229,55,120,61,105,122,123,6,89,186,116,241,249,38,243,104,181,26,44,22,
11,178,172,0,2,145,104,4,69,86,8,71,198,69,74,82,52,244,117,245,145,202,164,153,53,123,54,241,84,146,194,210,18,116,70,221,59,30,209,215,215,193,238,29,59,112,187,71,240,249,188,152,140,122,74,74,74,153,
57,107,38,117,139,23,177,227,185,151,216,187,247,117,236,86,7,171,87,95,73,213,212,105,28,218,181,11,239,128,27,33,153,194,132,150,75,23,45,163,178,124,10,15,63,242,56,15,254,242,247,140,142,6,153,49,
189,14,187,213,65,58,117,126,211,215,61,226,165,164,114,10,229,149,211,233,237,27,67,139,30,81,48,160,72,42,146,32,18,141,166,72,203,113,226,233,4,135,14,158,96,195,45,55,190,139,112,166,232,107,107,101,
203,230,45,244,245,244,144,138,39,144,229,12,177,88,140,5,243,23,178,116,209,34,134,70,71,120,125,215,78,124,62,63,245,245,245,44,91,178,148,161,225,65,118,239,223,67,40,30,67,145,65,148,53,104,49,16,
11,38,56,124,176,1,68,13,177,112,10,103,110,209,121,219,98,181,88,48,26,141,103,7,109,129,100,50,73,56,18,65,81,20,180,103,31,39,220,208,208,192,236,89,179,200,119,185,80,85,21,135,195,113,142,241,82,
101,112,112,144,254,190,62,130,161,16,206,156,28,166,214,212,96,119,58,199,63,78,166,240,140,141,33,103,210,20,86,150,1,18,131,109,167,216,187,111,63,67,35,163,32,64,126,97,41,58,131,158,151,54,191,76,
107,71,15,201,180,129,112,32,132,51,63,247,252,99,106,58,134,111,116,132,211,167,78,114,252,248,49,82,233,113,119,153,195,102,199,233,204,197,233,200,165,166,188,10,91,110,46,165,149,83,112,143,140,240,
165,123,190,70,97,73,241,121,39,20,241,72,4,173,86,135,230,173,131,117,50,130,164,183,76,114,163,180,159,110,162,185,233,20,71,142,28,166,249,204,25,4,65,228,43,95,250,26,197,229,85,188,190,253,0,15,255,
254,33,234,103,207,226,27,223,249,242,185,45,131,225,97,142,53,52,96,50,27,209,233,244,148,151,151,82,84,82,114,86,248,255,154,174,141,228,89,137,148,254,50,241,84,20,101,210,76,47,18,9,243,167,63,253,
137,200,240,0,161,64,0,139,193,200,237,55,221,66,36,154,228,209,251,126,196,163,79,60,70,38,163,18,2,76,102,251,57,133,19,32,26,74,17,142,65,90,103,39,46,165,40,40,40,32,150,72,49,18,73,48,26,15,147,145,
253,200,157,131,72,199,155,137,196,2,92,115,245,85,111,119,219,202,50,72,18,125,199,143,243,226,166,23,232,104,109,36,28,14,147,74,203,164,210,41,182,109,221,74,85,85,21,22,171,149,230,83,205,12,187,221,
108,218,242,26,51,55,111,167,184,48,143,246,214,211,24,180,102,226,201,8,158,80,132,225,216,32,110,127,156,126,183,151,41,21,179,24,243,199,73,158,215,28,82,136,39,18,164,210,105,4,65,64,85,69,36,81,66,
145,21,68,65,60,251,94,6,57,149,68,85,101,252,94,15,162,70,64,103,120,39,225,204,112,108,203,11,108,218,180,137,120,34,129,201,104,66,167,211,48,230,27,161,191,171,141,150,19,71,113,108,126,129,120,76,
33,21,142,211,63,234,227,145,190,135,208,104,68,76,6,19,25,69,33,16,8,80,87,87,199,71,46,95,193,75,7,14,176,241,137,39,137,198,163,172,191,113,61,83,171,167,225,243,123,113,230,228,159,215,35,147,74,102,
168,174,158,65,95,255,8,175,239,57,76,52,26,39,154,248,179,95,91,210,128,172,202,4,67,30,102,204,157,206,154,181,215,189,205,157,51,60,208,206,201,227,13,188,190,99,23,94,143,23,171,209,136,170,40,104,
69,17,139,193,200,193,61,123,104,58,126,20,141,86,139,34,43,100,226,113,14,237,219,75,91,243,73,244,122,3,177,140,74,56,146,68,167,51,34,168,90,70,135,188,36,147,41,242,243,75,200,205,113,162,36,53,232,
36,243,185,141,36,69,38,24,12,160,213,232,65,84,16,69,9,141,40,161,145,4,84,68,76,58,45,102,147,17,223,232,8,189,157,70,52,26,129,84,70,193,238,176,35,188,195,172,109,180,189,149,93,59,118,210,215,219,
131,44,171,100,210,105,100,89,38,17,139,50,99,250,12,74,75,75,233,238,233,225,212,137,19,152,45,22,46,95,117,57,229,21,101,236,222,191,159,120,44,129,65,103,34,46,167,200,203,203,231,192,193,35,60,251,
236,38,66,241,40,213,149,139,40,46,173,196,229,58,255,90,158,201,12,228,228,23,83,86,85,195,235,135,142,161,149,12,104,181,90,2,9,153,145,142,62,244,210,48,125,131,99,180,246,116,99,51,154,200,201,201,
229,158,123,190,254,46,71,203,224,238,238,228,224,129,3,180,119,182,147,78,102,136,199,162,212,213,205,96,229,202,21,20,78,169,161,253,68,35,47,191,188,133,194,124,23,215,92,123,45,166,252,82,58,26,14,
243,252,179,127,162,187,167,139,104,52,129,221,96,230,242,213,31,99,160,127,140,239,124,253,123,156,58,213,194,142,29,59,249,167,234,154,243,182,39,47,223,137,217,160,197,59,54,74,34,30,163,189,165,25,
73,146,136,37,226,88,205,102,10,11,11,25,27,243,80,85,85,201,148,105,181,36,18,73,10,139,139,222,85,228,254,239,145,32,57,70,60,24,194,231,15,225,30,243,51,107,193,18,116,70,27,190,80,248,207,226,121,
236,240,225,241,69,93,101,5,57,35,83,53,165,148,233,51,166,83,82,84,204,145,195,135,249,227,147,27,113,230,230,242,137,219,111,71,201,100,56,213,116,146,96,95,15,62,143,159,68,38,205,162,165,151,97,43,
168,224,225,167,158,225,87,15,61,75,127,127,128,203,87,95,133,61,149,139,54,183,252,109,29,233,173,68,66,97,114,243,75,168,168,157,201,144,255,32,221,67,35,128,136,40,232,80,212,4,162,32,161,55,26,208,
27,12,68,98,1,190,250,149,175,188,41,48,34,142,31,87,85,121,237,153,103,120,233,229,151,137,132,131,196,99,97,244,58,29,58,65,38,39,55,151,64,40,196,241,147,77,104,68,9,163,201,136,193,98,37,45,139,52,
119,245,211,213,63,136,213,172,199,27,10,225,116,230,81,100,43,228,149,93,7,72,75,6,230,45,94,206,244,169,243,169,170,157,75,73,137,3,249,28,95,147,119,212,141,207,227,65,101,252,81,183,145,72,4,69,85,
81,21,21,65,16,208,104,52,100,146,73,116,90,1,155,209,142,70,84,48,153,45,111,187,44,131,189,157,108,127,241,89,134,187,218,64,73,161,21,85,84,57,129,160,24,176,89,76,88,76,122,100,89,33,232,243,2,6,36,
81,196,108,50,193,217,197,146,21,21,50,233,52,22,139,133,69,11,23,34,21,22,210,218,218,66,111,79,7,27,54,220,198,252,121,139,16,37,29,101,21,69,244,246,117,83,81,157,255,174,113,153,161,190,97,198,70,
189,232,244,38,22,47,185,148,68,70,96,216,237,39,30,147,137,196,194,132,35,65,60,99,110,98,9,63,99,67,125,212,205,92,64,81,110,201,196,76,28,160,163,237,56,79,60,242,7,90,90,90,208,137,90,36,85,197,159,
136,17,79,36,112,57,114,137,134,66,24,244,6,18,177,40,146,36,161,215,235,145,83,41,116,26,13,126,223,248,34,197,113,25,194,9,149,117,87,175,32,22,141,115,252,104,19,118,107,30,229,101,21,232,12,38,180,
58,19,177,68,226,93,141,17,128,206,19,205,12,180,183,161,215,27,209,234,37,180,58,45,86,179,25,171,217,140,70,167,67,138,199,73,198,227,84,229,231,225,212,233,209,203,10,250,92,231,219,133,51,149,224,
240,246,87,57,188,127,31,74,50,133,221,106,67,81,65,205,104,145,85,21,197,60,46,192,99,238,97,204,22,51,243,230,204,38,20,9,115,224,192,126,78,183,58,136,199,18,104,141,70,162,1,31,115,23,44,164,164,184,
152,67,135,15,35,8,176,246,170,181,44,89,186,26,147,217,138,197,98,56,111,23,55,218,156,84,213,206,196,19,78,144,179,109,15,67,253,125,140,103,70,8,136,122,3,137,88,154,140,63,130,209,232,32,20,15,179,
225,150,143,146,87,82,244,182,17,50,49,218,207,182,87,183,114,166,165,133,225,225,33,194,209,24,86,179,153,100,34,197,211,13,199,216,189,245,21,86,174,92,73,79,111,47,141,39,78,16,14,135,232,104,110,102,
230,236,89,52,55,159,98,108,116,12,37,158,192,172,19,153,53,119,17,221,157,131,236,219,119,144,182,182,30,114,237,185,216,108,14,52,186,55,79,18,18,192,219,219,39,167,226,76,175,173,33,35,43,24,12,6,18,
177,24,153,140,194,136,219,141,199,235,195,55,230,229,76,243,105,122,58,187,216,185,99,39,35,67,195,124,243,155,95,39,191,178,230,77,26,163,78,250,253,145,137,67,36,138,28,75,160,26,244,104,114,115,223,
210,139,51,103,203,158,125,47,238,165,97,247,171,180,53,159,98,208,61,66,90,21,25,241,133,201,121,225,37,22,47,95,193,107,187,247,163,25,107,109,101,199,214,173,244,245,244,48,54,58,134,154,206,96,50,
26,105,223,183,147,29,122,13,5,174,124,52,90,9,99,34,74,160,55,192,67,63,251,111,52,162,68,60,17,3,73,34,133,142,178,41,53,92,114,217,10,78,183,245,242,155,223,253,30,157,222,202,250,219,110,103,254,162,
101,84,79,159,5,162,230,156,194,233,115,7,73,38,83,212,205,154,131,100,178,81,51,173,158,214,246,54,18,201,36,65,95,128,104,44,78,70,201,144,76,164,240,250,60,56,243,92,44,187,244,146,63,143,14,64,104,
104,144,71,31,121,148,237,175,190,138,36,138,24,12,90,244,26,19,130,40,160,162,33,158,82,208,233,76,104,36,3,177,68,130,180,44,97,212,153,73,39,1,157,153,180,160,16,76,200,52,55,117,240,131,31,222,133,
51,191,132,118,119,16,189,163,128,156,188,98,122,135,135,177,153,29,28,60,122,148,141,207,108,225,150,27,63,118,246,204,111,154,89,5,135,121,125,251,54,236,86,59,54,155,21,131,97,252,81,26,102,139,153,
76,38,67,42,153,34,153,72,162,164,211,184,156,185,136,130,128,65,18,41,44,40,152,116,61,26,14,237,97,251,142,237,120,7,250,33,62,46,42,58,189,22,69,81,136,39,19,227,202,32,140,119,103,85,16,64,81,16,181,
58,20,69,38,157,206,140,207,242,53,2,209,80,140,89,179,231,48,247,146,241,107,53,165,166,130,218,250,169,52,156,56,50,110,66,22,150,1,42,71,142,236,36,154,240,48,189,174,6,167,195,142,191,111,12,5,1,191,
47,68,239,192,16,209,120,146,184,172,162,32,146,202,168,228,229,23,161,215,21,16,141,102,208,27,116,184,242,115,208,25,68,2,161,49,58,218,79,243,133,47,76,126,132,69,115,227,126,30,127,252,49,78,157,62,
141,148,81,145,53,41,70,135,70,49,155,76,164,147,41,250,59,251,49,24,12,152,140,38,20,85,69,163,209,160,138,42,178,172,16,137,70,49,153,77,168,40,140,140,249,176,228,186,184,253,147,119,210,220,220,70,
195,169,86,244,58,35,225,68,2,139,86,36,148,242,178,235,192,22,74,159,43,224,99,235,214,161,55,76,30,226,6,78,182,179,233,201,103,137,132,130,148,149,149,98,113,88,48,219,204,36,45,22,34,6,3,102,179,153,
84,50,137,201,108,166,192,233,194,96,208,51,58,54,70,73,158,107,178,175,178,189,141,87,95,121,153,222,142,118,82,177,56,249,78,39,146,70,131,132,0,90,45,178,172,160,170,42,170,170,144,74,38,73,196,226,
164,146,73,16,68,92,249,5,164,50,73,244,38,3,145,72,12,163,197,198,170,43,87,49,50,230,37,153,140,83,144,151,71,73,73,9,189,93,29,184,92,133,136,133,185,12,15,122,41,42,113,190,115,0,205,27,33,18,137,
161,8,90,10,138,43,184,245,142,187,25,114,15,50,50,50,138,223,23,32,147,206,144,72,165,24,232,239,71,111,51,146,201,200,92,123,237,219,31,227,50,214,218,200,83,79,61,205,145,195,135,112,57,243,72,165,
18,216,245,70,200,40,232,37,129,162,124,23,170,2,187,119,238,0,68,156,246,28,114,237,118,122,122,123,232,238,236,194,100,54,163,209,234,56,113,162,137,207,124,230,51,24,172,185,124,255,71,255,137,164,
213,51,103,214,92,92,174,66,78,183,52,49,101,202,155,87,232,55,188,163,153,19,9,4,136,70,130,40,178,2,74,6,69,150,65,86,40,41,42,161,162,172,2,84,21,103,78,14,22,139,149,84,42,69,127,95,31,174,130,226,
201,98,121,246,175,28,28,229,116,227,9,78,30,61,198,72,255,48,114,34,206,88,52,68,121,93,53,215,95,115,45,86,155,149,227,199,27,104,60,217,72,121,105,25,171,175,92,141,193,100,100,207,174,157,116,54,30,
197,63,58,130,217,158,67,129,203,69,60,150,225,233,39,159,228,217,231,54,147,86,181,104,254,240,219,7,137,135,99,100,82,105,52,138,138,78,171,197,160,213,161,47,200,39,153,73,50,22,240,32,32,98,182,219,
49,202,105,50,10,164,85,25,173,193,136,70,171,37,30,137,51,123,246,44,28,165,197,196,79,158,38,26,137,112,197,226,75,201,117,56,240,12,15,82,232,202,161,179,163,157,129,41,118,74,43,167,190,237,82,245,
117,12,210,210,210,130,215,235,69,17,244,24,76,118,230,47,94,70,69,245,52,252,254,0,122,147,1,37,173,160,55,24,64,132,161,254,62,202,10,45,152,76,127,54,103,34,158,81,126,253,155,95,179,123,231,110,4,
32,207,225,192,61,50,66,44,22,1,4,204,102,51,62,175,15,68,72,39,211,148,87,85,97,209,24,72,101,210,24,204,6,156,37,149,36,99,81,252,222,17,244,102,27,171,174,252,24,38,167,131,107,219,7,56,220,120,138,
64,56,140,195,156,75,60,30,36,22,11,243,173,111,127,131,253,7,95,101,221,218,53,248,130,30,44,38,43,241,88,156,182,214,78,60,253,125,20,228,185,200,207,47,32,223,149,135,197,98,33,26,141,142,251,72,52,
18,58,157,30,147,86,135,73,35,145,78,36,137,70,66,96,210,79,152,252,221,167,79,240,196,31,254,64,107,103,59,5,118,27,102,141,132,40,129,78,167,33,158,142,147,78,165,145,68,9,65,18,17,69,9,81,0,157,78,
139,2,248,3,65,124,161,32,169,116,154,66,151,11,81,20,177,216,173,160,29,159,134,173,191,241,90,94,121,117,11,155,94,122,149,154,234,41,108,122,249,89,124,94,31,177,68,152,63,189,184,145,133,139,103,83,
234,44,32,230,141,147,74,41,68,34,49,66,209,56,133,197,21,148,86,85,161,213,155,104,109,109,167,189,167,151,80,40,77,34,162,144,235,176,114,233,37,11,169,173,159,74,190,221,129,90,90,198,101,139,23,252,
89,56,91,27,248,241,47,254,151,221,59,119,163,215,25,176,25,44,88,173,57,228,228,149,225,247,6,73,197,50,32,90,9,201,2,209,180,64,42,149,198,225,176,224,247,123,64,82,144,149,52,201,116,18,65,2,147,203,
129,94,111,192,81,144,195,165,206,75,56,122,188,137,157,59,119,33,73,224,246,4,241,120,220,200,106,148,175,127,253,107,60,243,220,11,76,173,170,193,153,107,199,105,177,147,73,36,25,26,30,228,244,233,51,
160,200,184,61,62,140,102,45,249,133,78,140,102,11,162,36,146,99,115,224,116,230,162,11,6,17,68,9,89,150,209,153,140,84,235,254,156,53,48,60,208,203,111,31,254,29,17,127,8,187,217,128,213,108,66,21,32,
26,141,160,211,25,206,166,128,141,167,124,137,146,6,179,197,66,58,157,38,25,79,96,52,27,136,39,19,164,228,20,38,139,153,100,42,200,138,133,11,209,219,115,41,183,229,176,118,237,58,126,254,179,159,243,
212,83,79,82,91,83,207,204,250,25,52,157,60,192,241,35,123,249,210,151,191,192,212,154,42,70,70,135,0,21,21,149,230,150,118,14,159,236,65,163,215,35,10,26,202,203,75,176,57,156,232,77,38,42,42,129,240,
204,27,0,0,32,0,73,68,65,84,166,34,34,129,32,144,150,147,228,57,115,57,217,112,140,178,130,124,86,175,94,51,201,180,24,108,105,230,215,15,252,154,142,182,142,241,193,93,29,35,16,12,97,54,153,209,74,250,
241,233,129,36,140,199,33,4,72,36,211,88,205,86,18,201,4,241,120,108,220,205,34,165,73,134,98,136,58,11,235,111,190,149,253,135,26,200,207,47,193,145,155,75,73,241,184,159,55,223,85,76,123,91,231,248,
36,79,3,168,33,16,204,147,124,153,145,209,62,70,70,134,73,167,82,168,170,76,50,30,67,20,36,84,85,139,197,34,145,140,197,72,103,100,18,241,56,185,57,185,20,22,20,176,96,238,92,4,163,233,45,150,65,144,198,
195,71,104,58,218,72,219,169,83,120,7,221,152,116,122,116,146,134,112,60,196,190,93,125,180,53,159,164,186,114,10,131,3,131,180,181,181,97,181,89,105,61,117,146,188,188,92,134,6,220,164,51,41,194,177,
4,149,165,22,186,60,17,158,127,237,117,58,70,194,196,211,35,228,229,84,161,233,233,235,195,229,204,67,212,105,145,20,153,76,38,131,63,20,68,99,148,48,217,140,24,205,102,146,201,20,178,44,147,201,168,136,
162,136,70,171,71,85,85,146,201,20,133,133,37,44,94,186,12,128,186,25,51,248,248,181,215,242,204,115,47,48,125,246,92,74,202,43,48,155,108,116,159,9,208,114,244,53,62,178,106,5,206,220,60,220,110,55,173,
205,29,68,98,73,218,218,59,49,155,205,88,204,22,28,133,37,12,120,35,12,15,12,18,12,5,145,36,17,155,205,142,197,98,97,90,77,13,6,163,25,173,214,192,218,143,253,249,57,49,153,120,152,123,191,251,93,14,29,
60,72,60,26,195,168,211,19,139,68,168,169,174,70,17,5,226,137,52,177,104,148,162,50,43,122,157,14,179,217,140,156,145,137,38,83,132,3,97,4,67,6,79,172,29,81,150,153,58,165,140,76,42,193,238,221,59,89,
189,118,29,54,179,145,104,36,194,240,208,8,173,129,83,140,12,244,162,209,67,42,29,226,87,63,249,41,191,250,249,79,49,154,76,84,150,87,19,10,70,81,100,129,84,204,143,43,215,198,148,234,41,24,12,198,179,
130,169,163,164,164,4,189,78,135,209,100,102,106,85,5,185,90,29,146,0,193,112,152,96,40,136,70,39,209,61,208,207,203,47,111,33,150,140,81,59,181,26,147,70,71,208,235,103,196,27,192,96,50,99,50,26,16,117,
26,100,21,68,1,20,85,4,21,226,177,40,30,175,15,21,129,242,202,74,116,90,13,221,253,253,100,82,41,254,240,212,147,156,58,211,202,242,203,151,99,116,89,48,154,116,204,159,55,7,141,86,100,229,21,151,51,103,
238,92,140,6,29,135,14,237,37,28,241,163,40,2,85,197,149,36,227,41,50,121,25,34,137,36,138,32,66,50,66,52,18,96,100,176,131,234,242,2,22,206,93,136,197,104,100,160,191,143,80,112,136,134,125,237,120,198,
198,80,80,121,232,87,185,84,148,149,113,166,189,141,29,135,95,71,210,139,220,243,173,111,147,99,182,210,210,116,134,246,150,78,50,201,52,83,167,78,39,28,12,145,95,80,128,206,110,166,187,167,143,210,146,
34,250,250,251,16,36,5,171,213,194,226,37,11,80,145,9,4,130,196,194,17,58,187,250,120,226,145,199,168,171,155,131,40,8,248,124,62,70,220,110,2,129,81,234,102,214,82,94,94,133,215,31,224,224,129,253,108,
124,252,49,114,237,14,28,54,27,162,172,98,49,90,72,167,83,88,76,214,113,223,164,26,35,24,246,145,72,165,200,115,58,201,207,47,96,74,85,37,5,249,5,148,84,148,19,9,71,8,134,66,44,187,114,53,94,111,128,83,
39,78,240,252,179,79,49,54,234,166,188,160,144,84,42,133,36,141,63,194,24,229,207,162,41,156,141,13,168,170,66,50,158,70,81,85,50,178,204,208,224,0,232,36,116,70,61,170,162,144,136,197,25,24,24,100,184,
163,157,162,154,169,172,185,114,21,175,108,217,138,45,55,135,18,87,33,29,237,109,196,227,9,134,134,122,249,242,23,191,192,178,197,139,241,6,60,132,194,97,236,86,43,93,61,253,132,177,96,181,56,40,47,43,
97,108,120,136,19,39,155,240,121,125,8,2,40,178,76,85,101,5,211,167,87,99,32,77,145,211,193,117,215,172,197,240,166,12,143,67,175,239,230,63,254,207,127,114,166,185,25,189,86,162,170,188,156,254,65,47,
225,80,8,157,46,130,172,202,19,185,251,170,42,162,170,25,204,86,27,99,154,8,145,112,152,84,38,141,197,106,195,231,233,32,24,12,243,205,111,125,7,123,101,53,179,147,90,62,250,209,117,120,70,199,240,249,
35,104,36,9,179,209,200,159,158,123,158,234,41,69,92,127,211,85,196,227,126,28,78,3,160,3,53,78,123,227,9,154,79,55,145,201,168,56,28,118,108,54,27,58,141,140,42,0,232,144,101,153,100,50,137,86,171,197,
108,49,35,8,2,145,72,132,162,169,147,253,168,177,128,155,215,182,190,194,246,151,94,197,235,245,226,178,229,96,201,203,195,172,211,163,149,180,228,234,10,24,13,142,32,32,16,24,245,147,138,39,153,53,125,
38,146,36,17,15,196,232,242,4,201,164,51,12,38,227,104,114,236,220,121,237,77,60,246,216,31,57,209,214,137,168,49,147,151,87,141,170,104,16,190,117,231,39,84,65,210,32,169,10,58,73,139,6,1,25,149,180,
42,147,86,210,104,53,90,76,102,35,169,84,138,72,36,74,56,28,70,81,21,140,6,3,169,116,6,163,45,143,127,251,193,127,96,205,207,3,73,228,197,167,95,228,191,127,254,11,114,243,11,240,249,2,12,13,13,99,178,
234,241,186,219,201,113,216,152,53,115,54,54,171,131,246,142,46,84,69,36,30,79,161,215,27,40,42,44,194,236,112,114,248,68,11,33,191,159,202,234,106,10,10,198,253,112,233,84,10,135,221,74,91,91,59,138,
156,97,209,252,90,110,251,187,235,232,239,237,99,243,166,77,216,45,86,174,252,200,149,232,52,90,186,186,186,216,189,99,7,40,2,121,5,69,248,67,97,80,65,171,209,144,202,164,17,69,137,158,238,30,50,178,204,
173,183,222,194,101,151,173,192,232,204,101,215,246,87,105,58,126,132,83,77,39,24,27,25,229,250,245,55,18,87,68,118,237,61,66,67,75,59,78,155,133,59,111,185,145,149,43,151,51,109,70,53,135,14,238,225,
190,251,238,227,76,107,23,83,202,167,163,149,44,164,226,50,145,248,0,130,54,129,78,99,192,235,245,80,61,165,138,155,110,186,153,101,203,150,98,207,201,161,177,161,145,134,195,71,176,136,10,69,121,46,134,
220,110,94,219,181,147,130,194,34,236,206,28,10,139,139,185,238,250,235,185,244,178,75,208,136,58,78,54,158,100,235,214,173,12,12,12,161,213,106,145,68,1,81,18,80,100,21,89,25,55,13,67,161,16,83,107,167,
114,197,202,149,44,93,178,140,116,38,195,209,35,71,216,185,115,7,123,14,236,231,232,225,35,32,72,76,157,93,135,40,74,140,142,120,184,121,195,223,113,199,39,239,98,218,217,31,94,119,119,15,15,255,254,119,
28,220,119,144,50,157,149,116,42,141,140,66,44,157,38,154,140,161,51,234,25,26,26,102,254,178,69,124,230,179,159,99,241,194,133,160,215,209,120,224,16,191,249,245,111,216,183,111,31,30,175,23,187,221,
134,170,168,216,236,54,66,193,32,55,223,125,43,31,223,176,158,217,181,243,0,56,184,127,47,255,231,223,127,200,222,93,251,168,169,172,38,28,30,207,64,240,197,34,88,173,22,64,161,179,191,147,59,110,187,
157,239,125,239,159,168,44,47,38,35,167,217,181,123,55,255,251,191,255,203,232,136,143,190,254,33,166,213,212,97,50,230,112,240,224,97,226,241,8,119,221,121,27,119,127,246,46,166,78,171,64,175,55,242,
232,31,254,200,207,126,246,51,130,1,63,86,147,25,1,45,40,16,14,135,177,152,172,168,42,180,14,53,49,163,172,156,59,62,241,9,230,205,95,128,123,100,132,199,30,123,140,238,174,30,138,139,139,49,153,77,196,
227,73,236,133,133,76,169,172,32,18,10,144,155,99,103,253,245,215,49,165,170,138,209,145,1,78,54,54,208,219,219,131,89,111,64,141,203,72,26,13,90,157,14,65,16,144,51,105,84,69,101,116,108,148,84,42,197,
146,197,139,169,157,93,79,107,103,27,157,221,221,168,136,236,218,189,23,187,35,135,250,57,243,136,68,99,156,60,121,26,73,35,81,224,180,115,203,134,155,113,21,228,51,216,63,192,230,151,54,49,236,30,166,
184,168,136,254,254,126,116,58,29,138,168,193,31,19,81,50,10,69,37,197,180,182,158,193,235,241,50,163,110,58,117,211,235,8,5,252,12,12,15,145,73,197,72,70,3,132,195,65,62,126,237,117,220,116,243,45,24,
76,70,78,157,106,226,137,141,207,16,141,71,41,41,45,67,171,168,88,116,90,66,209,40,169,84,146,100,50,1,50,136,146,22,132,179,35,182,40,128,12,3,103,39,56,58,189,14,4,40,40,40,100,243,166,205,252,248,254,
31,243,133,111,124,17,100,248,205,175,158,101,199,142,157,120,189,62,146,169,36,209,120,8,247,216,0,170,18,163,162,188,144,154,105,149,212,79,169,38,199,145,75,50,153,96,176,175,15,103,78,14,54,155,157,
68,44,68,73,81,49,46,167,19,173,70,36,156,17,177,230,216,201,164,101,244,38,61,138,44,163,215,25,168,169,169,193,86,88,242,231,172,144,158,54,254,240,187,223,211,219,211,139,116,214,165,165,215,232,208,
136,226,120,192,86,5,37,147,66,107,146,48,232,245,248,253,126,164,179,41,106,153,140,76,52,26,197,104,52,144,74,37,233,244,120,249,200,245,215,240,165,207,125,131,159,252,244,126,254,229,95,127,64,60,
150,198,108,114,224,114,22,34,85,150,22,253,171,78,146,16,4,17,189,193,128,78,59,110,2,166,229,52,130,70,196,100,52,34,136,26,142,159,56,65,50,153,164,188,188,146,185,115,231,129,164,193,227,243,209,211,
63,200,142,157,187,233,233,232,97,176,167,151,150,214,14,6,7,251,240,142,142,178,96,238,28,238,251,183,127,229,115,159,250,36,171,87,95,193,152,103,140,131,7,15,17,10,133,48,155,173,68,66,49,82,233,52,
137,68,130,145,17,55,141,39,78,32,42,240,169,79,125,130,127,184,231,171,220,117,231,6,234,166,213,226,25,30,228,68,227,49,78,159,106,164,179,189,141,17,119,63,127,124,106,35,207,191,240,2,149,21,21,252,
243,119,191,203,156,57,115,169,153,59,143,185,117,117,244,118,117,177,101,219,171,184,71,253,140,141,249,24,24,28,96,104,216,77,58,3,67,131,110,218,59,187,184,246,218,235,249,210,151,190,140,201,98,166,
184,184,144,133,139,231,211,219,118,134,99,135,14,208,219,221,201,224,64,31,238,145,81,78,159,57,131,40,10,252,227,183,190,206,223,223,125,59,22,147,22,171,81,199,236,186,25,36,194,9,90,79,119,96,55,230,
33,102,116,72,130,30,73,167,130,144,65,85,69,204,22,51,95,249,242,215,152,49,125,58,169,84,130,210,252,66,170,202,203,240,249,188,252,254,119,143,210,213,221,79,107,123,15,125,131,195,204,154,59,159,210,
226,82,46,95,190,2,17,129,99,135,142,17,242,7,48,219,204,140,121,198,8,248,199,125,98,6,163,14,147,209,128,172,202,100,50,41,4,65,69,103,48,112,217,202,43,9,133,195,28,61,214,192,192,192,0,83,167,214,
50,232,118,19,142,132,145,52,90,124,30,15,62,95,140,88,52,198,130,57,11,88,255,241,27,240,12,15,115,178,225,4,222,145,81,68,85,161,171,179,139,158,142,78,140,146,134,100,38,133,70,175,1,73,34,153,76,146,
150,51,24,109,22,110,190,249,102,204,38,51,219,94,123,13,191,123,20,167,211,201,208,208,48,167,78,157,34,147,201,80,83,83,131,223,239,199,237,30,97,70,221,12,110,220,176,129,190,254,94,94,125,117,11,35,
67,131,228,57,114,233,236,232,194,59,230,197,238,176,35,74,26,4,68,156,5,121,88,172,22,220,238,17,22,206,91,192,79,127,250,19,134,7,7,232,232,104,35,149,202,96,119,216,105,111,111,103,160,127,144,209,
17,15,201,100,154,72,56,206,160,167,151,181,31,189,154,47,126,241,11,68,99,97,60,158,17,130,193,16,94,143,159,214,214,22,82,201,36,161,80,12,69,86,144,5,137,104,52,129,209,100,198,235,15,145,99,54,243,
224,3,15,48,123,222,60,44,54,27,85,85,213,164,100,133,93,187,118,19,138,132,73,36,83,140,122,189,184,221,110,42,74,74,41,41,46,102,213,170,143,80,88,232,98,212,237,198,100,53,226,30,117,211,218,214,134,
222,160,67,163,136,152,173,22,244,90,29,233,76,230,236,192,22,70,81,84,86,92,177,146,53,171,174,196,85,94,134,203,229,164,187,171,155,112,40,130,215,31,228,153,23,54,113,250,116,11,39,78,52,145,136,39,
144,5,129,219,110,189,145,143,173,93,131,171,160,128,234,169,213,244,246,244,240,234,214,173,152,205,102,210,169,52,162,32,50,54,226,195,235,245,163,202,41,252,99,99,196,195,65,86,175,186,130,127,255,
151,239,177,97,253,117,204,159,59,135,225,254,1,218,78,55,16,15,141,209,217,218,74,115,115,19,7,14,29,226,133,77,155,216,250,218,110,42,166,76,225,222,127,251,1,55,223,186,129,178,226,10,154,155,154,241,
249,253,104,244,122,100,89,197,96,52,35,74,34,162,36,33,138,18,70,157,129,131,71,143,80,53,109,42,159,249,220,231,184,227,147,159,100,218,140,90,226,201,4,205,109,103,56,121,170,137,72,52,74,95,239,0,
29,205,237,156,58,211,200,235,71,118,50,20,238,163,110,73,45,139,150,207,35,16,14,113,244,80,35,238,46,47,123,119,31,228,208,129,195,28,61,212,64,115,243,25,124,163,126,2,62,63,241,80,28,247,240,8,135,
15,30,230,248,209,227,116,244,245,48,234,241,98,181,153,199,3,136,130,128,36,138,216,237,54,140,122,29,114,58,65,195,193,131,252,238,55,15,178,255,224,1,210,233,12,70,189,30,187,221,134,70,148,16,16,80,
84,5,20,133,84,42,133,168,17,73,166,211,100,50,50,57,57,185,248,2,1,100,89,70,148,52,136,146,134,120,60,129,209,110,229,147,119,127,150,28,135,139,156,28,27,141,13,39,232,234,108,35,153,76,82,148,95,140,
230,59,223,254,54,47,109,126,137,182,51,173,8,128,172,55,160,215,106,208,162,195,96,179,17,14,5,9,135,252,56,236,78,238,254,204,103,168,157,49,29,103,89,25,145,49,47,175,109,223,206,206,61,123,217,178,
245,85,94,121,117,43,51,103,206,38,18,142,112,178,165,153,127,250,246,63,114,253,199,63,78,81,65,30,185,57,118,138,202,47,33,26,13,211,122,166,141,238,158,30,66,161,8,99,163,1,36,73,139,65,63,62,139,141,
39,98,220,121,251,173,220,120,205,199,24,232,57,3,233,16,213,165,101,172,94,121,9,135,246,239,192,105,209,145,12,166,209,107,96,200,27,64,175,213,113,233,101,151,115,226,100,19,7,246,61,72,73,73,49,203,
47,89,78,93,125,61,21,21,21,12,187,195,104,116,90,236,57,102,68,73,67,52,154,64,21,68,242,11,139,41,40,42,230,231,255,243,43,26,154,142,145,151,103,99,221,154,213,216,236,102,244,122,45,117,211,166,225,
143,70,137,133,130,232,4,145,52,96,209,235,248,175,31,254,27,189,125,61,164,82,41,74,10,203,112,230,230,147,137,43,72,86,129,140,2,201,120,2,173,217,74,60,153,65,210,104,209,138,48,216,51,202,182,77,91,
241,122,135,209,100,50,212,84,151,35,136,18,138,198,204,72,76,70,78,171,148,86,215,225,42,40,33,145,202,176,245,149,87,233,238,238,34,28,14,49,54,226,166,122,122,13,1,191,143,188,124,23,11,231,205,39,
16,8,96,208,72,8,178,130,154,201,144,145,211,164,100,129,103,54,62,73,79,119,55,94,143,151,225,209,17,46,95,190,28,159,207,143,94,171,101,233,188,133,12,117,245,226,112,22,32,138,26,196,84,154,167,30,
121,140,206,174,110,116,58,45,169,84,10,171,213,74,111,119,23,162,40,225,168,168,194,98,179,82,92,90,74,58,147,166,189,167,7,175,223,135,78,167,225,208,254,131,156,110,61,67,95,79,47,177,104,148,89,179,
103,17,12,134,8,133,66,232,245,122,6,7,6,113,230,229,17,137,70,49,24,141,236,120,109,27,7,143,28,194,239,29,35,157,148,41,43,171,100,239,158,67,84,87,78,65,21,37,20,141,192,236,37,243,9,135,67,12,14,14,
97,49,155,49,26,205,252,225,209,199,217,187,111,55,62,223,24,162,6,170,42,43,105,108,104,0,85,36,47,207,137,34,11,164,211,73,44,186,92,100,57,195,163,143,60,202,192,112,47,253,131,157,152,77,102,68,65,
79,111,79,15,38,147,21,73,163,65,22,181,136,130,6,65,103,68,145,140,248,227,99,172,190,100,49,123,15,30,164,185,229,12,167,154,78,82,87,95,143,86,171,35,165,168,8,138,64,50,173,144,74,101,88,182,100,49,
70,131,158,88,36,202,211,79,62,73,119,95,15,138,156,166,178,170,140,211,103,154,241,140,141,113,219,134,91,48,8,194,196,13,7,162,36,33,8,2,241,88,12,187,195,129,223,231,227,23,15,252,138,174,190,30,10,
74,139,216,179,119,47,178,160,97,254,156,121,204,153,94,75,82,81,49,152,173,152,77,86,150,93,178,140,160,47,192,79,238,191,31,207,216,40,181,211,102,112,96,223,235,196,34,17,130,129,32,137,100,18,147,
209,132,197,108,194,100,177,162,145,52,140,142,142,114,197,242,165,124,230,83,119,224,31,29,166,171,229,52,170,160,146,73,132,201,164,18,32,171,20,228,23,160,213,24,233,239,234,101,112,104,152,91,111,
255,4,159,191,227,118,226,195,125,156,234,239,166,111,160,23,247,64,23,157,157,157,204,156,89,79,44,236,35,163,211,162,17,5,146,137,20,118,135,141,67,251,247,81,89,51,149,127,248,214,55,40,42,42,36,55,
55,151,112,44,72,255,80,63,5,69,46,58,90,219,248,229,47,255,151,41,229,85,168,113,13,123,26,246,50,103,222,92,254,237,63,254,133,69,151,46,196,108,52,241,135,223,61,193,79,135,3,36,3,105,114,242,92,100,
148,52,201,100,18,148,12,157,3,110,250,135,70,81,149,52,62,223,24,139,22,45,228,170,53,31,37,146,136,240,228,51,207,112,244,248,49,102,214,205,196,102,183,97,54,153,121,238,185,231,73,167,51,88,44,22,
246,29,216,135,211,153,195,231,63,243,25,68,81,226,165,23,55,19,137,68,49,232,116,8,50,104,36,9,73,35,34,72,18,201,84,140,220,28,7,105,131,137,254,193,65,198,60,94,92,206,60,204,22,43,145,104,28,163,209,
138,162,42,116,182,118,48,165,114,58,211,107,235,88,177,124,57,237,205,109,204,155,183,144,142,246,110,52,83,235,166,179,50,153,192,231,243,145,74,165,144,227,17,172,182,66,244,146,134,112,34,1,162,22,
127,56,194,140,233,211,209,155,204,108,127,109,7,121,121,121,204,153,51,151,162,146,18,156,121,5,212,213,207,166,233,228,9,134,135,134,200,164,210,148,228,57,153,94,91,195,161,253,175,115,96,255,1,28,
14,43,181,115,103,162,168,10,122,189,142,220,156,92,52,146,150,197,139,23,147,201,40,248,253,126,60,99,94,12,58,13,129,177,1,126,247,203,255,102,199,206,29,152,204,102,102,214,215,51,103,246,108,194,158,
97,114,173,38,220,114,138,84,44,134,51,215,137,70,144,104,107,61,195,47,127,250,83,180,146,150,177,209,81,138,11,10,113,21,20,48,212,223,143,206,148,143,164,211,80,85,61,5,87,158,147,227,199,143,19,14,
4,144,132,52,155,95,126,129,195,71,14,145,99,181,145,74,70,121,122,227,227,44,89,184,136,206,222,97,10,11,74,136,69,163,8,26,133,72,44,204,130,250,69,108,223,188,137,174,158,99,20,151,150,209,219,213,
79,75,83,39,87,172,184,18,57,173,142,143,100,168,232,117,26,100,4,116,122,39,30,207,48,51,106,171,233,104,239,97,239,158,3,148,20,229,48,56,208,71,115,75,11,215,94,179,22,139,213,66,50,45,163,211,106,
40,46,45,37,22,143,99,54,25,241,120,195,12,12,246,83,84,84,132,65,111,196,168,213,83,58,189,142,112,36,130,22,9,53,163,144,140,165,64,5,189,164,37,153,84,176,232,180,28,63,121,138,150,211,45,212,214,76,
101,48,145,34,30,10,147,107,179,227,25,27,163,172,168,152,217,245,245,12,13,140,96,178,90,177,24,77,116,181,119,210,209,214,202,244,233,211,233,235,232,96,222,130,5,212,78,173,165,175,171,11,85,146,72,
169,10,41,65,5,141,68,90,201,32,8,2,38,163,145,163,199,142,209,220,220,204,140,25,51,72,36,226,227,65,61,189,30,163,201,136,217,108,97,96,160,31,87,190,11,157,86,75,97,126,1,167,79,54,19,10,248,209,74,
26,122,135,250,152,61,123,30,215,92,179,142,198,99,141,100,144,137,198,19,36,18,113,12,6,35,145,112,4,189,222,128,44,103,120,228,225,135,16,68,133,140,156,60,43,220,58,170,107,106,232,108,239,65,163,209,
144,146,199,163,241,138,34,163,211,233,104,60,113,130,96,200,139,35,215,66,87,103,7,139,23,45,195,98,174,163,175,119,8,245,141,252,100,141,22,65,171,18,77,201,40,26,29,246,220,124,254,244,252,38,252,1,
31,163,99,94,210,25,153,101,75,151,81,89,89,69,95,255,0,26,173,14,187,67,71,142,221,65,216,31,98,36,30,163,165,181,25,175,111,20,151,43,15,139,221,140,217,106,165,119,104,128,158,190,110,230,78,153,65,
44,26,71,206,100,48,24,244,232,13,70,84,85,165,189,189,141,109,219,182,209,218,122,6,147,213,202,212,153,181,116,117,116,146,86,96,102,253,76,102,212,213,113,164,161,17,135,94,79,36,18,230,232,209,99,
156,57,9,253,189,29,128,192,153,51,29,184,221,227,233,98,174,188,0,146,168,197,234,180,81,80,224,34,20,140,224,11,120,9,122,135,137,133,253,252,233,201,141,28,61,126,148,225,225,33,92,78,39,3,3,3,164,
101,5,141,198,76,58,109,64,35,233,177,26,45,212,150,155,112,25,13,188,240,216,163,28,57,114,24,187,195,142,193,104,164,181,171,139,225,161,33,166,85,87,226,114,216,48,24,141,88,173,86,130,193,32,177,88,
12,157,78,98,237,154,171,240,142,140,240,242,139,47,18,9,135,72,36,146,244,181,117,82,104,119,98,170,157,193,208,240,48,81,127,136,161,126,15,78,173,131,143,175,189,134,124,71,46,207,60,250,56,170,42,
208,221,218,3,233,12,146,172,96,50,218,8,42,105,210,74,20,45,227,217,34,73,57,73,208,31,225,210,229,43,249,175,31,254,144,153,115,230,208,112,236,32,175,236,216,65,115,211,105,68,65,194,108,182,160,168,
10,123,94,223,131,213,98,161,188,188,138,169,213,181,220,253,169,59,89,124,197,101,156,62,120,152,64,48,64,79,183,159,25,83,167,33,73,34,146,100,68,175,215,161,211,233,241,71,20,34,177,20,195,238,65,64,
228,174,79,223,205,37,203,46,161,169,233,36,143,63,254,4,99,195,67,36,50,42,95,249,251,47,113,217,138,167,41,43,43,231,244,201,211,228,229,218,25,236,239,97,205,154,21,72,65,207,200,191,38,146,73,154,
154,78,145,159,231,36,18,139,146,150,101,244,6,35,190,80,24,81,146,240,135,66,248,124,62,182,108,221,202,99,143,63,193,83,79,63,67,99,99,35,221,221,221,180,117,116,82,84,92,138,172,40,12,14,13,98,208,
106,41,45,43,165,163,163,131,77,47,60,79,60,22,166,229,76,51,143,62,241,52,241,100,148,246,182,118,84,89,198,108,178,50,181,122,42,5,5,133,132,195,17,70,71,70,209,10,128,146,102,203,230,77,152,12,6,60,
163,163,236,60,120,16,163,86,203,240,224,32,38,163,9,65,5,157,65,79,40,224,163,170,178,2,139,209,200,145,195,135,41,43,43,163,175,175,143,154,105,83,185,236,178,75,241,6,2,4,252,99,152,141,38,98,145,0,
137,68,140,76,58,201,136,123,136,186,250,58,156,118,43,77,103,78,82,148,151,79,34,21,103,218,180,105,92,123,253,13,100,50,42,94,95,24,85,16,113,230,184,232,243,244,112,211,181,55,179,244,146,133,12,14,
118,211,219,211,143,70,163,229,163,107,174,226,170,143,174,195,237,30,37,16,8,17,140,68,208,136,34,241,116,10,163,197,192,200,216,32,107,62,178,146,53,171,87,177,237,213,173,36,146,49,92,5,46,110,88,255,
113,110,184,225,6,78,119,116,19,142,36,81,5,88,182,108,41,102,179,137,105,213,213,84,79,171,166,167,167,139,206,142,14,34,177,40,247,252,253,23,153,57,163,142,104,40,50,158,117,160,209,161,100,20,52,162,
22,131,206,8,138,66,65,126,17,165,69,37,184,7,7,73,36,18,84,149,150,115,199,109,183,177,112,222,60,70,134,221,204,172,171,39,228,15,160,160,65,175,213,176,116,209,18,46,89,178,4,175,215,199,152,123,20,
73,148,184,253,214,91,89,186,104,9,131,195,195,8,58,13,190,112,8,89,78,211,213,223,11,170,74,42,157,102,233,146,197,204,158,51,135,19,13,13,200,233,52,102,179,149,27,110,248,56,53,53,53,12,14,14,98,183,
219,80,100,133,188,124,23,161,96,144,181,235,174,102,209,252,185,184,221,195,120,199,60,44,88,176,128,79,223,245,105,138,139,75,233,25,24,36,163,170,4,195,33,252,225,48,30,143,23,57,157,70,163,145,184,
245,182,219,64,148,233,237,237,69,150,51,148,151,149,114,229,170,143,176,120,241,98,134,135,135,49,153,173,104,52,6,244,58,51,138,170,114,207,87,191,74,105,105,41,39,78,157,32,28,14,96,183,153,248,212,
29,159,194,149,95,192,224,240,48,193,112,12,68,13,233,244,184,112,202,130,6,131,209,198,29,183,109,32,149,8,211,209,209,78,158,51,151,249,139,22,115,221,181,215,97,50,155,104,109,107,195,225,112,16,139,
71,185,226,210,203,209,105,37,166,86,79,69,149,20,134,7,6,209,234,52,76,169,170,228,178,203,151,35,0,90,81,194,101,207,67,119,214,231,169,10,226,248,141,37,146,132,201,108,198,227,247,50,224,30,194,85,
80,192,178,101,203,89,176,96,41,153,140,138,211,154,67,253,172,89,116,181,119,51,111,70,61,195,189,253,204,153,49,131,112,56,194,169,198,211,148,20,85,80,81,84,202,162,249,75,200,164,51,132,252,33,44,
102,11,35,131,35,232,245,90,20,69,70,149,83,36,227,49,92,121,78,94,125,245,21,130,126,31,213,213,213,184,242,156,84,85,85,48,52,56,66,90,249,255,218,123,243,40,57,142,251,206,243,27,17,153,89,85,93,125,
163,187,113,223,0,9,2,36,68,145,148,72,81,18,15,241,16,37,155,22,101,123,61,146,111,174,53,99,191,25,207,202,151,252,118,103,222,204,202,111,252,118,223,190,55,26,217,94,31,51,107,251,217,179,246,236,
174,189,150,188,150,100,203,178,45,74,150,76,73,20,197,251,0,72,220,141,6,208,141,110,244,85,93,87,102,70,196,254,17,153,89,89,213,213,64,3,108,138,128,240,253,240,53,27,221,93,149,149,153,85,249,201,
95,252,34,226,23,174,233,173,77,140,129,193,126,12,12,244,65,2,120,234,155,223,192,161,87,15,97,215,174,93,216,188,121,51,234,97,136,241,241,113,244,13,14,186,155,98,169,132,13,155,54,193,15,2,44,44,44,
96,124,98,2,253,189,125,120,226,31,158,192,87,191,252,4,158,123,230,89,60,253,212,183,49,113,106,28,81,163,129,158,160,136,202,226,34,202,65,1,210,4,88,168,44,160,228,123,248,234,87,190,140,23,95,124,
30,23,206,157,71,201,43,192,132,6,243,23,230,81,139,12,180,95,68,12,129,72,3,133,82,15,164,242,17,65,224,67,143,254,32,172,148,248,173,255,253,119,240,185,47,124,30,199,94,59,12,33,4,102,102,102,209,108,
134,56,63,121,30,147,147,83,184,249,150,183,161,183,220,135,247,189,239,33,76,157,63,139,175,252,221,23,241,196,19,95,193,107,175,30,198,115,47,190,130,114,49,192,182,173,219,17,135,33,194,48,196,186,
209,17,84,106,117,68,214,226,236,228,52,30,253,208,135,112,255,3,15,96,102,102,22,223,124,234,105,124,237,235,79,194,66,98,211,198,205,120,246,229,23,112,248,240,107,56,114,232,48,142,188,126,24,39,78,
79,224,253,15,220,135,255,237,127,249,117,120,255,245,79,254,20,7,246,239,67,88,111,98,211,198,13,40,245,244,32,8,124,52,194,16,158,31,64,249,62,162,216,192,239,41,224,217,103,95,64,80,10,48,61,63,143,
191,125,226,9,124,224,161,135,48,191,176,132,157,187,118,227,214,183,221,130,165,165,57,76,156,62,141,245,235,199,176,99,219,86,156,60,113,20,23,102,231,32,37,240,246,155,14,224,241,143,254,52,254,230,
139,95,196,43,175,28,66,92,143,241,210,11,207,163,167,84,68,20,25,244,120,2,99,235,199,240,161,15,255,16,166,38,167,113,122,98,2,81,20,225,182,155,110,197,47,255,210,175,226,83,159,254,52,234,181,58,170,
245,24,22,33,132,177,216,178,113,51,62,246,248,207,96,252,228,56,142,30,57,130,77,27,55,226,225,135,31,198,77,251,246,97,98,226,12,140,1,78,159,58,11,79,74,204,92,152,65,20,70,40,151,203,216,191,111,31,
30,126,248,97,204,206,207,98,242,236,121,220,114,240,32,126,224,209,71,113,243,254,91,112,228,245,163,136,34,139,227,71,143,67,5,62,122,49,136,227,39,142,227,151,126,233,95,161,220,103,241,167,255,215,
255,141,221,59,246,224,7,30,251,48,172,145,88,170,87,49,126,230,52,66,104,244,23,250,49,215,172,32,152,15,96,80,193,235,71,143,226,95,255,252,207,225,223,253,218,39,113,230,244,113,140,141,12,225,29,239,
124,59,166,207,207,96,169,209,196,216,198,81,156,57,123,22,181,176,137,219,223,118,0,245,90,13,183,238,222,135,159,248,201,159,198,51,207,124,7,119,222,118,27,182,109,216,140,115,103,206,161,167,88,70,
101,113,9,190,239,161,89,107,66,23,44,76,100,81,175,187,15,196,187,238,126,23,246,31,188,25,211,231,103,208,87,46,97,247,190,125,120,246,217,103,49,52,50,130,98,111,25,115,213,37,156,159,57,143,161,193,
33,124,235,219,79,225,215,62,249,107,216,176,113,3,198,199,79,3,0,118,238,218,137,147,227,227,80,190,194,228,220,44,206,206,76,225,220,133,105,12,13,14,193,247,36,22,42,11,56,126,226,36,254,229,207,189,
31,163,195,159,196,177,35,71,48,178,113,3,182,109,221,138,23,94,120,1,82,73,148,74,61,208,58,70,28,69,240,60,15,199,142,30,193,227,143,255,56,250,251,202,152,159,155,195,246,157,59,97,165,135,153,153,
25,156,58,53,142,11,115,115,80,133,2,224,251,104,46,86,16,72,137,215,207,142,227,216,209,35,248,197,95,248,5,220,124,243,1,204,94,152,194,142,221,187,176,115,199,54,28,122,237,48,122,123,123,177,184,88,
67,20,54,1,235,195,83,10,141,102,3,31,248,192,7,80,40,73,76,79,159,197,174,93,219,176,109,195,38,28,59,113,2,245,122,19,147,103,39,81,238,31,2,100,1,22,18,75,75,139,208,181,26,38,38,38,240,145,31,251,
8,238,122,247,157,136,35,141,77,155,54,98,243,166,141,120,246,249,239,64,40,1,43,45,150,106,85,12,13,151,161,80,199,222,61,155,240,238,247,220,138,61,219,55,227,204,185,9,188,227,157,239,192,250,177,49,
156,24,24,194,64,223,0,180,210,136,173,107,234,151,74,69,44,86,42,144,158,194,193,91,111,197,230,221,219,176,109,239,118,20,131,94,108,218,184,19,235,214,173,67,216,52,240,125,31,186,97,208,91,44,193,
104,131,45,91,54,227,193,7,30,192,220,220,28,230,102,102,113,102,124,28,247,221,115,15,238,187,247,94,156,61,123,22,181,106,13,189,189,189,152,158,58,143,153,153,89,244,246,246,64,42,96,108,227,70,220,
119,255,253,232,27,24,192,183,191,245,45,140,172,27,198,158,61,123,177,255,166,253,152,173,212,112,238,252,2,162,88,99,118,122,26,189,125,3,24,93,55,128,251,239,191,23,82,89,28,61,126,12,213,122,13,219,
247,236,198,134,29,219,49,51,59,139,160,80,192,192,224,32,22,107,75,56,61,113,26,38,214,240,130,0,253,3,253,104,214,27,56,242,210,203,216,176,126,3,110,123,232,97,72,33,113,246,204,25,188,250,234,33,20,
188,0,67,229,62,4,158,143,243,213,121,236,216,180,13,55,221,112,35,190,248,165,207,99,227,230,81,108,25,30,197,200,200,24,122,14,148,81,153,169,225,212,244,12,68,185,15,86,120,136,224,62,211,74,72,64,
40,60,255,234,203,248,203,207,127,30,211,231,167,176,121,108,24,91,182,237,68,173,90,195,225,215,94,131,148,62,230,23,42,40,150,122,49,208,63,140,243,231,207,227,179,159,253,255,48,53,121,28,81,88,199,
182,173,219,112,251,237,111,199,226,194,60,158,121,238,57,220,176,123,47,138,133,2,206,78,156,193,185,115,147,88,191,109,27,172,16,8,138,37,132,97,140,223,248,244,111,225,217,231,158,195,203,47,191,140,
51,243,243,24,233,233,65,108,129,59,111,123,39,14,189,250,42,116,232,134,103,237,221,125,3,238,191,247,221,248,167,175,127,5,234,158,187,238,248,228,39,126,229,19,88,90,92,132,239,249,240,3,31,74,73,212,
106,21,64,74,88,19,195,23,2,239,127,232,1,156,56,117,20,211,147,231,224,217,24,63,254,207,126,24,143,255,212,79,34,138,26,128,53,216,184,113,61,14,31,62,140,190,222,18,70,199,70,240,161,199,30,67,111,
111,15,38,167,166,176,105,243,102,124,236,103,62,134,155,110,60,128,83,39,198,49,117,110,18,243,115,179,88,156,95,192,228,228,20,230,231,231,16,70,33,162,48,196,191,248,153,143,225,237,183,223,129,165,
106,21,183,28,124,27,126,236,199,126,20,163,35,35,248,199,175,125,29,67,131,131,152,58,127,30,214,198,40,245,148,48,57,57,137,187,239,190,27,239,125,239,123,113,224,224,45,120,240,193,7,113,240,224,65,
76,76,156,198,83,223,249,14,198,199,199,97,173,192,250,141,155,80,44,21,1,41,177,176,176,128,179,103,207,226,190,251,239,195,99,143,125,24,55,29,184,9,119,191,235,93,216,127,96,63,94,61,124,24,47,188,
244,18,164,244,221,208,12,33,48,182,126,61,190,245,212,119,176,113,203,122,220,122,219,65,188,235,174,119,225,222,251,31,128,242,2,124,229,107,95,199,179,207,63,15,173,53,246,239,59,128,247,222,127,47,
110,189,229,32,110,184,241,6,140,173,219,128,167,159,254,22,198,214,143,226,238,187,239,198,254,155,111,194,230,109,91,113,126,122,22,95,254,218,63,226,200,241,147,232,237,31,192,204,204,52,46,204,206,
226,182,219,223,142,165,234,18,26,97,3,3,253,189,184,241,166,27,177,126,195,6,204,207,204,163,209,136,224,23,75,88,191,113,19,246,31,216,143,247,222,119,63,110,190,249,109,216,180,101,43,134,134,215,33,
22,2,141,184,137,254,161,65,244,15,15,160,80,46,227,228,248,73,204,46,204,99,223,129,253,56,63,55,131,127,252,167,175,225,149,87,15,225,206,119,222,137,165,122,13,139,231,216,208,3,0,0,32,0,73,68,65,84,
75,139,24,25,27,195,182,29,219,1,165,112,98,124,28,47,190,252,18,102,231,231,80,28,234,199,15,127,228,71,240,192,131,15,226,190,251,238,197,150,45,91,81,44,148,112,242,196,113,68,205,16,59,182,239,192,
254,3,251,209,63,56,128,215,94,123,29,39,79,28,71,189,222,64,189,94,199,82,165,2,207,243,49,56,56,136,185,185,121,52,27,53,12,15,14,96,108,253,122,44,44,46,226,204,217,179,56,114,244,4,206,76,158,197,
93,239,126,55,126,252,39,126,18,31,252,254,15,226,209,239,255,62,220,188,255,0,124,47,192,115,207,61,135,209,177,49,220,126,251,109,216,181,107,59,198,70,198,112,252,248,113,60,245,173,167,16,133,17,170,
213,26,102,102,102,33,32,96,45,112,126,122,10,235,215,143,96,255,77,123,177,109,199,86,140,142,142,96,226,220,57,60,247,210,139,56,55,53,133,27,15,220,128,239,255,190,71,240,158,123,222,137,187,238,56,
136,93,219,71,96,108,29,207,63,251,36,14,30,216,135,123,223,251,110,244,247,245,162,84,80,56,114,228,53,124,254,11,95,192,208,64,47,6,250,203,56,119,238,12,54,142,14,224,198,27,118,224,204,153,113,244,
150,75,120,251,173,55,99,239,222,61,40,23,138,152,159,155,67,181,82,193,166,77,155,17,20,10,232,235,239,71,80,8,80,40,22,33,164,64,189,86,69,169,167,7,219,182,110,197,142,237,59,176,115,199,110,140,172,
27,195,196,217,115,168,215,107,216,184,105,19,250,250,122,241,173,167,190,13,229,251,136,181,70,111,127,31,238,188,243,46,28,60,120,16,183,191,243,157,120,231,157,119,98,234,252,20,190,253,204,211,80,
126,128,153,11,23,0,79,33,40,248,128,114,181,19,230,102,103,177,123,207,30,60,240,208,131,24,30,25,193,224,208,176,155,15,46,128,99,39,78,64,5,61,104,70,77,44,46,86,176,99,231,54,192,90,60,242,129,71,
112,247,221,119,225,194,220,44,202,165,18,246,238,187,17,125,3,253,184,48,63,135,117,195,195,40,246,148,48,55,191,128,102,179,137,70,179,137,161,117,67,240,60,15,63,248,161,31,196,82,165,138,201,201,73,
108,92,191,1,59,118,238,196,182,109,219,16,71,33,74,165,18,180,209,48,218,66,21,75,232,237,237,195,191,249,159,126,21,219,183,110,66,216,168,97,235,150,205,24,27,221,128,173,219,119,97,106,118,14,227,
147,147,104,66,34,210,218,245,132,235,24,205,102,13,163,35,35,120,240,125,15,224,208,171,175,32,14,27,120,248,193,7,112,243,77,251,48,60,50,138,147,199,79,34,240,139,208,218,96,223,141,55,97,211,198,205,
40,149,74,216,189,107,47,78,78,28,197,182,173,91,113,243,77,251,49,186,110,20,163,99,99,248,230,243,47,225,150,27,247,98,120,120,29,188,100,38,158,150,62,230,230,231,81,173,57,25,127,246,47,255,18,205,
40,194,240,240,48,246,238,220,137,90,189,142,197,74,5,59,119,236,70,117,169,130,56,142,225,41,133,82,161,128,169,169,243,248,210,223,125,17,222,199,30,255,41,172,27,236,199,141,55,238,198,161,87,15,97,
180,52,10,35,12,22,151,22,97,244,60,182,109,219,134,51,19,23,80,44,41,252,143,159,248,69,124,243,201,111,162,84,42,225,222,251,238,67,101,105,9,165,98,17,189,253,3,48,198,64,73,160,111,104,24,19,19,19,
56,125,234,20,62,250,209,143,226,174,187,222,5,33,36,148,242,241,79,79,254,19,162,40,66,177,167,132,177,177,245,56,248,182,131,48,198,32,54,26,103,38,38,240,244,211,207,224,247,254,224,247,241,137,95,
249,101,124,242,215,62,137,102,179,137,102,189,129,191,252,252,231,176,184,84,65,108,99,204,205,207,162,214,168,226,134,27,119,99,122,122,26,127,248,199,127,140,143,126,228,71,176,107,231,46,23,237,156,
56,129,103,159,127,30,202,15,48,186,126,19,62,244,161,199,112,251,237,183,193,90,139,40,54,120,249,165,23,241,183,95,250,18,126,231,247,255,11,30,126,240,33,140,142,142,161,218,172,225,107,223,120,18,
135,15,29,130,10,124,76,157,157,65,181,209,64,28,89,12,141,12,195,194,224,83,159,254,77,124,240,240,189,216,184,121,35,172,21,152,60,59,133,215,143,158,68,101,105,1,119,190,251,157,248,245,95,255,95,177,
255,166,61,104,54,1,207,3,38,207,157,199,191,255,228,191,197,111,255,238,111,227,235,223,248,26,182,110,219,130,216,106,28,61,246,58,166,38,167,225,21,139,56,116,228,117,76,157,57,131,115,147,147,248,
218,147,79,226,209,71,30,134,142,155,184,176,184,0,185,228,46,138,234,98,13,129,240,49,91,89,194,238,61,123,240,193,143,252,24,16,120,128,182,128,53,56,117,248,117,124,251,185,239,224,212,153,227,152,
62,81,65,79,185,8,64,193,10,131,93,7,110,192,185,201,73,124,246,243,159,195,137,115,103,80,28,236,195,203,71,14,99,199,142,29,56,54,62,142,227,103,198,49,216,63,136,216,196,152,158,190,128,169,153,243,
152,154,58,143,31,249,233,31,195,63,255,185,159,69,201,11,178,194,23,71,94,63,130,63,248,157,223,197,95,127,225,139,120,230,59,207,98,239,158,221,152,159,95,192,252,82,5,190,31,192,90,139,51,167,39,208,
83,46,35,140,154,128,16,48,58,198,115,207,191,128,241,227,199,176,113,203,38,188,126,236,24,32,60,156,159,155,67,185,175,23,63,244,131,31,198,127,247,195,143,181,230,104,87,66,60,240,190,7,240,111,254,
237,175,226,15,126,255,63,227,109,183,222,138,209,209,17,232,56,196,228,212,52,180,209,168,84,234,56,114,228,40,230,231,23,48,178,110,20,165,98,128,195,135,159,195,31,253,241,2,110,190,249,102,12,175,
27,70,189,94,195,161,163,71,48,62,62,142,158,190,34,254,135,159,255,89,60,246,225,15,187,89,119,245,58,162,40,196,151,191,252,4,126,227,63,253,39,252,31,191,255,159,241,202,43,47,99,227,198,13,56,124,
248,48,142,29,59,134,217,11,23,220,156,119,223,245,210,254,227,215,190,138,3,251,118,97,104,221,58,28,59,126,12,83,231,167,33,165,68,24,199,24,236,239,195,45,183,222,10,79,5,216,181,107,23,118,236,218,
9,41,36,194,40,66,101,97,1,135,143,28,197,153,51,19,152,93,88,66,177,84,2,164,192,212,204,52,252,66,128,61,55,222,136,202,210,18,190,245,244,211,120,246,165,231,17,148,10,216,185,115,23,190,241,212,83,
40,244,244,96,235,150,45,24,29,29,193,153,201,115,56,61,49,129,114,79,25,145,54,184,239,190,123,177,239,166,155,80,44,149,208,168,87,49,121,126,2,47,188,248,18,158,252,214,55,176,125,215,14,188,235,238,
119,161,90,173,162,86,171,226,165,151,95,134,82,18,165,82,1,86,204,194,11,124,196,198,160,216,91,196,23,190,248,215,248,129,71,63,128,143,255,226,47,160,90,169,160,17,133,120,242,91,223,68,185,92,134,
129,197,107,199,142,96,251,214,173,152,91,92,196,96,255,0,166,166,103,48,183,180,132,179,231,39,241,223,127,236,103,48,55,59,7,11,11,41,5,38,78,159,65,223,208,16,66,99,208,104,134,168,84,42,24,221,182,
7,175,30,62,138,175,126,243,159,240,200,67,247,99,203,214,13,88,90,170,96,195,198,237,56,124,244,36,100,185,0,89,42,160,50,59,7,223,11,32,16,67,73,96,97,118,6,125,5,133,247,220,125,23,14,238,219,131,47,
125,241,111,48,212,215,143,237,59,118,97,96,112,24,235,70,198,96,180,198,194,98,5,133,66,17,195,195,235,128,89,129,71,31,253,62,148,203,2,199,142,31,66,80,44,224,142,119,220,129,23,95,120,1,183,221,176,
27,61,165,18,22,22,230,33,148,132,48,18,94,169,128,250,5,141,193,161,97,236,185,225,6,140,159,62,3,72,129,7,30,126,63,214,141,140,224,51,159,249,12,78,28,63,129,77,155,54,98,177,178,136,227,199,142,162,
84,242,209,63,56,128,161,161,126,84,150,250,224,109,223,186,13,199,79,28,135,141,13,198,70,199,176,101,235,22,172,27,94,135,177,209,81,204,204,94,112,157,72,90,99,124,226,12,118,239,220,133,123,238,185,
31,61,189,46,17,254,242,171,175,98,253,134,13,104,132,49,254,225,75,95,194,220,194,162,27,204,93,46,227,207,63,251,89,156,24,31,199,45,7,111,129,167,60,156,61,51,133,103,158,121,30,51,179,23,224,121,62,
254,197,199,127,22,15,63,252,32,2,63,128,84,30,78,157,58,133,191,248,139,63,199,159,255,197,95,224,83,191,249,27,184,97,247,94,104,107,48,59,55,139,115,147,83,104,132,33,78,140,159,194,185,153,105,212,
116,8,117,242,52,202,61,69,28,58,244,58,62,245,233,223,197,173,183,30,68,28,71,152,190,112,1,147,231,166,0,107,176,121,203,86,60,240,240,131,184,249,214,91,97,155,33,12,44,110,190,229,0,164,175,240,255,
252,249,159,225,255,253,203,207,224,109,183,28,68,189,190,4,37,37,74,61,101,212,155,17,130,158,34,214,149,75,176,70,162,183,183,15,31,254,145,31,130,133,193,220,210,18,48,117,1,129,31,32,178,192,230,109,
155,209,51,208,135,125,251,247,163,127,176,140,165,70,3,141,90,3,190,144,24,30,236,195,7,30,121,4,65,49,128,244,125,20,10,5,72,79,97,104,116,20,99,27,55,160,94,15,177,56,191,128,98,161,8,19,135,144,194,
160,25,199,24,25,89,135,29,125,219,17,71,81,50,80,185,23,115,179,21,68,74,162,41,128,83,167,79,33,210,110,218,95,169,92,70,13,22,125,35,195,144,243,231,80,8,124,108,218,180,57,25,107,105,16,197,49,122,
227,16,15,124,223,35,120,228,7,62,232,114,184,199,198,177,126,211,6,12,245,15,32,138,53,34,29,193,15,92,9,182,180,224,203,190,155,15,224,232,201,147,16,214,194,151,110,46,190,110,134,184,231,254,251,177,
117,219,118,119,44,82,162,216,83,116,35,7,140,1,172,69,51,138,224,41,15,70,2,81,232,254,237,43,129,40,14,1,41,48,188,109,7,180,6,106,141,26,60,207,67,95,111,17,227,227,19,168,55,235,152,155,185,128,177,
117,35,168,55,22,240,190,7,238,195,109,183,221,10,63,240,81,40,20,161,148,196,246,29,123,208,211,83,194,236,236,44,238,121,239,189,232,237,43,163,25,134,152,60,123,14,197,98,9,190,239,193,88,131,165,74,
5,22,192,250,145,49,20,139,69,140,142,140,160,220,219,139,163,199,142,33,12,93,165,252,161,193,65,140,142,142,226,158,123,239,197,235,135,14,99,97,97,30,165,98,1,189,229,50,222,113,199,29,8,195,16,83,
231,207,195,24,131,59,110,191,3,11,51,231,241,220,11,47,227,161,135,30,198,232,232,122,156,59,127,30,67,189,125,8,23,23,112,244,248,73,84,171,53,52,195,16,27,54,109,66,172,1,207,19,8,10,37,108,216,212,
143,227,167,78,99,110,110,30,115,11,139,24,25,30,65,111,127,47,130,82,1,229,190,62,212,27,77,188,240,194,11,248,250,215,191,134,205,27,54,225,228,169,83,8,155,33,118,238,217,141,111,60,249,36,154,97,136,
205,155,55,98,105,169,134,133,165,5,156,157,56,135,245,99,35,248,103,63,250,17,28,188,251,78,160,17,3,194,96,113,110,6,127,253,55,95,192,23,254,250,139,248,175,127,242,39,216,177,99,7,132,148,104,52,106,
104,212,155,136,1,124,251,185,167,113,126,106,6,97,179,129,122,173,138,13,27,71,48,126,242,36,78,77,156,192,193,3,55,163,191,175,15,147,147,147,152,169,44,226,194,226,60,6,250,7,240,47,255,245,207,227,
189,247,220,139,102,163,142,165,165,37,76,159,159,198,223,252,237,95,227,51,159,255,28,38,207,93,192,109,111,127,27,170,213,58,166,102,166,113,228,181,215,176,80,93,132,245,20,172,39,17,73,139,160,175,
23,197,161,62,252,225,127,251,19,52,195,37,28,184,105,47,138,189,189,56,114,242,24,190,252,205,111,226,165,35,175,65,75,139,159,250,137,143,162,92,232,69,164,155,240,165,192,137,99,175,227,201,175,126,
21,127,241,223,254,20,191,242,75,191,136,219,110,222,143,249,249,57,188,126,228,40,78,28,63,142,56,138,176,110,221,40,106,213,42,206,76,156,197,67,15,61,132,249,249,5,156,61,59,137,247,188,231,30,220,
125,247,29,104,214,107,88,170,86,240,204,115,207,98,215,222,189,208,66,98,97,246,2,214,13,175,67,8,131,168,178,0,223,147,88,92,90,192,251,222,119,15,182,110,222,128,175,60,241,4,14,220,176,27,67,35,195,
24,232,45,98,108,116,8,91,182,109,193,87,255,241,9,12,12,15,98,106,114,18,119,189,123,39,126,242,39,127,2,47,191,252,42,196,31,255,214,167,108,80,8,160,163,8,181,102,19,239,184,253,14,28,184,229,32,130,
82,17,205,106,21,58,214,120,233,149,151,241,237,167,159,70,28,199,8,130,34,6,122,203,168,53,27,104,212,27,88,63,182,30,207,188,232,122,168,74,61,61,104,52,66,220,113,219,109,168,53,26,152,159,159,199,
134,141,27,176,126,116,12,75,181,58,230,230,22,16,54,67,108,220,184,1,31,255,248,199,241,142,59,110,71,181,86,135,82,18,214,88,252,253,151,255,30,159,251,171,207,97,122,102,22,91,183,110,194,192,192,32,
74,197,18,202,125,125,104,134,13,152,48,66,80,42,161,84,234,129,31,120,40,247,244,64,73,31,82,121,208,58,70,51,10,225,41,9,37,61,8,8,104,104,236,218,177,29,235,70,71,81,175,215,161,164,132,239,7,152,155,
159,199,236,220,28,140,53,8,27,77,244,148,11,240,3,31,2,10,144,18,190,215,3,171,45,96,5,130,66,17,129,95,4,20,80,40,40,52,155,13,52,27,13,4,65,128,158,222,94,212,150,150,16,233,24,125,189,125,104,132,
117,20,253,0,190,22,144,190,15,29,135,168,197,49,138,61,61,144,158,135,70,28,33,54,6,50,80,8,252,0,38,214,232,41,149,96,180,70,220,172,185,74,75,113,19,218,68,16,214,162,24,20,160,225,67,168,2,130,32,
64,179,209,196,133,11,211,110,48,185,144,240,125,31,158,239,3,210,32,70,136,40,142,96,211,121,213,201,116,208,82,79,47,4,4,226,88,163,88,40,0,145,133,0,80,107,52,80,8,124,212,235,13,20,139,69,68,81,148,
21,6,174,214,235,136,162,8,66,10,40,11,104,173,225,7,1,60,165,96,141,129,182,22,86,155,108,252,159,16,194,125,73,137,64,41,24,0,177,142,97,141,133,181,22,90,187,146,119,82,74,8,41,16,36,145,234,82,165,
226,170,76,1,104,84,171,40,250,1,138,165,146,251,156,21,10,208,81,140,48,108,34,142,221,243,131,32,112,191,143,35,72,165,224,251,62,172,181,110,6,79,210,25,80,175,55,208,12,155,40,148,74,16,74,66,107,
157,213,231,180,214,162,92,46,187,253,72,102,167,120,214,21,112,9,130,0,141,102,19,165,98,177,245,122,197,2,116,20,65,196,33,170,149,121,24,109,221,249,6,208,108,134,48,86,163,186,180,132,56,54,80,158,
64,79,169,23,253,3,3,88,170,44,192,247,2,12,174,27,198,236,204,44,206,158,155,128,148,62,122,122,138,40,4,37,244,245,15,162,94,175,163,90,173,161,86,171,65,41,137,129,161,33,84,22,22,209,104,54,81,44,
20,80,44,151,81,169,44,96,118,118,22,74,122,152,95,156,199,236,236,44,54,109,222,130,125,55,222,128,117,235,70,16,248,30,148,39,17,235,16,199,142,31,199,11,207,63,143,70,163,14,41,61,120,158,196,224,240,
48,148,242,48,53,57,137,185,165,24,214,0,81,20,194,232,8,18,6,187,118,108,199,185,137,147,80,82,194,106,131,153,11,51,8,5,240,210,139,47,225,61,239,125,15,254,231,127,247,239,81,76,202,194,245,246,148,
161,117,140,191,250,220,231,240,155,191,249,219,104,44,53,48,182,126,12,67,131,67,16,158,68,193,243,49,61,59,139,215,14,29,194,212,244,121,12,13,173,195,146,13,80,40,247,161,81,185,128,225,98,128,245,
67,125,40,20,11,56,127,97,14,211,75,13,212,140,197,207,254,171,143,227,215,126,249,23,80,40,0,97,3,240,125,224,245,87,142,226,211,255,241,63,226,255,252,147,63,194,7,30,126,63,118,239,218,137,56,138,240,
226,43,135,48,53,57,137,90,173,134,66,224,99,252,204,89,104,27,226,231,254,249,207,225,224,219,14,98,105,169,2,223,3,54,110,26,67,216,104,226,240,225,215,160,181,198,186,145,81,88,88,55,18,103,195,122,
52,106,53,84,22,231,112,110,226,20,198,199,39,176,109,219,86,236,189,97,47,10,133,34,10,65,128,103,158,253,14,254,238,239,255,1,91,183,237,192,134,141,91,241,87,95,248,2,26,141,58,42,75,75,88,55,60,140,
79,252,202,39,112,240,224,65,136,223,248,15,159,180,198,26,76,79,79,227,212,169,83,248,216,207,124,12,247,191,255,17,156,159,56,3,33,45,6,134,134,241,205,39,159,196,243,47,188,8,41,149,43,120,17,20,208,
219,215,139,32,240,49,59,191,8,35,4,46,204,45,96,203,230,205,88,152,95,64,111,95,63,70,71,215,193,247,125,212,106,53,8,225,193,218,24,82,42,40,37,225,41,15,197,158,18,124,223,7,172,117,69,46,132,128,80,
110,62,177,18,18,74,185,241,88,66,72,120,190,7,165,20,148,20,174,186,141,144,176,214,85,82,50,137,40,148,0,164,231,46,38,192,0,66,161,217,168,195,216,8,218,104,0,2,65,224,35,142,99,215,212,80,30,138,190,
15,33,21,194,168,129,56,142,220,107,120,30,4,10,176,6,80,240,96,0,104,3,40,41,160,60,215,235,108,109,242,179,114,133,73,162,184,137,40,106,194,2,40,5,5,248,161,129,240,21,252,160,128,166,49,104,132,145,
43,24,33,12,32,61,88,8,120,2,168,213,171,144,66,66,90,3,79,74,148,60,129,122,163,6,137,24,74,42,192,88,24,175,0,107,165,27,14,37,21,202,61,69,196,81,4,161,20,172,182,136,226,24,74,185,249,203,233,236,
15,119,138,4,60,233,65,39,203,84,40,40,88,107,161,224,4,6,0,205,48,132,16,98,89,37,117,173,53,172,117,85,160,178,18,14,133,66,246,183,40,142,179,5,241,242,11,227,229,31,159,254,108,140,65,189,230,34,77,
229,37,239,163,82,8,124,31,141,102,51,123,125,229,110,93,8,35,55,157,209,104,13,153,236,87,28,134,240,130,0,82,8,196,113,12,223,247,81,8,2,68,81,132,165,165,42,140,113,51,123,60,207,131,53,110,38,204,
194,226,34,134,71,71,80,89,92,116,85,154,138,69,72,233,122,192,227,56,70,169,84,66,189,90,199,64,185,7,97,20,101,219,117,101,235,12,172,177,8,124,15,161,214,174,230,131,50,136,181,6,172,132,18,110,22,
158,128,128,149,73,9,10,3,196,113,12,99,1,36,55,4,33,0,105,1,35,0,29,27,68,58,6,96,33,160,32,4,160,252,0,202,115,231,35,142,35,40,225,110,60,97,179,9,11,11,63,240,17,134,77,20,130,18,162,176,233,102,200,
9,129,40,138,178,194,48,141,70,29,133,130,155,2,28,134,33,138,197,18,180,118,215,154,16,194,201,212,243,160,81,128,84,69,4,158,130,181,26,58,110,64,135,33,4,34,196,97,232,58,132,148,68,45,114,211,45,167,
47,76,67,10,9,64,34,40,184,25,83,133,98,224,114,129,139,21,68,161,69,179,217,132,167,148,27,103,217,223,139,122,189,129,202,82,5,61,133,18,34,163,49,83,109,32,138,13,116,163,134,178,39,17,214,43,152,155,
153,69,181,222,196,116,101,9,115,149,69,124,244,71,127,28,15,188,251,61,240,96,221,132,143,32,128,239,75,252,217,159,253,57,254,240,15,126,31,181,90,13,189,189,101,148,123,203,80,22,104,52,154,88,88,152,
195,194,252,2,164,144,152,95,156,199,250,245,235,241,216,135,30,195,158,27,247,194,151,30,194,40,130,82,18,51,51,23,208,108,52,112,250,244,105,188,255,253,239,199,99,31,253,168,43,18,156,22,67,57,250,
50,94,124,225,69,188,242,202,203,24,30,30,70,181,86,71,16,4,120,233,165,151,48,56,48,128,189,55,238,195,243,175,28,194,103,62,243,89,40,169,176,121,235,22,52,27,77,244,245,247,225,193,7,30,132,120,242,
111,255,198,10,41,208,104,132,40,4,1,70,215,175,135,144,2,70,27,24,107,221,93,201,184,57,237,86,194,21,165,128,112,181,61,133,128,144,30,188,66,9,126,80,0,4,16,107,13,163,53,172,5,140,181,73,165,56,151,
15,77,43,69,105,235,202,222,185,139,92,102,37,196,100,186,142,139,181,48,162,85,197,78,249,30,164,1,12,140,123,144,145,173,82,164,50,249,48,91,87,75,81,72,233,10,212,9,1,41,129,90,99,9,66,9,244,20,75,
168,53,234,16,66,162,24,4,208,70,35,138,53,164,16,48,214,201,170,16,20,96,12,80,175,199,16,82,161,24,20,97,52,16,134,26,197,98,0,173,99,24,107,96,161,221,133,33,4,180,49,80,210,66,155,8,202,19,128,182,
40,9,31,97,20,34,12,53,188,98,0,72,31,22,22,205,56,134,80,128,133,116,197,175,4,160,148,132,214,49,180,213,174,30,169,117,205,62,41,220,135,95,27,155,221,96,92,250,209,69,114,66,0,74,169,172,70,104,24,
69,203,171,17,42,149,85,230,178,201,63,68,50,51,195,229,128,99,39,212,36,122,76,183,223,41,193,86,205,95,11,99,76,246,61,21,106,94,156,233,126,40,165,178,109,197,113,220,246,152,244,24,130,52,154,181,
46,26,214,97,132,32,17,88,24,69,201,123,99,33,133,64,169,84,66,163,209,132,181,174,135,58,138,34,232,100,31,162,40,66,148,124,238,220,76,24,233,62,82,158,66,189,94,7,146,242,128,169,232,221,103,195,141,
253,12,224,222,195,180,108,160,251,8,138,220,10,7,174,212,97,90,61,43,21,37,0,88,217,185,4,145,116,143,79,138,250,8,72,52,155,13,55,55,92,90,88,227,158,47,149,204,10,166,185,89,47,238,189,240,148,132,
72,214,49,18,82,192,26,139,40,10,33,132,132,181,38,219,255,116,137,13,99,52,164,4,148,39,16,133,49,180,137,209,83,238,73,206,131,15,163,35,68,177,70,185,183,15,161,13,160,141,112,181,10,117,4,107,99,244,
149,10,104,212,42,8,195,70,242,57,2,188,114,9,181,122,19,158,84,238,102,1,64,41,1,171,145,237,71,161,80,130,133,219,150,54,218,201,28,128,146,18,65,161,0,169,36,194,102,8,33,20,172,0,76,24,186,136,215,
24,20,139,61,8,195,6,194,102,19,210,247,32,97,177,184,184,8,192,189,175,74,185,207,115,163,217,132,146,174,248,205,244,244,121,120,190,143,64,186,169,168,97,24,182,213,23,158,56,59,1,107,129,45,155,54,
39,45,32,129,153,153,11,152,157,157,197,244,244,121,156,58,53,142,247,61,240,62,124,240,145,71,16,134,46,152,82,48,232,41,21,240,165,47,253,29,198,199,79,67,199,26,165,158,18,54,108,88,143,48,138,81,12,
2,60,243,236,115,248,242,87,190,138,225,145,81,28,61,122,20,139,149,69,252,192,163,143,98,239,158,189,56,123,238,44,196,153,163,199,109,250,105,176,198,66,91,147,149,115,146,82,100,255,118,159,9,9,72,
1,145,214,75,76,238,176,86,4,73,148,40,92,147,81,235,100,101,22,87,88,210,192,66,42,64,72,13,173,221,124,108,99,13,32,164,211,136,104,175,202,109,146,15,96,42,65,223,243,114,23,180,5,172,68,28,139,92,
49,100,3,33,101,86,152,1,144,48,208,80,82,192,34,134,16,110,95,234,181,26,130,100,222,113,33,105,166,165,219,212,113,236,102,31,64,193,66,2,86,194,243,60,192,0,97,164,17,248,10,177,113,242,148,64,86,217,
168,81,175,65,74,137,192,147,144,158,130,132,128,9,35,119,70,141,133,148,128,49,233,249,116,167,58,61,55,70,2,86,184,105,195,128,128,54,58,251,64,8,33,50,121,116,19,88,38,199,228,2,55,93,150,162,90,73,
132,23,147,103,94,110,109,85,179,61,47,19,67,250,216,88,235,76,166,249,199,165,63,119,46,215,156,47,166,157,30,95,148,136,85,74,233,6,78,75,217,38,194,116,95,59,143,67,102,117,75,45,180,49,45,105,37,191,
51,72,206,109,254,247,198,100,63,167,55,127,207,182,10,122,184,202,255,78,92,249,237,193,118,91,26,79,180,149,12,53,6,73,75,196,141,0,72,63,135,81,24,194,38,203,204,8,37,32,44,224,7,201,251,149,180,154,
32,4,226,36,250,181,0,60,63,128,239,41,212,170,53,196,201,208,175,116,254,181,231,249,104,54,221,77,196,69,230,218,221,204,165,130,176,22,74,121,240,252,0,205,102,29,214,186,233,149,70,199,136,181,128,
53,18,214,2,82,24,120,210,205,130,210,81,12,107,227,228,24,13,116,108,92,80,100,5,44,44,132,0,130,66,17,81,24,193,24,237,222,55,165,178,128,197,26,11,99,210,180,140,202,138,158,107,109,92,75,81,170,228,
122,79,106,218,202,116,157,51,157,157,220,40,10,225,121,194,205,4,139,99,68,81,156,180,72,100,38,209,98,177,4,207,186,98,214,214,90,24,237,36,90,44,185,74,86,139,11,139,8,130,0,11,139,174,148,157,16,194,
93,235,210,69,234,74,42,120,158,66,51,12,161,99,141,88,199,216,180,126,12,19,19,103,146,114,129,192,240,240,48,108,82,30,56,12,35,204,204,204,64,91,139,222,222,94,84,42,139,152,152,56,131,161,97,87,201,
169,222,168,67,156,58,114,212,166,211,201,178,42,120,201,255,4,68,86,33,6,182,189,178,184,205,149,16,213,201,199,200,230,5,152,202,47,185,27,11,105,225,126,171,97,146,92,152,139,0,210,11,178,85,137,70,
107,211,246,161,151,185,72,192,133,40,18,198,122,110,221,33,235,222,40,33,83,41,184,208,32,253,157,209,17,32,92,19,11,214,194,11,60,104,109,161,210,88,34,121,29,37,100,22,157,229,66,7,8,155,68,138,194,
116,149,147,78,46,72,119,151,148,201,178,8,113,118,97,153,68,160,249,26,131,105,42,32,173,225,156,223,94,103,36,151,254,46,255,115,167,60,149,148,208,198,92,182,60,117,210,132,245,218,110,78,237,175,209,
77,124,221,246,47,191,237,84,96,157,199,213,185,47,109,251,103,91,165,105,243,231,78,27,221,22,129,118,95,218,169,93,160,233,218,171,182,227,190,252,70,228,233,90,59,237,203,182,181,78,78,123,116,159,
127,154,167,220,185,213,169,44,173,110,137,67,186,166,152,16,112,37,33,125,5,41,61,39,27,173,147,207,183,133,49,238,26,144,194,165,6,148,82,217,113,25,99,33,32,33,146,60,174,82,42,17,21,90,75,25,39,17,
99,182,163,185,243,98,180,187,149,235,68,128,38,119,211,76,175,73,63,240,151,201,51,125,79,46,38,79,107,77,219,182,242,50,84,201,205,88,235,24,205,102,19,82,33,105,133,152,92,139,69,67,235,24,125,125,
125,168,44,86,224,73,149,5,84,249,149,1,108,78,204,81,20,193,104,131,66,177,128,176,25,194,90,11,207,83,109,159,21,87,203,58,132,142,35,244,15,12,186,115,33,5,140,177,153,120,33,210,227,111,125,38,210,
215,157,155,155,195,201,147,167,32,78,29,61,105,97,211,55,185,221,147,249,19,105,218,131,195,182,199,10,47,64,104,53,172,182,240,60,9,229,249,208,113,156,72,211,45,113,96,140,65,20,215,97,97,220,40,27,
173,93,135,68,146,131,72,98,95,248,201,29,58,125,211,37,68,219,126,164,175,111,172,77,68,105,19,215,11,40,153,52,115,97,161,181,203,125,118,230,243,210,55,38,171,55,157,164,38,90,209,117,46,194,205,132,
183,114,33,231,188,24,220,191,5,132,49,151,92,105,69,155,228,122,20,88,22,81,185,99,91,46,201,78,185,229,229,217,253,53,204,178,253,203,71,180,233,118,210,14,148,139,174,196,209,37,26,237,150,47,93,73,
148,151,196,2,202,0,249,67,201,203,243,226,235,226,93,166,60,133,139,4,243,242,188,88,179,221,109,175,227,230,145,23,165,69,91,58,64,228,174,150,214,103,213,102,139,248,185,86,183,205,228,102,224,90,107,
249,160,36,77,203,24,109,96,97,147,84,152,19,109,254,126,37,132,2,224,185,200,51,73,3,165,57,99,8,151,30,66,210,202,235,122,238,146,247,84,27,157,29,127,123,42,194,173,126,112,37,242,76,127,191,242,53,
96,146,124,186,130,177,6,113,210,252,151,82,33,214,49,130,32,192,210,210,18,202,61,101,40,41,16,55,162,76,174,233,254,122,158,27,101,33,133,204,210,7,237,215,99,254,179,153,190,207,6,176,2,202,11,220,
121,83,73,170,208,216,246,26,244,22,16,34,70,183,5,134,171,213,42,188,44,41,111,91,111,102,246,98,74,46,251,93,154,203,177,48,16,201,155,167,60,9,95,27,151,44,135,133,213,33,180,137,147,188,136,132,214,
0,172,118,119,34,1,40,11,184,118,124,250,33,20,72,227,94,109,12,132,117,23,184,16,173,171,41,31,165,8,1,72,164,6,23,29,145,143,19,168,11,44,212,178,232,43,219,70,190,83,35,39,208,246,16,183,219,191,219,
69,145,202,35,21,139,182,26,158,17,203,150,129,48,185,15,166,148,233,223,109,114,35,18,109,251,41,211,72,229,98,43,38,230,246,55,31,117,182,53,161,147,124,162,177,214,53,9,147,42,237,58,39,184,203,93,
118,119,165,136,115,165,78,163,181,198,92,98,9,48,147,221,217,45,132,21,93,158,108,147,207,175,133,151,166,164,164,132,178,22,26,38,105,98,139,228,6,107,97,172,139,206,60,239,162,107,254,37,247,87,11,
209,121,94,146,136,83,165,231,69,185,107,161,181,124,140,129,132,116,221,122,157,178,183,78,156,157,55,164,214,41,182,23,61,51,162,101,192,213,175,218,211,101,173,49,113,137,231,175,244,158,167,209,101,
38,243,92,11,215,104,157,92,115,54,139,6,165,84,217,246,124,207,135,53,22,61,201,172,181,40,52,240,146,14,81,215,210,83,48,34,185,25,38,205,249,252,254,136,180,115,57,61,83,198,186,27,141,209,48,82,194,
66,65,39,163,18,172,16,78,168,74,164,161,88,178,74,3,32,34,0,34,202,182,229,174,83,137,193,193,193,244,58,23,128,208,203,46,8,33,204,50,135,72,233,230,199,26,109,1,9,248,74,66,235,70,18,142,90,151,79,
176,238,77,112,77,101,211,138,16,211,228,163,88,121,73,163,110,61,182,82,202,101,81,79,55,161,165,189,169,105,51,246,98,157,31,151,21,20,117,105,58,47,147,113,210,121,212,109,145,48,99,108,246,161,76,
35,56,109,45,84,224,47,139,50,161,212,50,177,229,143,163,243,223,23,147,91,250,247,84,242,249,14,147,171,17,153,46,190,148,68,126,182,163,169,149,157,207,46,251,159,111,218,107,109,224,121,202,229,219,
140,139,232,140,53,144,202,221,108,149,16,64,218,4,148,194,125,182,164,128,132,116,250,76,75,166,167,17,165,18,43,8,40,247,1,22,54,115,229,50,95,95,244,124,191,249,171,65,90,107,46,42,64,219,17,32,117,
62,54,19,159,84,109,143,145,112,194,1,92,71,151,235,104,214,201,249,247,178,78,47,171,221,141,219,173,124,144,188,183,73,7,149,201,34,94,11,169,58,95,215,116,9,22,146,235,37,73,67,164,249,100,3,215,145,
46,132,106,221,92,172,105,189,75,42,9,80,172,130,132,19,168,231,249,238,70,106,146,86,172,129,139,66,115,134,49,74,67,234,118,221,8,207,3,164,132,23,219,200,229,32,146,101,7,210,33,16,221,228,102,147,
94,71,1,225,34,79,35,86,88,9,205,182,249,77,44,255,225,98,1,221,170,100,214,45,98,74,133,147,151,70,91,147,233,50,239,156,233,243,211,124,102,148,164,34,242,209,102,94,234,74,38,189,168,214,172,40,224,
244,131,39,146,83,103,46,35,218,187,216,191,187,61,39,205,199,166,145,237,229,70,153,23,187,145,228,3,171,246,14,191,142,86,138,93,222,124,94,169,221,222,72,85,146,116,56,74,1,192,83,237,159,33,23,10,
230,195,175,86,79,183,49,238,124,74,183,100,132,146,2,218,186,176,48,189,192,84,218,36,151,185,198,119,42,11,105,32,211,157,77,46,86,105,178,168,161,123,24,220,150,164,5,144,207,141,219,156,212,187,153,
245,10,206,125,183,230,104,254,84,228,211,15,169,20,165,82,137,32,218,37,218,234,116,82,46,32,238,34,89,107,93,94,60,159,202,232,148,172,237,250,121,55,89,123,178,189,217,220,145,79,78,194,246,78,183,
167,11,38,182,142,217,245,180,166,41,55,37,93,199,100,58,114,65,105,3,9,47,185,129,202,164,241,33,219,50,209,198,88,88,165,97,181,116,235,170,37,159,45,107,146,52,159,114,35,11,178,188,55,0,24,229,142,
221,90,151,59,54,6,126,80,4,96,225,9,36,137,82,19,163,235,173,179,243,78,218,49,236,36,237,45,109,27,30,179,22,205,179,164,185,211,214,17,146,219,55,211,241,186,87,34,199,110,249,151,149,254,150,254,221,
88,219,254,218,221,46,136,100,184,101,235,164,136,101,63,3,64,244,6,154,207,120,3,210,189,210,109,121,222,42,86,170,22,232,146,230,89,85,202,51,231,39,153,249,168,173,35,43,245,156,236,126,174,132,146,
89,71,32,146,134,49,114,195,130,228,10,238,131,188,72,20,40,47,18,29,202,85,60,214,184,222,237,236,46,115,153,2,77,155,159,86,136,182,33,76,54,59,217,210,85,122,207,223,220,100,107,104,81,218,249,101,
100,146,45,184,72,132,185,82,116,170,228,218,124,54,91,45,56,233,58,144,77,174,239,196,0,66,230,2,140,44,99,152,68,253,194,201,77,64,64,216,36,128,51,22,144,10,194,26,24,37,147,153,110,34,215,31,99,179,
107,212,125,142,210,156,183,112,159,14,19,185,207,140,76,147,211,174,88,178,16,2,194,136,228,51,41,224,161,0,40,215,127,3,24,168,228,58,240,64,200,53,133,88,126,71,191,100,66,103,173,182,124,5,9,90,24,
183,81,187,114,228,105,172,185,244,205,83,181,238,68,70,116,220,77,114,29,157,174,67,201,102,39,193,26,219,57,80,96,205,155,253,43,69,154,157,55,223,101,17,115,34,116,107,145,164,84,218,239,182,34,185,
19,10,0,198,138,100,232,89,150,33,113,99,103,69,178,120,156,112,157,70,144,128,77,198,168,91,107,50,113,42,225,198,68,103,163,10,96,32,77,152,172,236,43,32,96,96,211,6,134,116,29,115,2,2,210,202,44,216,
73,59,232,210,204,18,229,73,174,14,37,118,185,184,46,115,3,137,249,236,69,165,216,158,101,176,43,101,27,186,72,88,0,203,7,179,173,148,176,106,23,103,62,141,101,187,229,107,229,197,111,1,34,23,218,10,177,
124,83,185,99,183,54,29,150,247,6,238,34,29,209,168,242,150,239,159,142,163,214,128,254,100,40,148,251,89,103,77,252,52,85,208,202,91,186,244,65,108,226,236,247,46,23,234,185,14,155,180,233,161,93,142,
210,141,116,72,207,157,118,125,204,34,21,181,128,72,115,162,66,36,77,116,3,35,210,20,137,73,246,75,119,239,31,48,238,41,54,73,222,100,45,28,41,219,71,221,36,18,133,64,107,104,101,50,230,157,242,36,223,
27,116,21,175,189,104,84,121,121,170,78,103,24,217,75,63,207,180,37,5,186,104,92,162,149,216,89,40,191,109,36,0,0,24,132,73,68,65,84,65,146,93,243,30,233,24,85,151,250,21,104,245,67,180,178,194,185,155,
80,58,68,41,121,89,33,210,81,50,114,217,24,204,139,31,185,65,107,147,54,105,254,174,208,196,247,124,32,118,67,134,178,153,101,82,184,201,39,249,92,108,50,140,42,93,210,216,133,214,185,17,9,233,129,166,
99,111,133,204,157,66,123,209,119,41,123,183,114,35,89,150,13,9,108,133,253,80,158,130,22,22,208,203,59,152,211,119,92,228,134,44,166,3,204,40,79,114,149,59,209,182,13,47,179,249,102,219,26,53,203,197,
170,159,189,138,230,189,89,205,102,210,117,202,197,242,203,89,116,238,145,232,250,123,23,103,37,3,107,108,62,150,78,198,242,122,42,17,102,46,130,82,162,245,88,157,54,141,47,157,207,180,218,73,38,21,33,
210,204,178,185,116,243,94,100,145,154,72,94,223,102,118,236,140,240,220,113,73,152,116,96,58,68,22,149,91,233,70,243,200,139,156,123,3,155,76,208,177,185,233,40,93,90,40,238,118,0,15,18,202,83,16,66,
65,194,66,75,189,188,53,32,4,132,85,109,231,63,61,66,202,147,92,85,77,247,213,43,236,202,5,154,143,41,46,47,242,92,197,126,200,110,215,108,54,85,45,247,76,213,117,156,114,91,164,105,157,16,100,254,229,
115,57,5,55,196,80,192,164,193,39,68,150,243,76,39,3,228,119,61,29,240,111,97,1,37,87,60,231,157,177,181,84,10,6,186,109,198,141,181,173,177,202,43,222,48,164,219,191,172,102,69,178,223,198,154,54,89,
46,63,133,178,203,73,94,249,150,149,21,3,66,151,177,173,22,109,179,3,5,36,164,175,146,94,117,119,19,75,207,151,167,188,100,82,134,204,58,150,4,146,153,69,50,63,228,76,82,158,228,186,213,116,46,105,104,
113,121,93,69,237,207,177,43,9,20,178,53,116,201,230,4,154,109,67,161,235,240,189,182,151,90,105,156,87,231,254,138,116,104,172,123,201,220,52,36,107,91,1,151,73,35,169,174,119,1,209,241,171,214,113,90,
88,87,187,34,145,190,27,70,100,144,115,86,151,125,151,200,198,152,100,67,193,146,125,53,43,141,106,232,56,54,219,126,46,68,43,255,208,42,176,98,90,99,41,20,12,108,122,124,58,191,41,153,212,236,112,195,
9,165,39,221,26,83,104,143,204,221,208,178,100,156,104,42,78,233,78,156,236,242,38,81,158,132,172,40,206,149,187,132,236,229,68,173,89,4,40,46,51,140,22,144,194,174,240,224,150,100,100,86,180,39,157,104,
96,146,249,127,105,243,213,182,5,131,58,29,47,105,177,108,188,236,178,240,22,173,52,163,77,162,76,155,84,130,234,124,138,205,53,221,221,224,117,149,204,9,151,109,130,52,109,102,235,126,3,235,172,173,160,
178,230,118,43,255,233,186,147,210,170,99,238,5,92,108,45,210,219,72,43,194,181,73,5,55,41,90,247,178,180,35,168,227,38,150,166,19,92,138,66,230,106,107,200,182,104,158,242,36,215,98,251,126,149,78,92,
73,60,118,21,129,230,229,102,66,59,52,188,98,167,209,165,54,157,31,113,127,137,7,75,129,110,227,74,187,221,16,210,154,183,173,166,122,146,27,237,54,35,174,237,252,184,65,247,233,76,45,247,0,219,177,15,
89,220,151,189,126,218,227,46,148,188,164,156,219,191,219,246,166,123,91,233,42,87,130,200,228,122,234,211,177,76,2,105,26,65,185,42,81,29,7,47,61,149,68,147,50,27,0,225,6,41,136,236,24,178,99,147,29,
105,131,206,89,145,140,60,201,245,25,89,118,230,25,175,124,120,212,138,90,51,171,13,110,47,54,248,62,201,47,118,157,204,127,233,129,155,89,153,194,172,66,90,186,169,180,137,47,178,9,91,105,231,83,107,
235,46,197,144,86,63,51,90,183,199,133,178,163,76,101,26,148,25,147,150,82,107,157,155,142,89,88,249,129,241,221,90,231,185,100,104,251,201,51,105,237,140,172,216,165,139,158,165,27,208,158,14,170,95,
54,150,212,10,88,97,93,1,16,136,44,83,99,211,230,127,58,9,33,237,81,151,237,199,213,58,111,185,108,15,35,79,242,189,237,203,246,166,96,43,6,93,163,1,144,43,232,84,192,166,67,14,47,97,90,217,37,208,76,
46,83,147,19,232,106,7,184,231,37,101,90,2,189,180,100,177,172,220,100,42,213,182,244,132,144,43,28,66,46,135,42,229,178,2,78,217,136,168,86,117,60,88,147,236,100,103,202,215,174,16,228,45,139,166,69,
82,113,205,237,132,149,58,91,242,197,229,64,85,54,27,201,10,233,42,175,10,55,75,203,182,245,188,185,244,131,149,173,89,126,110,9,22,217,214,111,39,115,255,183,182,53,172,150,242,36,223,219,129,102,215,
200,102,53,2,189,140,14,36,209,18,246,37,106,97,173,28,60,166,43,36,200,75,101,44,58,39,19,152,46,243,76,37,86,87,53,225,18,225,180,112,145,27,132,108,23,165,88,225,9,214,118,204,129,183,137,44,205,242,
99,55,93,38,203,138,118,145,26,99,147,35,113,5,1,165,112,53,124,211,102,117,90,139,84,73,223,77,159,22,166,213,41,39,148,235,60,18,174,30,111,123,243,223,253,79,72,47,233,137,79,203,232,217,92,62,85,116,
63,53,226,10,154,237,143,63,254,56,250,251,250,80,46,151,81,234,233,65,33,8,178,117,105,90,75,15,8,94,184,228,170,145,230,27,109,150,175,94,56,34,23,237,174,240,178,98,141,183,143,142,112,173,237,113,
221,82,21,118,213,167,112,89,228,151,70,241,226,82,145,126,199,171,116,52,217,243,133,175,87,188,205,228,34,112,107,77,182,22,212,178,35,176,73,229,176,164,83,204,38,207,107,207,114,119,201,155,38,55,
56,99,140,91,204,208,196,104,54,67,212,106,117,84,107,85,84,42,21,252,151,223,251,189,229,169,231,46,172,90,158,125,189,189,24,24,24,64,255,192,0,202,61,61,40,20,139,217,106,139,174,0,44,229,73,222,234,
102,250,85,40,241,181,144,230,69,143,175,139,60,243,22,188,168,67,47,126,206,140,125,3,55,32,219,26,176,127,233,115,101,187,30,78,171,144,72,238,20,100,85,210,108,246,51,114,235,76,229,231,90,33,151,219,
205,70,245,38,37,50,141,209,174,224,143,142,146,21,100,107,240,125,175,53,38,22,249,169,161,203,118,241,242,228,217,219,235,150,85,29,28,28,68,95,95,31,74,197,34,130,66,33,89,213,82,102,43,96,18,242,214,
200,202,190,181,47,143,182,214,251,27,78,171,94,170,232,244,50,219,172,116,237,93,201,190,116,57,159,246,141,136,52,47,67,107,243,75,233,225,98,195,196,210,154,180,89,177,19,147,12,86,202,13,155,2,90,
179,152,92,61,247,124,101,38,209,113,90,220,244,84,155,172,80,160,181,70,20,54,81,42,54,17,4,1,164,144,46,231,217,165,131,46,87,222,213,85,182,210,118,245,242,44,149,74,40,247,244,160,183,183,23,125,125,
125,232,233,233,73,22,164,242,178,101,28,40,79,114,61,70,158,174,19,216,229,226,214,162,50,211,170,139,164,116,214,19,125,179,72,154,196,102,45,110,84,182,91,88,188,66,61,93,147,43,208,158,172,158,107,
116,171,24,95,150,135,237,82,233,175,83,69,182,227,245,211,50,147,81,216,64,189,86,3,132,69,20,69,40,213,139,104,159,198,149,142,109,109,205,140,82,230,50,103,24,21,10,5,20,75,37,244,148,74,40,151,203,
153,60,125,223,167,60,201,213,209,68,70,103,19,213,126,87,94,126,109,6,62,173,65,101,169,53,23,102,251,15,166,203,65,203,21,155,251,173,113,72,54,183,34,111,171,9,222,237,204,181,162,81,107,93,161,14,
183,61,147,245,164,167,165,235,220,236,38,11,147,20,58,73,119,38,157,78,153,150,167,75,7,219,231,11,73,91,155,172,169,166,67,52,147,133,223,138,81,132,82,189,129,66,110,57,237,244,24,76,82,218,46,93,67,
79,39,29,88,171,150,167,231,121,240,125,31,65,161,128,32,8,156,76,139,69,215,105,148,44,93,75,121,146,183,84,158,98,121,52,186,26,21,229,167,253,93,110,20,219,150,99,187,188,121,71,111,173,52,47,39,106,
189,216,128,255,206,135,117,203,97,90,187,60,193,209,237,189,202,68,151,24,216,75,7,196,231,7,24,229,4,139,246,181,237,68,126,70,81,218,35,111,90,157,79,233,248,77,107,45,180,213,240,99,23,178,234,56,
70,49,40,192,243,125,120,158,66,126,33,14,153,12,194,55,73,20,154,204,57,186,188,200,83,37,146,84,74,101,34,77,191,203,100,153,10,202,147,188,85,242,180,111,100,176,123,183,181,169,190,11,242,188,170,
34,205,43,108,202,47,143,58,109,151,230,247,242,101,121,58,155,209,214,0,86,38,147,74,141,133,145,201,92,116,43,219,250,195,100,82,252,56,63,203,168,85,4,165,213,69,158,174,183,100,114,101,240,92,125,
79,11,33,44,180,22,136,133,64,65,107,68,145,15,149,248,76,37,85,249,211,206,34,3,55,50,74,166,99,83,115,249,207,85,203,83,36,54,79,215,243,145,82,102,61,237,140,60,201,91,238,208,43,148,144,200,71,155,
66,92,34,11,183,246,145,231,119,251,154,185,84,55,205,170,197,41,187,76,125,74,139,104,118,158,35,97,187,5,154,185,29,178,174,35,71,139,236,241,173,2,209,157,5,80,146,57,252,38,41,93,151,188,1,50,55,150,
211,24,9,165,68,182,240,164,148,46,37,237,94,87,66,136,86,115,92,41,223,125,9,233,170,41,165,243,217,187,76,58,200,6,202,187,59,194,101,200,51,149,99,186,54,117,242,115,250,111,70,158,228,90,144,103,231,
103,52,171,188,46,58,103,34,125,247,154,237,111,186,236,58,182,247,198,7,3,172,176,0,244,10,157,73,238,28,231,255,108,179,249,245,72,167,84,10,55,141,18,112,181,52,179,28,101,110,184,147,132,108,245,172,
203,180,249,188,188,139,78,230,114,157,110,185,33,183,80,156,72,154,236,198,24,183,90,170,113,83,54,221,255,37,164,84,112,179,253,69,219,161,186,226,35,185,99,78,58,250,87,63,195,40,183,196,110,94,166,
157,95,132,188,21,172,166,9,220,182,152,92,110,241,61,209,161,75,113,5,114,203,103,228,222,140,134,184,184,154,182,179,210,117,190,66,161,234,110,103,197,26,211,254,190,228,234,160,40,161,114,105,128,
214,218,68,217,214,68,103,186,101,249,107,186,122,157,54,43,45,151,63,122,161,210,249,240,201,140,34,169,178,57,238,162,75,79,152,171,42,40,151,121,90,242,178,35,215,131,88,187,137,19,93,27,134,107,169,
170,239,85,228,101,169,67,199,177,27,98,100,211,247,66,182,22,197,107,123,31,220,99,140,77,10,140,200,116,106,104,171,40,113,251,100,198,139,85,108,74,90,199,217,190,182,215,20,93,94,32,38,121,189,108,
54,212,165,143,143,115,219,201,247,148,36,223,250,216,238,58,113,167,233,222,152,239,214,140,86,190,7,19,27,24,173,93,243,89,200,229,249,8,9,183,82,165,72,122,202,147,86,178,148,221,2,93,217,125,103,196,
37,226,127,137,172,0,246,178,26,208,137,75,5,90,107,61,181,73,213,216,101,149,74,40,79,114,93,241,166,244,110,175,106,26,229,85,114,252,111,162,64,179,160,14,162,173,215,61,93,86,217,90,55,51,167,213,
42,119,75,6,3,174,0,137,242,84,107,252,103,178,196,135,16,226,210,81,110,234,202,124,137,187,172,56,114,231,206,45,159,131,47,100,107,8,148,77,100,41,140,76,102,45,185,25,73,173,133,7,76,118,216,148,39,
33,215,144,52,87,63,109,243,187,17,129,202,139,186,53,47,236,116,253,36,200,116,233,96,153,149,61,118,98,50,174,210,123,90,169,190,75,76,219,185,229,172,101,109,100,71,195,193,184,41,148,105,135,20,0,
232,100,113,58,97,93,25,58,99,115,83,57,219,11,34,183,45,85,109,44,155,237,132,188,145,152,172,173,135,250,18,131,233,197,155,16,241,93,237,157,177,23,203,41,119,62,46,155,98,153,239,148,73,122,206,93,
20,40,219,52,150,246,156,139,164,183,61,191,20,176,237,216,78,42,216,116,145,96,11,87,38,207,154,36,119,154,149,39,77,150,217,16,203,7,236,183,10,147,152,110,125,249,108,182,147,235,60,104,188,198,34,
205,183,74,132,87,250,252,182,225,73,105,148,170,117,110,9,228,188,166,58,218,221,29,235,95,228,214,113,235,232,209,239,172,186,217,125,146,195,50,1,38,57,76,33,186,12,175,52,88,190,204,136,177,121,149,
51,242,36,148,230,21,11,229,187,32,206,75,9,108,45,103,39,189,25,130,238,186,127,203,42,120,172,180,62,125,187,26,173,148,174,206,113,242,159,93,113,225,168,156,116,211,156,103,50,218,221,13,69,130,171,
44,47,146,99,22,230,146,133,9,150,101,16,146,209,165,6,134,242,36,215,155,61,197,234,229,215,117,64,253,181,27,105,190,213,77,255,180,193,155,174,25,180,210,93,109,217,34,200,162,21,117,102,101,8,186,
109,35,123,74,62,114,205,247,198,203,164,55,93,36,173,245,86,254,216,229,54,91,157,73,89,132,217,89,129,62,93,162,152,145,39,161,64,87,215,68,191,210,24,111,213,139,121,92,129,216,86,27,125,126,183,165,
185,226,62,73,153,172,123,108,151,55,219,179,98,245,93,214,178,183,98,89,45,145,182,119,68,116,115,168,200,158,10,168,101,107,209,103,162,204,213,70,176,157,178,92,182,100,116,126,142,190,164,60,9,5,122,
49,105,190,145,230,254,170,42,58,173,81,126,241,106,137,52,47,37,243,52,133,40,164,232,56,65,43,207,205,186,242,195,200,109,51,153,73,182,124,247,108,78,182,249,152,183,99,172,103,23,40,79,114,125,11,
180,187,1,222,144,36,87,51,69,115,45,197,118,181,244,196,219,203,73,135,88,219,190,230,210,165,107,35,119,141,44,243,81,232,178,69,219,68,247,133,220,46,166,218,182,252,66,231,27,154,235,60,234,12,82,
9,185,190,73,150,137,120,163,209,165,189,216,133,9,124,79,214,128,88,125,231,149,92,46,29,145,147,234,106,196,217,241,184,182,57,233,233,246,46,247,20,119,62,71,174,230,72,8,33,87,220,131,46,86,251,152,
239,225,226,57,151,213,235,159,78,49,23,151,99,184,46,143,181,93,58,217,175,68,154,221,150,24,78,139,31,173,160,71,99,13,140,101,111,59,33,111,234,218,113,223,203,149,198,174,124,168,148,107,23,203,180,
66,123,215,27,152,200,79,250,105,205,155,183,54,215,36,95,139,247,39,141,120,197,50,153,174,148,243,148,66,82,158,132,188,25,99,54,175,135,210,140,111,104,140,169,76,254,103,0,153,19,148,17,185,213,214,
59,166,126,74,99,46,222,125,243,6,78,185,232,200,28,228,244,221,18,168,144,110,208,103,46,239,73,121,146,235,216,155,118,45,174,189,235,74,154,111,88,156,221,36,218,222,162,95,133,234,236,26,62,110,133,
99,52,169,84,229,178,146,133,86,10,64,51,231,73,40,78,70,155,151,113,206,222,242,130,36,98,53,183,58,177,202,199,93,100,11,89,9,80,211,90,96,46,157,157,4,70,158,132,80,156,111,193,205,102,181,69,68,186,
5,170,38,11,255,86,138,44,47,55,25,218,109,106,147,5,218,102,24,153,92,152,41,1,163,33,133,165,60,9,121,3,22,96,148,254,6,111,50,43,221,120,186,189,166,89,155,189,104,117,16,37,67,158,164,16,16,82,230,
22,157,91,49,199,144,185,85,27,77,121,18,146,198,26,98,245,22,184,126,206,203,91,80,124,100,165,215,148,109,18,181,151,142,52,187,54,221,91,99,156,36,146,170,245,82,174,234,45,79,199,146,26,24,132,81,
76,121,18,194,72,243,234,17,231,202,129,95,174,99,201,152,172,103,62,223,156,151,93,162,84,217,229,38,153,62,86,203,110,127,77,222,231,100,162,187,200,173,215,145,149,218,19,18,158,84,148,39,185,94,61,
40,46,111,58,33,165,249,214,137,179,107,12,106,114,105,200,100,214,82,110,69,78,217,69,186,0,0,173,221,179,211,250,162,43,6,172,114,89,245,60,183,12,50,32,149,130,95,240,41,79,66,40,206,181,151,230,155,
39,78,103,70,105,228,242,176,50,21,229,74,97,103,219,99,150,103,80,141,237,190,255,34,109,254,231,170,107,73,69,121,18,70,159,215,189,56,237,181,56,81,64,94,225,223,86,243,52,145,95,128,58,159,83,77,150,
254,176,128,144,44,73,71,40,208,235,250,248,57,222,181,91,179,93,116,44,99,156,254,33,17,39,4,229,73,8,197,121,253,138,115,217,254,230,166,183,11,187,66,81,230,36,48,149,146,131,228,9,161,56,175,50,105,
174,245,250,76,221,182,213,202,103,138,206,152,19,157,195,159,242,229,61,179,66,34,172,36,79,200,245,73,231,252,156,43,157,9,254,102,69,155,23,91,159,126,181,107,215,119,23,228,37,228,44,132,171,56,218,
49,238,73,194,192,36,29,71,50,233,116,162,60,9,185,30,35,207,238,173,213,75,62,206,126,151,155,233,23,123,141,149,36,122,185,251,181,236,241,203,122,241,221,255,100,199,115,40,79,66,174,227,232,51,107,
162,230,5,180,138,101,150,175,166,252,230,90,236,203,229,108,35,125,44,229,73,200,117,29,125,218,92,29,12,147,27,34,233,154,174,38,25,15,41,101,171,52,219,247,236,8,133,85,28,87,254,216,41,79,66,174,83,
76,126,160,120,71,132,105,160,1,237,132,146,230,248,174,139,97,93,171,72,19,80,158,132,92,207,77,246,68,138,153,64,87,144,134,148,242,186,27,11,187,218,227,165,60,9,185,206,5,250,70,37,114,189,66,121,
18,114,157,11,148,92,25,92,134,131,16,66,40,79,66,8,161,60,9,33,132,242,36,132,16,202,147,16,66,40,79,66,8,33,148,39,33,132,80,158,132,16,66,121,18,66,8,229,73,8,33,148,39,33,132,16,202,147,16,66,40,79,
66,8,161,60,9,33,132,242,36,132,16,202,147,16,66,8,229,73,8,33,148,39,33,132,80,158,132,16,66,121,18,66,8,229,73,8,33,132,242,36,132,16,202,147,16,66,40,79,66,8,161,60,9,33,132,242,36,132,16,66,121,18,
66,8,229,73,8,33,148,39,33,132,80,158,132,16,66,121,18,66,8,161,60,9,33,132,242,36,132,16,202,147,16,66,40,79,66,8,161,60,9,33,132,80,158,132,16,66,121,18,66,8,229,73,8,33,148,39,33,132,80,158,132,16,
66,40,79,66,8,161,60,9,33,132,242,36,132,16,202,147,16,66,40,79,66,8,33,148,39,33,132,80,158,132,16,66,121,18,66,8,229,73,8,33,148,39,33,132,16,202,147,16,66,40,79,66,8,161,60,9,33,132,242,36,132,16,202,
147,16,66,8,229,73,8,33,148,39,33,132,80,158,132,16,66,121,18,66,8,229,73,8,33,132,242,36,132,16,202,147,16,66,40,79,66,8,161,60,9,33,132,242,36,132,16,66,121,18,66,8,229,73,8,33,148,39,33,132,80,158,
132,16,66,121,18,66,8,161,60,9,33,132,242,36,132,16,202,147,16,66,40,79,66,8,161,60,9,33,132,80,158,132,16,66,121,18,66,8,229,73,8,33,148,39,33,132,80,158,132,16,66,40,79,66,8,161,60,9,33,132,242,36,132,
16,202,147,16,66,40,79,66,8,33,148,39,33,132,80,158,132,16,66,121,18,66,8,229,73,8,33,148,39,33,132,80,158,132,16,66,40,79,66,8,161,60,9,33,132,242,36,132,16,202,147,16,66,40,79,66,8,33,148,39,33,132,
80,158,132,16,66,121,18,66,8,229,73,8,33,148,39,33,132,16,202,147,16,66,40,79,66,8,161,60,9,33,132,242,36,132,16,202,147,16,66,8,229,73,8,33,148,39,33,132,80,158,132,16,66,121,18,66,8,229,73,8,33,132,
242,36,132,16,202,147,16,66,40,79,66,8,161,60,9,33,132,242,36,132,16,66,121,18,66,8,229,73,8,33,148,39,33,132,80,158,132,16,66,121,18,66,8,161,60,9,33,132,242,36,132,16,202,147,16,66,40,79,66,8,161,60,
9,33,132,80,158,132,16,66,121,18,66,8,229,73,8,33,148,39,33,132,80,158,132,16,66,40,79,66,8,161,60,9,33,132,242,36,132,16,202,147,16,66,40,79,66,8,33,93,241,86,253,72,107,147,111,173,239,157,95,132,16,
114,53,211,205,91,109,14,187,12,143,121,151,251,162,176,22,198,152,236,103,99,12,132,16,217,119,66,8,185,218,229,217,233,48,92,65,16,184,122,121,2,48,198,64,27,3,147,124,105,173,33,165,107,249,75,41,41,
79,66,200,53,35,207,182,175,84,168,111,70,179,93,199,49,180,214,208,90,35,142,99,68,81,4,165,20,0,64,41,5,33,4,229,73,8,185,38,228,153,247,88,28,199,136,83,191,197,241,218,203,51,125,161,176,217,68,24,
134,240,60,247,84,223,247,179,168,147,242,36,132,92,43,145,103,20,69,104,38,62,11,155,205,76,164,107,46,207,102,24,162,209,104,160,222,104,192,175,213,92,52,170,53,60,207,163,60,9,33,215,156,60,227,56,
70,179,217,68,173,86,67,189,209,64,163,209,64,51,12,215,94,158,245,90,13,213,106,21,190,239,3,0,162,48,68,80,40,64,41,5,37,37,64,121,18,66,174,1,121,194,90,232,164,207,38,108,54,81,111,52,80,169,84,80,
173,86,81,79,2,195,53,149,103,155,56,163,8,197,98,17,65,16,64,41,5,41,4,229,73,8,185,102,228,105,146,188,103,152,180,168,171,213,42,42,139,139,168,86,171,107,47,207,197,74,37,19,103,189,94,71,33,8,224,
121,30,148,231,57,121,2,0,229,73,8,185,186,237,9,0,78,158,73,71,81,51,12,179,150,117,234,185,213,32,142,159,56,193,209,237,132,16,114,153,112,122,38,33,132,80,158,132,16,66,121,18,66,8,229,73,8,33,148,
39,33,132,80,158,132,16,66,40,79,66,8,161,60,9,33,132,242,36,132,16,202,147,16,66,40,79,66,8,33,148,39,33,132,80,158,132,16,66,121,18,66,8,229,73,8,33,148,39,33,132,16,202,147,16,66,40,79,66,8,185,218,
88,245,26,70,143,63,254,56,250,251,250,80,46,151,81,234,233,225,26,70,132,144,107,143,85,172,97,244,71,127,244,71,107,43,207,190,222,94,12,12,12,160,127,96,0,229,158,30,20,242,171,103,74,9,65,121,18,66,
174,1,121,90,0,38,93,122,56,12,209,108,52,80,45,149,224,121,158,91,93,115,173,35,207,222,222,94,244,15,12,96,112,112,16,125,125,125,40,21,139,92,183,157,16,114,141,185,179,251,186,237,126,16,0,0,226,56,
94,123,121,150,74,37,148,123,122,208,219,219,139,190,190,62,244,244,244,160,80,40,192,243,60,23,121,82,158,132,144,107,64,158,214,90,24,99,16,199,49,194,48,132,87,173,194,90,139,40,105,190,175,185,60,
11,133,2,138,165,18,122,74,37,148,203,229,76,158,190,239,83,158,132,144,107,78,158,81,20,193,243,156,2,227,40,66,189,84,66,161,80,88,123,121,122,158,7,223,247,17,20,10,8,130,192,201,180,88,116,157,70,
74,81,158,132,144,107,70,158,90,107,40,165,178,166,122,144,4,130,169,76,215,84,158,42,145,164,82,42,19,105,250,93,74,153,69,159,132,16,114,181,203,51,245,149,214,26,158,231,101,65,160,122,51,228,41,0,
72,41,161,18,81,74,41,179,158,118,70,158,132,144,107,73,158,169,64,179,47,33,90,163,134,214,92,158,169,28,211,23,73,126,78,255,205,200,147,16,114,45,200,211,24,179,204,97,233,104,161,203,113,216,234,99,
212,100,163,34,247,189,219,23,33,132,92,205,172,228,174,52,56,92,45,156,158,73,8,33,87,0,229,73,8,33,148,39,33,132,80,158,132,16,66,121,18,66,8,229,73,8,33,148,39,33,132,16,202,147,16,66,40,79,66,8,161,
60,9,33,132,242,36,132,16,202,147,16,66,8,229,73,8,33,148,39,33,132,80,158,132,16,66,121,18,66,8,229,73,8,33,132,242,36,132,16,202,147,16,66,40,79,66,8,161,60,9,33,132,242,36,132,16,66,121,18,66,8,229,
73,8,33,148,39,33,132,80,158,132,16,66,121,18,66,8,161,60,9,33,132,242,36,132,16,202,147,16,66,40,79,66,8,161,60,9,33,132,80,158,132,16,66,121,18,66,8,229,73,8,33,148,39,33,132,80,158,132,16,66,40,79,
66,8,161,60,9,33,132,242,36,132,16,202,147,16,66,40,79,66,8,33,148,39,33,132,80,158,132,16,66,121,18,66,8,229,73,8,33,148,39,33,132,16,202,147,16,66,40,79,66,8,161,60,9,33,132,242,36,132,16,202,147,16,
66,8,229,73,8,33,148,39,33,132,80,158,132,16,66,121,18,66,8,229,73,8,33,132,242,36,132,16,202,147,16,66,40,79,66,8,161,60,9,33,132,242,36,132,16,66,121,18,66,8,229,73,8,33,148,39,33,132,80,158,132,16,
66,121,18,66,8,161,60,9,33,132,242,36,132,16,202,147,16,66,40,79,66,8,161,60,9,33,132,80,158,132,16,66,121,18,66,8,229,73,8,33,148,39,33,132,80,158,132,16,66,40,79,66,8,161,60,9,33,132,242,36,132,16,202,
147,16,66,40,79,66,8,33,148,39,33,132,80,158,132,16,66,121,18,66,8,229,73,8,33,148,39,33,132,16,202,147,16,66,40,79,66,8,161,60,9,33,132,242,36,132,16,202,147,16,66,40,79,66,8,33,148,39,33,132,80,158,
132,16,114,117,226,173,250,145,214,38,223,90,223,59,191,8,33,228,106,166,155,183,218,28,118,25,30,243,46,247,69,97,45,140,49,217,207,198,24,8,33,178,239,132,16,114,181,203,179,211,97,184,130,32,112,245,
242,4,96,140,129,54,6,38,249,210,90,67,74,215,242,151,82,82,158,132,144,107,70,158,109,95,169,80,223,140,102,187,142,99,104,173,161,181,70,28,199,136,162,8,74,41,0,128,82,10,66,8,202,147,16,114,77,200,
51,239,177,56,142,17,167,126,139,227,181,151,103,250,66,97,179,137,48,12,225,121,238,169,190,239,103,81,39,229,73,8,185,86,34,207,40,138,208,76,124,22,54,155,153,72,215,92,158,205,48,68,163,209,64,189,
209,128,95,171,185,104,84,107,120,158,71,121,18,66,174,57,121,198,113,140,102,179,137,90,173,134,122,163,129,70,163,129,102,24,174,189,60,235,181,26,170,213,42,124,223,7,0,68,97,136,160,80,128,82,10,74,
74,128,242,36,132,92,3,242,132,181,208,73,159,77,216,108,162,222,104,160,82,169,160,90,173,162,158,4,134,107,42,207,54,113,70,17,138,197,34,130,32,128,82,10,82,8,202,147,16,114,205,200,211,36,121,207,
48,105,81,87,171,85,84,22,23,81,173,86,215,94,158,139,149,74,38,206,122,189,142,66,16,192,243,60,40,207,115,242,4,0,202,147,16,114,117,219,19,0,156,60,147,142,162,102,24,102,45,235,212,115,171,65,28,63,
113,130,163,219,9,33,228,50,225,244,76,66,8,161,60,9,33,132,242,36,132,16,202,147,16,66,40,79,66,8,161,60,9,33,132,80,158,132,16,66,121,18,66,8,229,73,8,33,148,39,33,132,80,158,132,16,66,40,79,66,8,161,
60,9,33,132,242,36,132,144,239,13,254,127,218,13,194,0,8,18,181,78,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* EditorGUI::chainsawbg_png = (const char*) resource_EditorGUI_chainsawbg_png;
const int EditorGUI::chainsawbg_pngSize = 31053;
