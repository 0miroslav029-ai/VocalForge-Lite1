#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

class VocalForgeEditor : public juce::AudioProcessorEditor
{
public:
    explicit VocalForgeEditor (VocalForgeProcessor&);
        ~VocalForgeEditor() override;

            void paint (juce::Graphics&) override;
                void resized() override;

                private:
                    VocalForgeProcessor& audioProcessor;

                        using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
                            using ButtonAttachment = juce::AudioProcessorValueTreeState::ButtonAttachment;

                                std::unique_ptr<SliderAttachment> attInGain, attOutGain, attMix;
                                    std::unique_ptr<ButtonAttachment> attBypass;

                                        juce::Slider slInGain, slOutGain, slMix;
                                            juce::ToggleButton tbBypass;

                                                juce::Label lblInGain, lblOutGain, lblMix;

                                                    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VocalForgeEditor)
                                                    };