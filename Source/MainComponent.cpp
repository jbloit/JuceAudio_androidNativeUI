/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (800, 600);

    // specify the number of input and output channels that we want to open
    setAudioChannels (0, 2);
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.

    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.

    String message;
    message << "Preparing to play audio..." << newLine;
    message << " samplesPerBlockExpected = " << samplesPerBlockExpected << newLine;
    message << " sampleRate = " << sampleRate;
    Logger::getCurrentLogger()->writeToLog (message);
}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{

    for (auto channel = 0; channel < bufferToFill.buffer->getNumChannels(); ++channel)
    {
        // Get a pointer to the start sample in the buffer for this audio output channel
        auto* buffer = bufferToFill.buffer->getWritePointer (channel, bufferToFill.startSample);
        // Fill the required number of samples with noise betweem -0.125 and +0.125
        for (auto sample = 0; sample < bufferToFill.numSamples; ++sample)
            buffer[sample] = random.nextFloat() * 0.25f - 0.125f;
    }
}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    Logger::getCurrentLogger()->writeToLog ("Releasing audio resources");

}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    // You can add your drawing code here!
}

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
