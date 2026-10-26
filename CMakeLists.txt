cmake_minimum_required(VERSION 3.22)
project(VocalForge VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        JUCE
            GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
                GIT_TAG        8.0.4
)
FetchContent_MakeAvailable(JUCE)

juce_add_plugin(VocalForge
    COMPANY_NAME            "YourAudio"
        PLUGIN_MANUFACTURER_CODE Yrau
            PLUGIN_CODE             Vfrg
                FORMATS                 VST3
                    IS_SYNTH                FALSE
                        NEEDS_MIDI_INPUT        FALSE
                            NEEDS_MIDI_OUTPUT       FALSE
                                COPY_PLUGIN_AFTER_BUILD TRUE
                                    PRODUCT_NAME            "VocalForge Lite")

                                    juce_generate_juce_header(VocalForge)

                                    target_sources(VocalForge PRIVATE
                                        Source/PluginProcessor.cpp
                                            Source/PluginEditor.cpp)

                                            target_compile_definitions(VocalForge PUBLIC
                                                JUCE_WEB_BROWSER=0
                                                    JUCE_USE_CURL=0
                                                        JUCE_VST3_CAN_REPLACE_VST2=0
                                                            JUCE_DISPLAY_SPLASH_SCREEN=0)

                                                            # Флаги для старых CPU (Phenom X4)
                                                            if(MSVC)
                                                                target_compile_options(VocalForge PRIVATE /arch:SSE2)
                                                                else()
                                                                    target_compile_options(VocalForge PRIVATE -msse2 -mfpmath=sse)
                                                                    endif()

                                                                    target_link_libraries(VocalForge
                                                                        PRIVATE
                                                                                juce::juce_audio_utils
                                                                                        juce::juce_dsp
                                                                                            PUBLIC
                                                                                                    juce::juce_recommended_config_flags
                                                                                                            juce::juce_recommended_lto_flags
                                                                                                                    juce::juce_recommended_warning_flags)
)