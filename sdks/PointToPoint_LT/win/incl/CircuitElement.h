//
//  CircuitElement.h
//
//  Collection of the available circuit elements
//  in the PointToPoint library
//  Created by Eric Tarr on 11/4/21.
//
//

#pragma once
#include <cmath>

namespace PointToPoint_LT {

// Class definition
class CircuitElement
{

public:
	
    //---------------------------------------------------
    
    class VoltageInput
    {
    public:
        VoltageInput (int node1,int node2):
                    node1(node1),node2(node2) {};
        
        int getNode1() {return node1;}
        int getNode2() {return node2;}
    private:
        int node1;
        int node2;
    };
    
    //---------------------------------------------------
    
    class VoltageOutput
    {
    public:
        VoltageOutput (int node1,int node2):
                    node1(node1),node2(node2) {};
        
        int getNode1() {return node1;}
        int getNode2() {return node2;}
    private:
        int node1;
        int node2;
    };
    
    //---------------------------------------------------
    
    
    class Resistor
    {
    public:
        Resistor (double value,int node1,int node2):
                    value(value),node1(node1),node2(node2) {};
        
        double getValue() {return value;}
        int getNode1() {return node1;}
        int getNode2() {return node2;}
    private:
        double value;
        int node1;
        int node2;
    };
    
    //---------------------------------------------------
    
    class Capacitor
    {
    public:
        Capacitor (double value,int node1,int node2):
                    value(value),node1(node1),node2(node2) {};
        
        double getValue() {return value;}
        int getNode1() {return node1;}
        int getNode2() {return node2;}
    private:
        double value;
        int node1;
        int node2;
    };
    
    //---------------------------------------------------
    
    class OPAmp
    {
    public:
        OPAmp (int nonInvertingNode,
               int invertingNode,
               int outputNode):
                    nonInvertingNode(nonInvertingNode),
                    invertingNode(invertingNode),
                    outputNode(outputNode){};
        
        int getNonInvertingNode() {return nonInvertingNode;}
        int getInvertingNode() {return invertingNode;}
        int getOutputNode() {return outputNode;}
        
    private:
        int nonInvertingNode;
        int invertingNode;
        int outputNode;
    };
    
    //---------------------------------------------------
    
};

}

