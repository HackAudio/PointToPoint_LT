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
//  CircuitElement.h
//
//  Collection of the available circuit elements
//  in the "Point To Point LT" library
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

