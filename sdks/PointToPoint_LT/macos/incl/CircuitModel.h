/**
 * Copyright (C) Hack Audio LLC - All Rights Reserved
 *
 * This source code is protected under international copyright law.  All rights
 * reserved and protected by the copyright holders.
 * This file is confidential and only available to authorized individuals with the
 * permission of the copyright holders.  If you encounter this file and do not have
 * permission, please contact the copyright holders and delete this file.
 */

//
//  CircuitModel.h
//
//  Created by Hack Audio on 1/20/22.
//

#ifndef CircuitModel_
#define CircuitModel_

/* The classes below are exported */
#pragma GCC visibility push(default)

#include <vector>
#include "CircuitElement.h"

namespace PointToPoint_LT {

class CircuitModel
{
    public:
    struct CircuitLayout
    {
        int numNodes = 0;
        CircuitElement::VoltageInput Vin {1,0};
        CircuitElement::VoltageOutput Vout {2,0};
        std::vector<CircuitElement::Resistor> Rs;
        std::vector<CircuitElement::Capacitor> Cs;
        std::vector<CircuitElement::OPAmp> OPAmps;
    };
    
    CircuitModel(CircuitLayout layout);
    
    ~CircuitModel();
    
    CircuitModel(const CircuitModel& other);
    CircuitModel& operator=( CircuitModel rhs );
    
    void process(const float * input, float * output, int numSamples, int channel);
    
    void processInPlace(float * buffer, int numSamples, int channel);
    
    float processSample(float x, int channel);
    
    void prepare(double sampleRate, int bufferSize);
    
private:
    class CircuitModelImpl;
    std::unique_ptr<CircuitModelImpl> pImpl;
};

}
#pragma GCC visibility pop
#endif
