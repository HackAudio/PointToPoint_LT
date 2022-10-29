//
//  CircuitModel.h
//  CircuitModel
//
//  Created by Hack Audio on 1/20/22.
//

#ifndef CircuitModel_
#define CircuitModel_

/* The classes below are exported */
#pragma GCC visibility push(default)

#include <vector>
#include <memory>
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
