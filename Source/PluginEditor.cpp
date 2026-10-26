#include "PluginEditor.h"

VocalForgeEditor::VocalForgeEditor (VocalForgeProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
    {
        setSize (700, 400);

            tbBypass.setButtonText ("BYPASS");
                attBypass = std::make_unique<ButtonAttachment> (p.apvts, PID::id[PID::Bypass], tbBypass);
                    addAndMakeVisible (tbBypass);

                        auto setupSlider = [this] (juce::Slider& s, juce::Label& l, const juce::String& name)
                            {
                                    s.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
                                            s.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 60, 20);
                                                    l.setText (name, juce::dontSendNotification);
                                                            l.setJustificationType (juce::Justification::centred);
                                                                    addAndMakeVisible (s);
                                                                            addAndMakeVisible (l);
                                                                                };

                                                                                    setupSlider (slInGain, lblInGain, "In Gain");
                                                                                        attInGain = std::make_unique<SliderAttachment> (p.apvts, PID::id[PID::InGain], slInGain);

                                                                                            setupSlider (slOutGain, lblOutGain, "Out Gain");
                                                                                                attOutGain = std::make_unique<SliderAttachment> (p.apvts, PID::id[PID::OutGain], slOutGain);

                                                                                                    setupSlider (slMix, lblMix, "Dry/Wet");
                                                                                                        attMix = std::make_unique<SliderAttachment> (p.apvts, PID::id[PID::Mix], slMix);
                                                                                                        }

                                                                                                        VocalForgeEditor::~VocalForgeEditor()
                                                                                                        {
                                                                                                        }

                                                                                                        void VocalForgeEditor::paint (juce::Graphics& g)
                                                                                                        {
                                                                                                            g.fillAll (juce::Colour (0xFF222222));

                                                                                                                g.setColour (juce::Colours::white);
                                                                                                                    g.setFont (juce::FontOptions (16.0f).withTypefaceStyle ("Bold"));
                                                                                                                        g.drawFittedText ("VocalForge Lite", 10, 10, getWidth() - 20, 30, juce::Justification::centred, 1);
                                                                                                                        }

                                                                                                                        void VocalForgeEditor::resized()
                                                                                                                        {
                                                                                                                            tbBypass.setBounds (getWidth() - 100, 10, 90, 30);

                                                                                                                                int y = 60;
                                                                                                                                    int h = 100;
                                                                                                                                        
                                                                                                                                            auto placeCol = [this, y, h] (int x, juce::Slider& s, juce::Label& l)
                                                                                                                                                {
                                                                                                                                                        s.setBounds (x + 15, y + 25, 80, 80);
                                                                                                                                                                l.setBounds (x + 15, y + 105, 80, 20);
                                                                                                                                                                    };

                                                                                                                                                                        placeCol (15, slInGain, lblInGain);
                                                                                                                                                                            placeCol (145, slOutGain, lblOutGain);
                                                                                                                                                                                placeCol (275, slMix, lblMix);
                                                                                                                                                                                }