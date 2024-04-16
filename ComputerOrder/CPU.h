//
//  CPU.h
//
//  Created by Gabriel Push on 2/8/24.
//

#pragma once
#include "Component.h"


// CPU inherits public from Component
class CPU : public Component {
private:
    string serialNum; // CPU serialNum
    double clockSpeedGHz;
    int cores;
public:
    CPU(const string& name, const string& serialNum, double price, double cost, double clockSpeedGHz, int cores); // CPU constructor
    ~CPU(); // CPU destructor
    string infoString() const override; // override infoString
    // accessors
    string getSerialNum() const;
    double getClockSpeed();
    int getCores();
};


