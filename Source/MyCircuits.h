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




//----------------------------- Active 2nd-order LPF
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


//----------------------------- 2nd Order RC BPF Circuit
// https://www.electronics-tutorials.ws/filter/filter_4.html
class Passive2ndOrderBPF : public Circuit
{
public:
    Passive2ndOrderBPF(){
        layout.numNodes = 3;
        
        layout.Vin = CircuitElement::VoltageInput {1,0};
        layout.Vout = CircuitElement::VoltageOutput {3,0};
        
        CircuitElement::Resistor R1 {5e3,2,0};
        CircuitElement::Resistor R2 {20e3,2,3};
        layout.Rs = std::vector<CircuitElement::Resistor> {R1,R2};
        
        CircuitElement::Capacitor C1 {15e-9,1,2};
        CircuitElement::Capacitor C2 {560e-12,3,0};
        layout.Cs = std::vector<CircuitElement::Capacitor> {C1,C2};
        
        circuit = CircuitModel(layout);
    }
};

//------------------------------ Sallen Key LPF Circuit
//http://sim.okawa-denshi.jp/en/OPseikiLowkeisan.htm
class SallenKeyLowPass : public Circuit
{
    
public:
    
    SallenKeyLowPass(){
        layout.numNodes = 4;
        
        layout.Vin = CircuitElement::VoltageInput {1,0};
        layout.Vout = CircuitElement::VoltageOutput {4,0};
        
        CircuitElement::Resistor R1 {16000.0,1,2};
        CircuitElement::Resistor R2 {16000.0,2,3};
        layout.Rs = std::vector<CircuitElement::Resistor> {R1,R2};
        
        CircuitElement::Capacitor C1 {0.01e-6,2,4};
        CircuitElement::Capacitor C2 {0.01e-6,3,0};
        layout.Cs = std::vector<CircuitElement::Capacitor> {C1,C2};
        

        CircuitElement::OPAmp OPA {3,4,4};
        layout.OPAmps = std::vector<CircuitElement::OPAmp> {OPA};
        
        circuit = CircuitModel(layout);
    }
};

//------------------------------- Baxandall Filter Circuit
// https://www.hgamps.com/wp-content/uploads/2015/11/baaxandall.png
class BaxandallToneStack : public Circuit
{
  
public:
    BaxandallToneStack(){
        layout.numNodes = 7;
        
        layout.Vin = CircuitElement::VoltageInput {1,0};
        layout.Vout = CircuitElement::VoltageOutput {6,0};
        
        CircuitElement::Resistor R1 {100e3,1,3};
        CircuitElement::Resistor R2 {10e3,5,0};
        CircuitElement::Resistor R3 {180e3,4,6};
        
        // Bass pot
        double b = 0.5; // (0:1)
        CircuitElement::Resistor VR1 {(1-b)*500e3,3,4};
        CircuitElement::Resistor VR2 {b*500e3,4,5};
        
        // Treble pot
        double t = 0.5; // (0:1)
        CircuitElement::Resistor VR3 {(1-t)*500e3,2,6};
        CircuitElement::Resistor VR4 {t*500e3,6,7};
        
        layout.Rs = std::vector<CircuitElement::Resistor> {R1,R2,R3,VR1,VR2,VR3,VR4};
        
        CircuitElement::Capacitor C1 {330e-12,1,2};
        CircuitElement::Capacitor C2 {560e-12,3,4};
        CircuitElement::Capacitor C3 {4.7e-9,4,5};
        CircuitElement::Capacitor C4 {3.3e-9,7,0};
        layout.Cs = std::vector<CircuitElement::Capacitor> {C1,C2,C3,C4};
        
        circuit = CircuitModel(layout);
    }
};


//------------------------------ Big Muff Tone Circuit
//https://www.electrosmash.com/big-muff-pi-analysis
class BigMuffToneStack : public Circuit
{
    
public:
    
    BigMuffToneStack(){
        layout.numNodes = 4;
        
        layout.Vin = CircuitElement::VoltageInput {1,0};
        layout.Vout = CircuitElement::VoltageOutput {3,0};
        
        CircuitElement::Resistor R1 {39e3,1,4};
        CircuitElement::Resistor R2 {22e3,2,0};
        
        // Tone pot
        double vr = .5; // (0:1)
        CircuitElement::Resistor VR1 {(1-vr)*100e3,2,3};
        CircuitElement::Resistor VR2 {vr*100e3,3,4};
        
        layout.Rs = std::vector<CircuitElement::Resistor> {R1,R2,VR1,VR2};
        
        CircuitElement::Capacitor C1 {4e-9,1,2};
        CircuitElement::Capacitor C2 {10.0e-9,4,0};
        layout.Cs = std::vector<CircuitElement::Capacitor> {C1,C2};
    
        circuit = CircuitModel(layout);
    }
};

//------------------------------- Fender Bassman Tone Stack
//https://www.ampbooks.com/mobile/classic-circuits/bassman-tonestack/
class FenderBassmanTonestack : public Circuit
{
    
public:
    
    FenderBassmanTonestack(){
        layout.numNodes = 7;
        
        layout.Vin = CircuitElement::VoltageInput {1,0};
        layout.Vout = CircuitElement::VoltageOutput {4,0};
        
        CircuitElement::Resistor R1 {56000.0,1,2};
        
        // Pot1
        double a = 0.5; // (0:1)
        CircuitElement::Resistor VR1 {(1-a)*25000.0,7,0};
        CircuitElement::Resistor VR2 {a*25000.0,6,7};
        
        // Pot2
        double b = 0.5; // (0:1)
        CircuitElement::Resistor VR3 {b*1000000.0,5,6};
        
        // Pot3
        double c = 0.5; // (0:1)
        CircuitElement::Resistor VR4 {c*250000.0,4,5};
        CircuitElement::Resistor VR5 {(1-c)*250000.0,3,4};
        
        layout.Rs = std::vector<CircuitElement::Resistor> {R1,VR1,VR2,VR3,VR4,VR5};
        
        CircuitElement::Capacitor C1 {0.25e-9,1,3};
        CircuitElement::Capacitor C2 {20.0e-9,2,5};
        CircuitElement::Capacitor C3 {20.0e-9,2,7};
        layout.Cs = std::vector<CircuitElement::Capacitor> {C1,C2,C3};
    
        circuit = CircuitModel(layout);
    }
};

//------------------------------ Tube Screamer Tone Stack
// https://www.electrosmash.com/images/tech/tube-screamer/tube-screamer-tone-volume.png
class TubeScreamerToneStack : public Circuit
{
    
public:
    TubeScreamerToneStack(){
        layout.numNodes = 9;
        
        layout.Vin = CircuitElement::VoltageInput {1,0};
        layout.Vout = CircuitElement::VoltageOutput {9,0};
        
        CircuitElement::Resistor R1 {1000,1,2};
        CircuitElement::Resistor R2 {10000,2,0};
        CircuitElement::Resistor R3 {220,3,0};
        CircuitElement::Resistor R4 {1000,5,6};
        CircuitElement::Resistor R5 {1000,7,8};
        
        // Tone pot
        double a = 0.5; // (0:1)
        CircuitElement::Resistor VR1 {a*20e3,2,4};
        CircuitElement::Resistor VR2 {(1-a)*20e3,4,5};
        
        // Level pot
        double b = 0.99; // (0:1)
        CircuitElement::Resistor VR3 {(1-b)*100e3,8,9};
        CircuitElement::Resistor VR4 {b*100e3,9,0};
        
        layout.Rs = std::vector<CircuitElement::Resistor> {R1,R2,R3,R4,R5,VR1,VR2,VR3,VR4};
        
        CircuitElement::Capacitor C1 {.22e-6,2,0};
        CircuitElement::Capacitor C2 {.22e-6,3,4};
        CircuitElement::Capacitor C3 {1e-6,6,7};
        layout.Cs = std::vector<CircuitElement::Capacitor> {C1,C2,C3};
        
        CircuitElement::OPAmp OPA {2,5,6};
        layout.OPAmps = std::vector<CircuitElement::OPAmp> {OPA};
        
        circuit = CircuitModel(layout);
    }
};

//------------------------------ State Variable Filters (LPF, BPF,  HPF)
// https://sound-au.com/articles/state-variable.htm
class StateVariable2ndOrder : public Circuit
{
    // https://www.circuitstoday.com/state-variable-filters
public:
    
    StateVariable2ndOrder(){
        layout.numNodes = 9;
        
        layout.Vin = CircuitElement::VoltageInput {1,0};
        layout.Vout = CircuitElement::VoltageOutput {9,0}; // LPF
        //layout.Vout = CircuitElement::VoltageOutput {7,0}; // BPF
        //layout.Vout = CircuitElement::VoltageOutput {5,0}; // HPF
        
        CircuitElement::Resistor R1 {10e3,1,2};
        CircuitElement::Resistor R2 {1e3,0,3};
        CircuitElement::Resistor R3 {10e3,4,7};
        CircuitElement::Resistor R4 {10e3,2,5};
        CircuitElement::Resistor R5 {10e3,2,9};
        
        // Frequency pot
        double a = 0.5; // (0:1)
        CircuitElement::Resistor VR1A {(1-a)*32e3,5,6};
        CircuitElement::Resistor VR1B {(1-a)*32e3,7,8};
        
        // Resonance pot
        double b = 0.9; // (0:1)
        CircuitElement::Resistor VR2 {(1-b)*19e3,3,4};
        layout.Rs = std::vector<CircuitElement::Resistor> {R1,R2,R3,R4,R5,VR1A,VR1B,VR2};
                
        CircuitElement::Capacitor C1 {10e-9,6,7};
        CircuitElement::Capacitor C2 {10e-9,8,9};
        layout.Cs = std::vector<CircuitElement::Capacitor> {C1,C2};
        
        CircuitElement::OPAmp OPA1 {4,2,5};
        CircuitElement::OPAmp OPA2 {0,6,7};
        CircuitElement::OPAmp OPA3 {0,8,9};
        layout.OPAmps = std::vector<CircuitElement::OPAmp> {OPA1,OPA2,OPA3};
        
        circuit = CircuitModel(layout);
    }
};


// End of namespace
}
