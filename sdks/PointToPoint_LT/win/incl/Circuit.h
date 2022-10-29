//
//  Circuit.h
//
//  Base classes for circuits in the PointToPoint library
//  Created by Eric Tarr on 2/13/22.
//
//

#include "CircuitModel.h"

#pragma once

namespace PointToPoint_LT {

//-------------------Don't change this base classes ---------

class Circuit
{
public:
    
    void process(const float * input, float * output, int numSamples, int channel)
    {
        circuit.process(input,output,numSamples,channel);
    }
    
    void processInPlace(float* buffer, int numSamples, int channel)
    {
        circuit.processInPlace(buffer,numSamples,channel);
    }
    
    float processSample(float x, int channel)
    {
        return circuit.processSample(x,channel);
    }
    
    void prepare(double sampleRate, int bufferSize) {
        circuit.prepare(sampleRate,bufferSize);
    }
    
protected:
    
    CircuitModel::CircuitLayout layout;
    
    CircuitModel circuit {layout};
};

// End of namespace
}



