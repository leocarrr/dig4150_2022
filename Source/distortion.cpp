/*
  ==============================================================================

    distortion.cpp
    Created: 30 Mar 2022 10:32:06am
    Author:  Leo Carr

  ==============================================================================
*/

#include "distortion.h"




void scaling(AudioBuffer<float> *buffer, float scalingFactor) {
    buffer->applyGain(scalingFactor);
}

void processBuffer(AudioBuffer<float> *buffer)
{
    int numberOfChannels = buffer->getNumChannels();
    int numberOfSamples = buffer->getNumSamples();
    
    for (int c=0; c<numberOfChannels; c++)
    {
        const float* input = buffer->getReadPointer(c);
        float* output = buffer->getWritePointer(c);
        for (int n=0; n<numberOfSamples; n++)
        {
            // Example of the functions
            if (input[n] >= 0.5) {
                output[n] = 0.5;
            } else if (input[n] <= -0.5) {
                output[n] = -0.5;
            } else {
                output[n] = input[n];
            }
        }
    }
}
