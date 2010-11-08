/*
 * JuceProcessor.cpp
 *
 *  Created on: Nov 2, 2010
 *      Author: suva
 */

/*
  ==============================================================================

    This file was auto-generated by the Jucer!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "JuceProcessor.h"
#include "jucegui/EditorGUI.h"

//==============================================================================
ChainsawAudioProcessor::ChainsawAudioProcessor()
	: b(32000)
{
	p.vp.stereoSpread = 0;
	p.vp.detune = 0;
	p.vp.octaveSpread = 0;
	p.vp.numosc = 1;
	for(int i = 0; i < NUM_OSC_GROUPS; i++){
			p.vp.g[i].type = 0;
			p.vp.g[i].vol = 0.5;
			p.vp.g[i].octave = 0;

	}
	p.vp.volAttack = 0;
	p.vp.volDecay = 0;
	p.vp.volSustain = 1;
	p.vp.volRelease = 0;
	p.vp.filterResonance = 0;
	p.vp.filterCutoff = 1;

}

ChainsawAudioProcessor::~ChainsawAudioProcessor()
{
}

//==============================================================================
int ChainsawAudioProcessor::getNumParameters()
{

    return NUM_CHAINSAW_PARAMETERS;

}

float ChainsawAudioProcessor::getParameter (int index)
{
    // This method will be called by the host, probably on the audio thread, so
    // it's absolutely time-critical. Don't use critical sections or anything
    // UI-related, or anything at all that may block in any way
	switch (index){
	case 0: return p.vp.stereoSpread;
	case 1: return p.vp.detune;
	case 2: return p.vp.octaveSpread;
	case 3: return p.vp.numosc / 7.0f;
	case 4: return p.vp.volAttack;
	case 5: return p.vp.volDecay;
	case 6: return p.vp.volSustain;
	case 7: return p.vp.volRelease;
	case 8: return p.vp.filterResonance;
	case 9: return p.vp.filterCutoff;
	default:
		int parNum = index - 10;
		int parGroup = parNum / 3;
		int parIdx = parNum % 3;
		switch(parIdx){
		case 0: return p.vp.g[parGroup].type / 3;
		case 1: return p.vp.g[parGroup].vol;
		case 2: return (p.vp.g[parGroup].octave + 5) / 10.0f;
		}
	}
	return 0;
}

void ChainsawAudioProcessor::setParameter (int index, float newValue)
{
    // This method will be called by the host, probably on the audio thread, so
    // it's absolutely time-critical. Don't use critical sections or anything
    // UI-related, or anything at all that may block in any way!
	printf("%i, %f\n", index, newValue);
	switch (index){
	case 0: p.vp.stereoSpread = newValue; return;
	case 1: p.vp.detune = newValue; return;
	case 2: p.vp.octaveSpread = newValue; return;
	case 3: p.vp.numosc = newValue * 7; return;
	case 4: p.vp.volAttack = newValue; return;
	case 5: p.vp.volDecay = newValue; return;
	case 6: p.vp.volSustain = newValue; return;
	case 7: p.vp.volRelease = newValue; return;
	case 8: p.vp.filterResonance = newValue; return;
	case 9: p.vp.filterCutoff = newValue; return;
	default:
		int parNum = index - 10;
		int parGroup = parNum / 3;
		int parIdx = parNum % 3;
		switch(parIdx){
		case 0: p.vp.g[parGroup].type = newValue * 3; return;
		case 1: p.vp.g[parGroup].vol = newValue; return;
		case 2: p.vp.g[parGroup].octave = newValue * 10 - 5; return;
		}
	}
}

const String ChainsawAudioProcessor::getParameterName (int index)
{
	String ret;

	switch (index){
	case 0: return "Stereo spread";
	case 1: return "Detune";
	case 2: return "Octave Spread";
	case 3: return "Number of oscillators";
	case 4: return "Volume Attack";
	case 5: return "Volume Decay";
	case 6: return "Volume Sustain";
	case 7: return "Volume Release";;
	case 8: return "Filter Resonance";
	case 9: return "Filter Cutoff";
	default:
		int parNum = index - 10;
		int parGroup = parNum / 3;
		int parIdx = parNum % 3;
		switch(parIdx){
		case 0: ret << "OSC " << parGroup << " type"; return ret;
		case 1: ret << "OSC " << parGroup << " volume"; return ret;
		case 2: ret << "OSC " << parGroup << " octave"; return ret;
		}
	}
}

const String ChainsawAudioProcessor::getParameterText (int index)
{
    return String (getParameter (index), 2);
}

//==============================================================================
void ChainsawAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    p.sFreq = sampleRate;
    keyboardState.reset();
}

void ChainsawAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
    keyboardState.reset();
}

void ChainsawAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
	MidiBuffer::Iterator mbi(midiMessages);
	MidiMessage message (0, 0.0);
	int time;

    b.size = buffer.getNumSamples();
    vm.process(&b, &p);

    while(mbi.getNextEvent(message, time)) {
    	if(message.isNoteOnOrOff()){
    		Note note;
			if(message.isNoteOn()){
				note.type = Note::NOTE_ON;
			} else {
				note.type = Note::NOTE_OFF;
			}
			note.note = message.getNoteNumber();
			note.velocity = message.getVelocity();
			vm.note(note);
    	}
    }

    for(int i = 0; i < b.size; i++) {
    	*buffer.getSampleData (0, i) += b.dataL[i];
    	*buffer.getSampleData (1, i) += b.dataR[i];
    }
}

//==============================================================================
AudioProcessorEditor* ChainsawAudioProcessor::createEditor()
{
    return new EditorGUI(this);
}

//==============================================================================
void ChainsawAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // Here's an example of how you can use XML to make it easy and more robust:

    // Create an outer XML element..
    XmlElement xml ("CHAINSAWSETTINGS");

    // add some attributes to it..
    xml.setAttribute (T("uiWidth"), lastUIWidth);
    xml.setAttribute (T("uiHeight"), lastUIHeight);


	xml.setAttribute(T("stereoSpread"), p.vp.stereoSpread);
	xml.setAttribute(T("detune"), p.vp.detune);
	xml.setAttribute(T("numOsc"), p.vp.numosc);
	xml.setAttribute(T("volAttack"), p.vp.volAttack);
	xml.setAttribute(T("volDecay"), p.vp.volDecay);
	xml.setAttribute(T("volSustain"), p.vp.volSustain);
	xml.setAttribute(T("volRelease"), p.vp.volRelease);
	xml.setAttribute(T("filterResonance"), p.vp.filterResonance);
	xml.setAttribute(T("filterCutoff"), p.vp.filterCutoff);

	for (int i = 0; i < NUM_OSC_GROUPS; i++){
		String paramName;
		paramName << "oscType" << i;
		xml.setAttribute(paramName, p.vp.filterCutoff);

		paramName << "oscVolume" << i;
		xml.setAttribute(paramName, p.vp.g[i].vol);

		paramName << "oscOctave" << i;
		xml.setAttribute(paramName, p.vp.g[i].octave);
	}

    // then use this helper function to stuff it into the binary blob and return it..
    copyXmlToBinary (xml, destData);
}

void ChainsawAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.

    // This getXmlFromBinary() helper function retrieves our XML from the binary blob..
    ScopedPointer<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));

    if (xmlState != 0)
    {
        // make sure that it's actually our type of XML object..
        if (xmlState->hasTagName (T("CHAINSAWSETTINGS")))
        {

            // ok, now pull out our parameters..
        	p.vp.stereoSpread  = xmlState->getDoubleAttribute(T("stereoSpread"), p.vp.stereoSpread);
        	p.vp.detune = xmlState->getDoubleAttribute (T("detune"), p.vp.detune);
        	p.vp.numosc = xmlState->getIntAttribute (T("numOsc"), p.vp.numosc);
        	p.vp.volAttack = xmlState->getDoubleAttribute (T("volAttack"), p.vp.volAttack);
        	p.vp.volDecay = xmlState->getDoubleAttribute (T("volDecay"), p.vp.volDecay);
        	p.vp.volSustain = xmlState->getDoubleAttribute (T("volSustain"), p.vp.volSustain);
        	p.vp.volRelease = xmlState->getDoubleAttribute (T("volRelease"), p.vp.volRelease);
        	p.vp.filterResonance = xmlState->getDoubleAttribute (T("filterResonance"), p.vp.filterResonance);
        	p.vp.filterCutoff = xmlState->getDoubleAttribute (T("filterCutoff"), p.vp.filterCutoff);

			for (int i = 0; i < NUM_OSC_GROUPS; i++){
				String paramName;
				paramName << "oscType" << i;
				p.vp.g[i].type = xmlState->getIntAttribute (paramName, p.vp.filterCutoff);

				paramName << "oscVolume" << i;
				p.vp.g[i].vol = xmlState->getDoubleAttribute (paramName, p.vp.g[i].vol);

				paramName << "oscOctave" << i;
				p.vp.g[i].octave = xmlState->getIntAttribute (paramName, p.vp.g[i].octave);

			}
        }
    }
}

const String ChainsawAudioProcessor::getInputChannelName (const int channelIndex) const
{
    return String (channelIndex + 1);
}

const String ChainsawAudioProcessor::getOutputChannelName (const int channelIndex) const
{
    return String (channelIndex + 1);
}

bool ChainsawAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool ChainsawAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool ChainsawAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool ChainsawAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter(const String& commandLine)
{
    return new ChainsawAudioProcessor();
}
