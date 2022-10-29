/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class PointToPoint_LTAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    PointToPoint_LTAudioProcessorEditor (PointToPoint_LTAudioProcessor&);
    ~PointToPoint_LTAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    PointToPoint_LTAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PointToPoint_LTAudioProcessorEditor)
};
