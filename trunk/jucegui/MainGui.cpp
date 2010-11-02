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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MainGui.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainGui::MainGui ()
    : component (0),
      component2 (0),
      component3 (0),
      component4 (0),
      stereoDepth (0),
      oneOsc (0),
      fiveOsc (0),
      threeOsc (0),
      textButton4 (0),
      frequency (0),
      resonance (0),
      filterEffect (0),
      filterAttack (0),
      filterDecay (0),
      filterSustain (0),
      filterRelease (0),
      label (0),
      label2 (0),
      label3 (0),
      label4 (0),
      label5 (0),
      label6 (0),
      label7 (0),
      volAttack (0),
      volDecay (0),
      volSustain (0),
      volRelease (0),
      label9 (0),
      label10 (0),
      label11 (0),
      label12 (0),
      masterVolume (0),
      label13 (0),
      panning (0),
      label8 (0),
      label14 (0),
      label15 (0),
      label16 (0),
      label17 (0),
      label18 (0),
      label19 (0),
      label20 (0),
      internalCachedImage1 (0)
{
    addAndMakeVisible (component = new OscGroupEditor());
    addAndMakeVisible (component2 = new OscGroupEditor());
    addAndMakeVisible (component3 = new OscGroupEditor());
    addAndMakeVisible (component4 = new OscGroupEditor());
    addAndMakeVisible (stereoDepth = new Slider (T("Stereo Depth")));
    stereoDepth->setTooltip (T("Stereo Depth"));
    stereoDepth->setRange (0, 10, 0);
    stereoDepth->setSliderStyle (Slider::LinearHorizontal);
    stereoDepth->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    stereoDepth->addListener (this);

    addAndMakeVisible (oneOsc = new TextButton (T("new button")));
    oneOsc->setButtonText (T("1"));
    oneOsc->setRadioGroupId (1);
    oneOsc->addButtonListener (this);

    addAndMakeVisible (fiveOsc = new TextButton (T("new button")));
    fiveOsc->setButtonText (T("5"));
    fiveOsc->setRadioGroupId (1);
    fiveOsc->addButtonListener (this);

    addAndMakeVisible (threeOsc = new TextButton (T("new button")));
    threeOsc->setButtonText (T("3"));
    threeOsc->setRadioGroupId (1);
    threeOsc->addButtonListener (this);

    addAndMakeVisible (textButton4 = new TextButton (T("sevenOsc")));
    textButton4->setButtonText (T("7"));
    textButton4->setRadioGroupId (1);
    textButton4->addButtonListener (this);

    addAndMakeVisible (frequency = new Slider (T("new slider")));
    frequency->setRange (0, 10, 0);
    frequency->setSliderStyle (Slider::Rotary);
    frequency->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    frequency->addListener (this);

    addAndMakeVisible (resonance = new Slider (T("resonance")));
    resonance->setRange (0, 10, 0);
    resonance->setSliderStyle (Slider::Rotary);
    resonance->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    resonance->addListener (this);

    addAndMakeVisible (filterEffect = new Slider (T("new slider")));
    filterEffect->setRange (0, 10, 0);
    filterEffect->setSliderStyle (Slider::Rotary);
    filterEffect->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    filterEffect->addListener (this);

    addAndMakeVisible (filterAttack = new Slider (T("new slider")));
    filterAttack->setRange (0, 10, 0);
    filterAttack->setSliderStyle (Slider::Rotary);
    filterAttack->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    filterAttack->addListener (this);

    addAndMakeVisible (filterDecay = new Slider (T("new slider")));
    filterDecay->setRange (0, 10, 0);
    filterDecay->setSliderStyle (Slider::Rotary);
    filterDecay->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    filterDecay->addListener (this);

    addAndMakeVisible (filterSustain = new Slider (T("new slider")));
    filterSustain->setRange (0, 10, 0);
    filterSustain->setSliderStyle (Slider::Rotary);
    filterSustain->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    filterSustain->addListener (this);

    addAndMakeVisible (filterRelease = new Slider (T("new slider")));
    filterRelease->setRange (0, 10, 0);
    filterRelease->setSliderStyle (Slider::Rotary);
    filterRelease->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    filterRelease->addListener (this);

    addAndMakeVisible (label = new Label (T("new label"),
                                          T("Freq")));
    label->setFont (Font (15.0000f, Font::plain));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label2 = new Label (T("new label"),
                                           T("Reso")));
    label2->setFont (Font (15.0000f, Font::plain));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label3 = new Label (T("new label"),
                                           T("E")));
    label3->setFont (Font (15.0000f, Font::plain));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label4 = new Label (T("new label"),
                                           T("A")));
    label4->setFont (Font (15.0000f, Font::plain));
    label4->setJustificationType (Justification::centred);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label5 = new Label (T("new label"),
                                           T("D")));
    label5->setFont (Font (15.0000f, Font::plain));
    label5->setJustificationType (Justification::centred);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label6 = new Label (T("new label"),
                                           T("S")));
    label6->setFont (Font (15.0000f, Font::plain));
    label6->setJustificationType (Justification::centred);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label7 = new Label (T("new label"),
                                           T("R\n")));
    label7->setFont (Font (15.0000f, Font::plain));
    label7->setJustificationType (Justification::centred);
    label7->setEditable (false, false, false);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (volAttack = new Slider (T("new slider")));
    volAttack->setRange (0, 10, 0);
    volAttack->setSliderStyle (Slider::Rotary);
    volAttack->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    volAttack->addListener (this);

    addAndMakeVisible (volDecay = new Slider (T("new slider")));
    volDecay->setRange (0, 10, 0);
    volDecay->setSliderStyle (Slider::Rotary);
    volDecay->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    volDecay->addListener (this);

    addAndMakeVisible (volSustain = new Slider (T("new slider")));
    volSustain->setRange (0, 10, 0);
    volSustain->setSliderStyle (Slider::Rotary);
    volSustain->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    volSustain->addListener (this);

    addAndMakeVisible (volRelease = new Slider (T("new slider")));
    volRelease->setRange (0, 10, 0);
    volRelease->setSliderStyle (Slider::Rotary);
    volRelease->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    volRelease->addListener (this);

    addAndMakeVisible (label9 = new Label (T("new label"),
                                           T("A")));
    label9->setFont (Font (15.0000f, Font::plain));
    label9->setJustificationType (Justification::centred);
    label9->setEditable (false, false, false);
    label9->setColour (TextEditor::textColourId, Colours::black);
    label9->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label10 = new Label (T("new label"),
                                            T("D")));
    label10->setFont (Font (15.0000f, Font::plain));
    label10->setJustificationType (Justification::centred);
    label10->setEditable (false, false, false);
    label10->setColour (TextEditor::textColourId, Colours::black);
    label10->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label11 = new Label (T("new label"),
                                            T("S")));
    label11->setFont (Font (15.0000f, Font::plain));
    label11->setJustificationType (Justification::centred);
    label11->setEditable (false, false, false);
    label11->setColour (TextEditor::textColourId, Colours::black);
    label11->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label12 = new Label (T("new label"),
                                            T("R\n")));
    label12->setFont (Font (15.0000f, Font::plain));
    label12->setJustificationType (Justification::centred);
    label12->setEditable (false, false, false);
    label12->setColour (TextEditor::textColourId, Colours::black);
    label12->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (masterVolume = new Slider (T("new slider")));
    masterVolume->setRange (0, 10, 0);
    masterVolume->setSliderStyle (Slider::Rotary);
    masterVolume->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    masterVolume->addListener (this);

    addAndMakeVisible (label13 = new Label (T("new label"),
                                            T("Vol")));
    label13->setFont (Font (15.0000f, Font::plain));
    label13->setJustificationType (Justification::centred);
    label13->setEditable (false, false, false);
    label13->setColour (TextEditor::textColourId, Colours::black);
    label13->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (panning = new Slider (T("new slider")));
    panning->setRange (0, 10, 0);
    panning->setSliderStyle (Slider::LinearHorizontal);
    panning->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    panning->addListener (this);

    addAndMakeVisible (label8 = new Label (T("new label"),
                                           T("Pan")));
    label8->setFont (Font (15.0000f, Font::plain));
    label8->setJustificationType (Justification::centred);
    label8->setEditable (false, false, false);
    label8->setColour (TextEditor::textColourId, Colours::black);
    label8->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label14 = new Label (T("new label"),
                                            T("Volume")));
    label14->setFont (Font (15.0000f, Font::plain));
    label14->setJustificationType (Justification::centredLeft);
    label14->setEditable (false, false, false);
    label14->setColour (TextEditor::textColourId, Colours::black);
    label14->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label15 = new Label (T("new label"),
                                            T("Filter")));
    label15->setFont (Font (15.0000f, Font::plain));
    label15->setJustificationType (Justification::centredLeft);
    label15->setEditable (false, false, false);
    label15->setColour (TextEditor::textColourId, Colours::black);
    label15->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label16 = new Label (T("new label"),
                                            T("OSC group 3")));
    label16->setFont (Font (15.0000f, Font::plain));
    label16->setJustificationType (Justification::centredLeft);
    label16->setEditable (false, false, false);
    label16->setColour (Label::textColourId, Colours::white);
    label16->setColour (TextEditor::textColourId, Colours::black);
    label16->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label17 = new Label (T("new label"),
                                            T("OSC group 2")));
    label17->setFont (Font (15.0000f, Font::plain));
    label17->setJustificationType (Justification::centredLeft);
    label17->setEditable (false, false, false);
    label17->setColour (Label::textColourId, Colours::white);
    label17->setColour (TextEditor::textColourId, Colours::black);
    label17->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label18 = new Label (T("new label"),
                                            T("OSC group 1")));
    label18->setFont (Font (15.0000f, Font::plain));
    label18->setJustificationType (Justification::centredLeft);
    label18->setEditable (false, false, false);
    label18->setColour (Label::backgroundColourId, Colour (0xffffff));
    label18->setColour (Label::textColourId, Colours::white);
    label18->setColour (TextEditor::textColourId, Colours::black);
    label18->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label19 = new Label (T("new label"),
                                            T("Main OSC")));
    label19->setFont (Font (15.0000f, Font::plain));
    label19->setJustificationType (Justification::centredLeft);
    label19->setEditable (false, false, false);
    label19->setColour (Label::textColourId, Colours::white);
    label19->setColour (TextEditor::textColourId, Colours::black);
    label19->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label20 = new Label (T("new label"),
                                            T("Stereo depth")));
    label20->setFont (Font (15.0000f, Font::plain));
    label20->setJustificationType (Justification::centredLeft);
    label20->setEditable (false, false, false);
    label20->setColour (TextEditor::textColourId, Colours::black);
    label20->setColour (TextEditor::backgroundColourId, Colour (0x0));

    internalCachedImage1 = ImageCache::getFromMemory (screenshot_png, screenshot_pngSize);

    //[UserPreSize]
    //[/UserPreSize]

    setSize (320, 240);

    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MainGui::~MainGui()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (component);
    deleteAndZero (component2);
    deleteAndZero (component3);
    deleteAndZero (component4);
    deleteAndZero (stereoDepth);
    deleteAndZero (oneOsc);
    deleteAndZero (fiveOsc);
    deleteAndZero (threeOsc);
    deleteAndZero (textButton4);
    deleteAndZero (frequency);
    deleteAndZero (resonance);
    deleteAndZero (filterEffect);
    deleteAndZero (filterAttack);
    deleteAndZero (filterDecay);
    deleteAndZero (filterSustain);
    deleteAndZero (filterRelease);
    deleteAndZero (label);
    deleteAndZero (label2);
    deleteAndZero (label3);
    deleteAndZero (label4);
    deleteAndZero (label5);
    deleteAndZero (label6);
    deleteAndZero (label7);
    deleteAndZero (volAttack);
    deleteAndZero (volDecay);
    deleteAndZero (volSustain);
    deleteAndZero (volRelease);
    deleteAndZero (label9);
    deleteAndZero (label10);
    deleteAndZero (label11);
    deleteAndZero (label12);
    deleteAndZero (masterVolume);
    deleteAndZero (label13);
    deleteAndZero (panning);
    deleteAndZero (label8);
    deleteAndZero (label14);
    deleteAndZero (label15);
    deleteAndZero (label16);
    deleteAndZero (label17);
    deleteAndZero (label18);
    deleteAndZero (label19);
    deleteAndZero (label20);
    ImageCache::release (internalCachedImage1);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainGui::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff464973));

    g.setColour (Colours::black);
    g.drawImage (internalCachedImage1,
                 0, 0, 320, 240,
                 0, 0, internalCachedImage1->getWidth(), internalCachedImage1->getHeight());

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainGui::resized()
{
    component->setBounds (72, 32, 202, 24);
    component2->setBounds (72, 64, 202, 24);
    component3->setBounds (72, 96, 202, 24);
    component4->setBounds (72, 128, 202, 24);
    stereoDepth->setBounds (72, 8, 240, 24);
    oneOsc->setBounds (272, 32, 40, 24);
    fiveOsc->setBounds (272, 96, 40, 24);
    threeOsc->setBounds (272, 64, 40, 24);
    textButton4->setBounds (272, 128, 40, 24);
    frequency->setBounds (72, 168, 31, 32);
    resonance->setBounds (104, 168, 31, 32);
    filterEffect->setBounds (152, 168, 31, 32);
    filterAttack->setBounds (184, 168, 31, 32);
    filterDecay->setBounds (216, 168, 31, 32);
    filterSustain->setBounds (248, 168, 31, 32);
    filterRelease->setBounds (280, 168, 31, 32);
    label->setBounds (72, 152, 32, 24);
    label2->setBounds (104, 152, 32, 24);
    label3->setBounds (152, 152, 32, 24);
    label4->setBounds (184, 152, 32, 24);
    label5->setBounds (216, 152, 32, 24);
    label6->setBounds (248, 152, 32, 24);
    label7->setBounds (280, 152, 32, 24);
    volAttack->setBounds (72, 208, 31, 32);
    volDecay->setBounds (104, 208, 31, 32);
    volSustain->setBounds (136, 208, 31, 32);
    volRelease->setBounds (168, 208, 31, 32);
    label9->setBounds (72, 192, 32, 24);
    label10->setBounds (104, 192, 32, 24);
    label11->setBounds (136, 192, 32, 24);
    label12->setBounds (168, 192, 32, 24);
    masterVolume->setBounds (280, 208, 31, 32);
    label13->setBounds (280, 192, 32, 24);
    panning->setBounds (208, 208, 72, 24);
    label8->setBounds (224, 192, 32, 24);
    label14->setBounds (8, 208, 64, 24);
    label15->setBounds (8, 168, 64, 24);
    label16->setBounds (8, 128, 64, 24);
    label17->setBounds (8, 96, 64, 24);
    label18->setBounds (8, 64, 64, 24);
    label19->setBounds (8, 32, 64, 24);
    label20->setBounds (8, 8, 64, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainGui::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == stereoDepth)
    {
        //[UserSliderCode_stereoDepth] -- add your slider handling code here..
        //[/UserSliderCode_stereoDepth]
    }
    else if (sliderThatWasMoved == frequency)
    {
        //[UserSliderCode_frequency] -- add your slider handling code here..
        //[/UserSliderCode_frequency]
    }
    else if (sliderThatWasMoved == resonance)
    {
        //[UserSliderCode_resonance] -- add your slider handling code here..
        //[/UserSliderCode_resonance]
    }
    else if (sliderThatWasMoved == filterEffect)
    {
        //[UserSliderCode_filterEffect] -- add your slider handling code here..
        //[/UserSliderCode_filterEffect]
    }
    else if (sliderThatWasMoved == filterAttack)
    {
        //[UserSliderCode_filterAttack] -- add your slider handling code here..
        //[/UserSliderCode_filterAttack]
    }
    else if (sliderThatWasMoved == filterDecay)
    {
        //[UserSliderCode_filterDecay] -- add your slider handling code here..
        //[/UserSliderCode_filterDecay]
    }
    else if (sliderThatWasMoved == filterSustain)
    {
        //[UserSliderCode_filterSustain] -- add your slider handling code here..
        //[/UserSliderCode_filterSustain]
    }
    else if (sliderThatWasMoved == filterRelease)
    {
        //[UserSliderCode_filterRelease] -- add your slider handling code here..
        //[/UserSliderCode_filterRelease]
    }
    else if (sliderThatWasMoved == volAttack)
    {
        //[UserSliderCode_volAttack] -- add your slider handling code here..
        //[/UserSliderCode_volAttack]
    }
    else if (sliderThatWasMoved == volDecay)
    {
        //[UserSliderCode_volDecay] -- add your slider handling code here..
        //[/UserSliderCode_volDecay]
    }
    else if (sliderThatWasMoved == volSustain)
    {
        //[UserSliderCode_volSustain] -- add your slider handling code here..
        //[/UserSliderCode_volSustain]
    }
    else if (sliderThatWasMoved == volRelease)
    {
        //[UserSliderCode_volRelease] -- add your slider handling code here..
        //[/UserSliderCode_volRelease]
    }
    else if (sliderThatWasMoved == masterVolume)
    {
        //[UserSliderCode_masterVolume] -- add your slider handling code here..
        //[/UserSliderCode_masterVolume]
    }
    else if (sliderThatWasMoved == panning)
    {
        //[UserSliderCode_panning] -- add your slider handling code here..
        //[/UserSliderCode_panning]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void MainGui::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == oneOsc)
    {
        //[UserButtonCode_oneOsc] -- add your button handler code here..
        //[/UserButtonCode_oneOsc]
    }
    else if (buttonThatWasClicked == fiveOsc)
    {
        //[UserButtonCode_fiveOsc] -- add your button handler code here..
        //[/UserButtonCode_fiveOsc]
    }
    else if (buttonThatWasClicked == threeOsc)
    {
        //[UserButtonCode_threeOsc] -- add your button handler code here..
        //[/UserButtonCode_threeOsc]
    }
    else if (buttonThatWasClicked == textButton4)
    {
        //[UserButtonCode_textButton4] -- add your button handler code here..
        //[/UserButtonCode_textButton4]
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

<JUCER_COMPONENT documentType="Component" className="MainGui" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="0" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="1" initialWidth="320" initialHeight="240">
  <BACKGROUND backgroundColour="ff464973">
    <IMAGE pos="0 0 320 240" resource="screenshot_png" opacity="1" mode="0"/>
  </BACKGROUND>
  <JUCERCOMP name="" id="d34eca899168cec4" memberName="component" virtualName=""
             explicitFocusOrder="0" pos="72 32 202 24" sourceFile="OscGroupEditor.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="a88860a9abddd990" memberName="component2" virtualName=""
             explicitFocusOrder="0" pos="72 64 202 24" sourceFile="OscGroupEditor.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="1c8e336c99dff7da" memberName="component3" virtualName=""
             explicitFocusOrder="0" pos="72 96 202 24" sourceFile="OscGroupEditor.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="de3009f004b19f8f" memberName="component4" virtualName=""
             explicitFocusOrder="0" pos="72 128 202 24" sourceFile="OscGroupEditor.cpp"
             constructorParams=""/>
  <SLIDER name="Stereo Depth" id="c96f39b99f818163" memberName="stereoDepth"
          virtualName="" explicitFocusOrder="0" pos="72 8 240 24" tooltip="Stereo Depth"
          min="0" max="10" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="new button" id="5d2039d7d4c2c79" memberName="oneOsc" virtualName=""
              explicitFocusOrder="0" pos="272 32 40 24" buttonText="1" connectedEdges="0"
              needsCallback="1" radioGroupId="1"/>
  <TEXTBUTTON name="new button" id="6ae2e59f3379d745" memberName="fiveOsc"
              virtualName="" explicitFocusOrder="0" pos="272 96 40 24" buttonText="5"
              connectedEdges="0" needsCallback="1" radioGroupId="1"/>
  <TEXTBUTTON name="new button" id="ac2fb0fcdb3bb813" memberName="threeOsc"
              virtualName="" explicitFocusOrder="0" pos="272 64 40 24" buttonText="3"
              connectedEdges="0" needsCallback="1" radioGroupId="1"/>
  <TEXTBUTTON name="sevenOsc" id="619489a70e99167e" memberName="textButton4"
              virtualName="" explicitFocusOrder="0" pos="272 128 40 24" buttonText="7"
              connectedEdges="0" needsCallback="1" radioGroupId="1"/>
  <SLIDER name="new slider" id="5d053565f77b1fe8" memberName="frequency"
          virtualName="" explicitFocusOrder="0" pos="72 168 31 32" min="0"
          max="10" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="resonance" id="2ca27fa6719cf615" memberName="resonance"
          virtualName="" explicitFocusOrder="0" pos="104 168 31 32" min="0"
          max="10" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="dfcfa80002a979cf" memberName="filterEffect"
          virtualName="" explicitFocusOrder="0" pos="152 168 31 32" min="0"
          max="10" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="57c254856403dbdb" memberName="filterAttack"
          virtualName="" explicitFocusOrder="0" pos="184 168 31 32" min="0"
          max="10" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="1667ab36fb17e7b1" memberName="filterDecay"
          virtualName="" explicitFocusOrder="0" pos="216 168 31 32" min="0"
          max="10" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="d9265fc9ae8ed62c" memberName="filterSustain"
          virtualName="" explicitFocusOrder="0" pos="248 168 31 32" min="0"
          max="10" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="9593b1dd820ae867" memberName="filterRelease"
          virtualName="" explicitFocusOrder="0" pos="280 168 31 32" min="0"
          max="10" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="f3d374d5adad31eb" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="72 152 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Freq" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="7369d53022eaf271" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="104 152 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Reso" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="8e2400448b9071b" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="152 152 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="E" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="1b50f8d1c9ab0a3" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="184 152 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="A" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="75ce1d715c25901" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="216 152 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="D" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="829abcf57361b8a3" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="248 152 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="S" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="5c9864dd37a34081" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="280 152 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="R&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="72b6e7ae2cedfd03" memberName="volAttack"
          virtualName="" explicitFocusOrder="0" pos="72 208 31 32" min="0"
          max="10" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="23f41f7d915294b1" memberName="volDecay"
          virtualName="" explicitFocusOrder="0" pos="104 208 31 32" min="0"
          max="10" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="41d22ff517e5f5d8" memberName="volSustain"
          virtualName="" explicitFocusOrder="0" pos="136 208 31 32" min="0"
          max="10" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="3acebc270bd909d4" memberName="volRelease"
          virtualName="" explicitFocusOrder="0" pos="168 208 31 32" min="0"
          max="10" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="4451810538b89dbb" memberName="label9" virtualName=""
         explicitFocusOrder="0" pos="72 192 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="A" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="943a6b198bc2830e" memberName="label10" virtualName=""
         explicitFocusOrder="0" pos="104 192 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="D" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="268312a82691def7" memberName="label11" virtualName=""
         explicitFocusOrder="0" pos="136 192 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="S" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="bd5e0a63b12710a6" memberName="label12" virtualName=""
         explicitFocusOrder="0" pos="168 192 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="R&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="6371e83ca581725a" memberName="masterVolume"
          virtualName="" explicitFocusOrder="0" pos="280 208 31 32" min="0"
          max="10" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="ed97d6a68864b2d0" memberName="label13" virtualName=""
         explicitFocusOrder="0" pos="280 192 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Vol" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="105d9761310776f8" memberName="panning"
          virtualName="" explicitFocusOrder="0" pos="208 208 72 24" min="0"
          max="10" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="a3f83d72f9b52aa" memberName="label8" virtualName=""
         explicitFocusOrder="0" pos="224 192 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Pan" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="3da2551768743443" memberName="label14" virtualName=""
         explicitFocusOrder="0" pos="8 208 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Volume" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="9a37005cdbcadb34" memberName="label15" virtualName=""
         explicitFocusOrder="0" pos="8 168 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Filter" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="437444efa21c8fd4" memberName="label16" virtualName=""
         explicitFocusOrder="0" pos="8 128 64 24" textCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="OSC group 3" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="db4420511c0a11a0" memberName="label17" virtualName=""
         explicitFocusOrder="0" pos="8 96 64 24" textCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="OSC group 2" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="fc64d1fda49f00c2" memberName="label18" virtualName=""
         explicitFocusOrder="0" pos="8 64 64 24" bkgCol="ffffff" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="OSC group 1" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="dc225bb981c46c82" memberName="label19" virtualName=""
         explicitFocusOrder="0" pos="8 32 64 24" textCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="Main OSC" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="36cf33f7301a9fdc" memberName="label20" virtualName=""
         explicitFocusOrder="0" pos="8 8 64 24" edTextCol="ff000000" edBkgCol="0"
         labelText="Stereo depth" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: screenshot_png, 3582, "../../../Desktop/Screenshot.png"
static const unsigned char resource_MainGui_screenshot_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,1,64,0,0,0,240,8,6,0,0,0,113,45,189,107,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,6,
98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,217,5,24,11,46,30,89,245,204,233,0,0,13,126,73,68,65,84,120,218,237,221,65,
114,243,184,17,128,81,180,75,183,155,93,14,145,93,42,135,153,123,100,151,59,228,86,157,133,69,18,0,65,144,148,255,133,45,191,87,153,88,150,100,89,246,68,95,26,36,69,199,63,255,253,191,44,0,191,208,135,
95,1,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,252,110,143,163,
27,254,251,159,127,149,18,81,74,41,37,74,84,151,203,122,249,121,203,224,243,245,191,42,177,221,173,186,14,248,237,178,253,44,247,215,149,146,203,127,182,219,50,15,62,95,46,111,215,255,245,143,191,239,
5,112,30,191,56,9,97,31,188,81,232,162,255,86,192,111,202,94,214,45,200,174,7,219,117,235,253,226,89,141,37,132,163,207,151,8,70,148,200,242,25,193,73,96,30,179,39,184,196,239,56,118,131,219,134,209,251,
67,211,159,82,194,79,42,219,203,47,231,250,33,234,251,101,206,194,23,213,109,89,178,142,224,221,0,142,226,215,78,131,49,8,95,61,213,197,56,116,245,52,121,240,157,129,31,108,58,168,228,193,181,209,148,
239,104,10,140,56,8,97,19,197,124,78,128,91,4,239,79,128,179,248,61,167,191,254,242,112,2,92,30,231,44,112,131,95,154,20,194,155,12,133,253,171,186,155,18,71,11,199,122,83,96,116,95,182,125,158,107,99,
214,40,14,34,248,210,18,184,159,6,219,224,181,83,223,110,226,107,194,23,23,38,64,185,131,183,29,10,79,174,200,193,128,184,228,165,13,225,103,229,242,89,187,136,58,138,249,140,224,249,210,247,194,18,120,
137,216,89,252,238,132,176,143,225,60,126,146,8,239,52,253,245,175,238,92,239,48,155,0,99,48,56,238,195,23,213,245,185,69,240,185,125,240,165,37,112,179,77,175,156,196,111,13,221,100,2,172,67,41,121,240,
59,167,191,146,187,46,228,224,230,120,46,99,251,165,240,26,198,38,124,213,229,82,79,127,49,205,202,227,244,137,55,83,224,22,188,253,118,192,163,16,110,249,156,79,129,251,95,149,28,194,187,78,128,125,236,
150,79,162,13,98,238,151,194,107,24,179,221,54,184,70,112,217,14,88,31,22,115,63,128,91,244,170,161,110,157,252,70,59,65,218,16,246,225,187,50,5,134,129,16,222,109,2,204,249,148,117,56,253,149,40,89,237,
230,173,195,215,44,119,155,163,79,114,221,25,178,238,26,126,101,47,112,187,37,47,186,237,127,147,189,193,77,248,142,166,192,56,8,156,93,35,240,118,19,96,220,8,228,104,250,171,31,35,219,240,45,151,99,23,
198,207,136,230,73,67,206,183,1,246,219,2,215,105,112,28,191,40,71,83,96,31,189,201,182,64,7,60,195,251,76,128,107,208,114,55,214,228,250,105,174,245,107,163,87,77,127,37,74,62,215,182,227,8,118,239,46,
137,237,97,95,88,2,87,83,96,191,221,111,26,191,126,39,72,52,209,139,219,161,19,67,248,193,243,223,244,245,30,107,24,163,141,94,217,14,96,206,40,205,182,194,81,4,151,216,173,211,223,115,41,124,178,2,190,
184,13,176,244,123,132,203,113,252,234,169,175,127,251,220,240,151,112,246,206,16,211,33,252,156,222,229,165,1,38,235,75,213,107,58,158,65,203,117,109,92,31,204,188,76,131,251,8,118,239,38,110,191,253,
151,182,1,198,201,20,216,197,111,24,194,93,184,94,153,4,129,239,191,222,189,246,90,222,77,126,93,12,219,16,150,106,26,220,71,240,112,250,91,183,5,190,50,1,198,133,31,160,190,116,58,5,158,77,130,227,111,
44,141,240,22,11,224,233,146,184,9,94,23,194,172,142,107,217,194,183,141,119,103,203,220,23,183,1,198,254,159,225,244,87,218,37,242,139,75,224,221,243,140,23,127,34,224,219,36,47,118,87,71,127,246,191,
166,11,163,16,182,17,220,30,53,74,62,183,15,118,59,60,242,250,179,125,92,153,102,163,219,129,27,125,36,227,238,185,2,251,40,10,27,188,201,26,248,244,234,168,222,2,215,196,174,11,97,86,107,219,230,116,
87,89,133,239,249,181,125,255,182,229,240,252,236,92,143,235,63,87,61,253,149,238,29,38,213,94,225,211,248,69,119,194,232,120,237,23,10,252,200,69,112,187,90,124,158,8,43,247,33,28,71,176,110,66,174,199,
59,111,213,91,42,120,109,12,124,156,199,103,180,7,56,6,211,95,31,171,179,248,157,156,37,90,19,225,231,183,174,217,201,49,186,227,18,195,124,174,112,227,56,130,235,228,149,235,91,221,234,163,172,163,57,
255,75,156,61,177,179,0,198,112,249,123,117,250,187,243,183,66,230,3,161,218,193,207,93,253,182,51,91,187,236,45,93,216,158,183,228,104,27,96,185,54,5,14,150,193,179,134,60,166,43,222,171,63,243,96,250,
155,220,241,36,124,130,7,111,91,197,231,241,44,235,97,45,85,200,234,9,111,63,180,29,76,129,87,158,193,36,41,31,183,126,144,232,150,196,253,73,93,102,211,223,81,252,98,119,1,120,235,32,70,243,161,12,250,
112,120,106,189,254,252,162,209,63,238,189,142,60,46,61,225,136,227,31,164,196,180,248,49,88,63,199,241,141,87,231,106,224,71,200,249,235,250,57,201,85,139,217,201,32,216,31,227,18,195,165,246,178,92,
46,57,251,254,151,2,216,206,110,71,31,119,151,6,167,197,106,226,119,241,207,101,222,93,142,3,223,44,127,187,83,193,12,222,42,87,45,139,155,3,90,182,61,29,221,246,191,45,117,71,135,255,197,62,137,95,93,
2,31,244,41,142,43,21,183,39,187,246,172,51,17,226,7,63,122,193,187,123,13,199,197,22,76,110,137,152,183,232,198,227,79,247,2,79,227,51,60,169,115,183,157,239,112,250,59,216,19,124,253,140,8,254,151,5,
63,102,185,219,255,109,223,24,220,63,6,135,194,116,83,224,96,242,59,27,242,206,14,132,190,63,1,126,37,62,47,199,111,124,86,26,224,91,205,123,151,94,171,17,147,229,100,124,245,251,223,243,241,218,55,24,
255,128,187,61,193,245,52,57,121,188,113,252,4,15,222,39,138,87,35,184,223,243,112,184,7,120,216,137,123,189,184,30,192,139,103,111,185,91,228,227,248,1,239,28,194,175,111,223,143,155,173,250,35,75,96,
128,247,112,49,128,103,39,7,188,176,150,191,242,110,17,75,94,248,5,147,96,159,142,184,217,142,43,83,222,181,142,124,188,250,244,71,7,56,223,125,42,17,247,159,48,240,94,17,188,127,143,246,157,100,175,109,
253,179,4,6,44,129,1,126,167,243,247,2,199,252,175,182,197,124,64,45,227,1,53,190,180,252,13,111,15,129,111,39,51,239,188,138,203,250,102,181,88,14,142,206,238,182,237,99,123,174,191,139,143,124,118,20,
180,9,16,176,4,6,16,64,128,223,227,241,71,31,45,206,255,34,212,205,27,159,15,107,155,31,124,119,253,235,244,124,155,224,236,44,6,7,55,93,216,174,103,2,4,16,64,0,1,4,16,64,0,1,4,4,208,175,0,16,64,0,1,4,
16,64,0,1,4,16,64,0,1,4,16,64,0,1,4,16,64,0,1,4,16,64,0,1,4,16,64,0,1,4,16,64,0,1,4,16,64,0,1,4,16,64,0,1,4,16,64,0,1,4,16,64,0,1,4,16,64,0,1,4,16,64,0,1,4,4,16,64,0,1,4,16,64,0,1,4,16,64,0,1,4,16,64,
0,1,4,16,64,0,1,4,16,64,0,1,4,16,224,219,120,252,209,71,203,44,37,98,112,125,41,37,14,191,104,118,227,243,97,179,249,60,34,252,155,131,111,166,127,157,94,248,138,251,55,221,254,30,38,64,0,1,4,16,64,128,
114,101,27,224,115,187,222,209,150,186,209,245,159,215,45,183,244,31,63,239,145,25,213,230,194,243,237,128,237,83,74,255,230,224,71,203,38,49,237,70,191,220,125,204,87,30,249,66,39,76,128,128,37,48,128,
0,94,28,47,119,83,235,100,72,189,182,71,219,178,22,126,219,242,247,181,123,100,211,160,252,66,65,62,254,200,19,222,173,181,115,255,37,135,235,252,254,78,66,8,191,37,126,195,237,127,167,237,40,23,182,239,
93,235,136,37,48,96,9,124,30,238,124,161,180,249,226,195,154,2,225,253,38,191,188,55,196,189,186,50,189,241,192,31,175,125,195,28,255,64,213,55,239,111,201,217,90,62,103,191,48,49,132,119,10,95,251,154,
207,163,42,236,219,145,121,112,239,44,175,110,9,252,120,237,7,250,74,176,243,70,4,71,63,164,32,194,247,142,221,252,181,122,28,191,252,226,203,251,254,23,63,102,15,214,30,172,60,248,94,209,95,108,15,118,
46,25,165,196,118,32,116,150,120,126,218,31,248,188,68,112,187,110,126,190,3,17,132,31,149,198,211,35,62,178,234,95,118,65,204,195,249,240,44,7,103,171,225,251,19,96,30,173,138,243,102,166,114,122,93,
230,246,15,240,115,195,119,41,126,119,70,157,229,1,243,234,195,228,43,19,224,54,209,29,189,169,109,52,249,125,14,120,203,105,177,38,83,96,25,77,130,163,39,27,34,8,63,122,89,124,114,123,142,102,187,110,
250,219,109,255,219,221,251,104,148,122,117,9,220,61,193,152,133,42,198,107,227,53,136,245,85,159,17,220,250,151,131,199,176,220,133,95,17,198,60,136,85,30,239,30,105,63,207,113,238,242,218,254,130,143,
91,79,56,187,111,152,221,83,171,247,0,103,191,23,231,96,29,159,187,11,192,91,135,47,155,15,101,208,135,166,25,57,217,19,156,253,227,222,235,200,199,108,237,126,185,227,87,222,229,49,188,79,14,250,103,
143,47,188,93,240,6,225,203,50,26,124,142,246,4,239,239,115,181,14,179,150,61,230,79,60,214,179,220,119,171,216,207,77,123,205,19,139,102,251,95,191,45,240,179,109,241,121,175,168,151,188,117,235,99,125,
184,152,197,212,25,241,225,219,174,106,207,111,186,186,23,120,54,253,229,126,37,217,61,250,236,88,195,11,1,236,191,176,222,221,81,127,183,168,246,115,116,231,252,43,81,69,176,190,174,28,108,251,27,13,
196,113,235,23,13,252,144,42,54,203,220,89,252,14,166,191,110,197,152,135,147,231,75,19,224,96,142,92,119,253,198,165,41,240,56,130,203,52,248,252,218,152,141,118,106,7,111,25,197,225,222,223,131,248,
93,153,254,178,222,14,120,205,227,180,121,81,118,203,224,246,160,151,122,10,204,231,42,54,198,17,44,101,31,194,102,217,155,23,151,185,214,192,240,163,38,190,188,184,28,110,222,74,155,251,24,46,151,115,
16,194,193,242,247,172,133,143,91,63,200,238,64,192,103,248,170,9,112,57,238,101,31,193,207,219,71,33,108,191,99,52,87,199,75,99,53,240,61,115,56,63,129,193,116,25,220,237,241,109,66,152,253,94,224,107,
59,83,31,211,103,30,229,194,205,185,134,47,227,121,132,223,115,163,224,126,242,27,132,176,137,225,233,255,63,0,111,83,199,126,248,201,227,32,230,178,106,236,67,120,161,17,175,236,5,94,135,188,102,25,156,
165,126,147,199,54,5,110,225,203,231,206,141,200,122,117,123,20,194,101,106,204,235,139,90,127,20,29,126,68,212,174,53,233,238,18,184,15,225,54,245,229,250,177,91,6,191,188,4,222,77,129,209,197,49,159,
61,107,35,88,74,150,140,37,122,203,52,120,52,249,157,85,60,94,250,5,3,223,115,17,124,121,18,92,99,87,186,55,86,84,33,60,56,253,222,213,3,163,31,103,79,125,155,2,7,211,95,137,113,4,151,126,62,63,249,28,
10,151,48,94,152,252,38,75,98,224,125,166,195,221,36,88,45,111,251,169,111,189,182,139,223,116,10,60,121,74,143,233,147,237,98,87,154,37,241,51,124,131,8,150,242,60,224,57,219,232,197,250,140,158,15,28,
253,19,140,221,47,202,130,23,222,109,6,204,131,79,71,219,253,198,49,172,227,183,78,129,253,123,228,46,28,22,115,190,13,240,51,113,165,62,148,239,243,114,28,68,240,121,159,93,244,170,246,149,122,50,156,
8,243,31,188,95,1,243,120,10,156,198,112,9,221,40,126,213,1,209,217,30,24,253,245,109,128,207,35,158,151,165,112,93,168,62,130,37,250,233,47,150,123,86,101,204,38,146,91,42,179,157,250,212,15,222,127,
18,28,156,221,32,119,203,230,193,182,192,220,255,137,142,236,255,110,239,151,183,1,102,54,167,244,251,60,75,244,246,141,150,61,196,37,182,105,111,153,244,98,125,194,177,159,254,134,63,120,232,30,252,234,
69,241,193,20,56,12,97,86,127,86,179,186,156,203,142,146,252,3,219,0,215,40,109,59,44,150,8,54,151,251,211,6,174,33,140,106,250,235,126,224,221,91,224,134,91,4,129,183,202,221,249,4,56,10,223,126,249,
59,136,223,178,151,184,9,234,171,219,0,155,233,175,94,238,246,17,108,183,15,150,110,2,204,221,232,215,79,128,227,163,174,77,130,240,59,178,184,95,242,150,195,165,239,60,132,245,177,131,231,83,224,227,
218,83,205,131,8,150,118,251,95,217,162,56,156,0,143,162,127,48,238,153,0,225,77,167,192,11,127,103,124,28,190,250,62,57,8,97,21,191,11,166,75,224,245,96,230,136,125,4,203,118,185,148,253,4,184,91,10,
143,38,192,225,47,36,76,128,240,203,22,196,179,9,176,157,248,250,169,175,11,222,238,114,121,117,9,252,25,188,195,8,62,203,118,20,190,236,150,183,91,16,119,103,20,28,255,42,188,229,13,222,168,123,87,198,
153,236,238,62,248,51,26,187,9,112,22,194,243,105,240,113,101,233,155,177,189,107,35,183,99,152,215,67,99,214,185,45,218,159,179,110,88,30,236,241,61,108,157,183,188,193,47,106,226,241,159,203,220,197,
240,240,92,129,57,56,131,244,171,39,68,29,78,125,245,57,255,186,16,118,159,79,167,192,46,130,90,7,150,197,199,211,223,18,183,201,73,18,154,207,247,211,224,237,0,254,245,143,191,253,123,1,222,218,135,95,
1,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,8,32,128,0,2,8,32,
128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,32,128,0,2,8,32,128,0,2,8,32,128,
0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,2,8,32,128,0,199,254,15,203,196,164,67,184,37,224,57,0,0,0,0,73,69,78,68,174,66,96,
130,0,0};

const char* MainGui::screenshot_png = (const char*) resource_MainGui_screenshot_png;
const int MainGui::screenshot_pngSize = 3582;
