//
//  MyCircuits.h
//
//  Collection of famous, foundational linear
//  circuits (e.g. Butterworth, Sallen-Key, etc)
//
//
#include "Circuit.h"
#include "CircuitModel.h"
#include "CircuitElement.h"

#pragma once
namespace PointToPoint_LT {

//------ Passive 1st-order RC LPF

class Passive1stOrderRCLPF : public Circuit
{
    
public:
    
    Passive1stOrderRCLPF(){
        layout.numNodes = 2;
        
        layout.Vin = CircuitElement::VoltageInput {1,0};
        layout.Vout = CircuitElement::VoltageOutput {2,0};
        
        CircuitElement::Resistor R {4700.0,1,2};
        layout.Rs = std::vector<CircuitElement::Resistor> {R};
        
        CircuitElement::Capacitor C {47e-9,2,0};
        layout.Cs = std::vector<CircuitElement::Capacitor> {C};
        
        circuit = CircuitModel(layout);
    }
};




//----------------------------- Passive 1st-order RC HPF
class Passive1stOrderRCHPF : public Circuit
{
    
public:
    
    Passive1stOrderRCHPF(){
        layout.numNodes = 2;
        
        layout.Vin = CircuitElement::VoltageInput {1,0};
        layout.Vout = CircuitElement::VoltageOutput {2,0};
        
        CircuitElement::Resistor R {4700.0,2,0};
        layout.Rs = std::vector<CircuitElement::Resistor> {R};
        
        CircuitElement::Capacitor C {47e-9,1,2};
        layout.Cs = std::vector<CircuitElement::Capacitor> {C};
        
        circuit = CircuitModel(layout);
    }
};




//----------------------------- Active 2nd-order LPF (no VariableResistor)
// https://www.electronics-tutorials.ws/filter/second-order-filters.html
class Active2ndOrderLPF : public Circuit
{
    
public:
    
    Active2ndOrderLPF(){
        layout.numNodes = 4;
        
        layout.Vin = CircuitElement::VoltageInput {1,0};
        layout.Vout = CircuitElement::VoltageOutput {4,0};
        
        CircuitElement::Resistor R1 {10e3,1,2};
        CircuitElement::Resistor R2 {10e3,2,3};
        layout.Rs = std::vector<CircuitElement::Resistor> {R1,R2};
        
        CircuitElement::Capacitor C1 {10e-9,2,4};
        CircuitElement::Capacitor C2 {10e-9,3,0};
        layout.Cs = std::vector<CircuitElement::Capacitor> {C1,C2};
        
        CircuitElement::OPAmp OPA {3,4,4};
        layout.OPAmps = std::vector<CircuitElement::OPAmp> {OPA};
        
        circuit = CircuitModel(layout);
    }
};



// End of namespace
}



