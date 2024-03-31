//
//  CPU.cpp
//  CIS200-Assignment1
//
//  Created by Gabriel Push on 2/8/24.
//

#include "CPU.h"
#include <sstream>
#include <fstream>
using namespace std;


// CPU constructor initializing attirbutes and base class Component attributes
CPU::CPU(const string& name, const string& serialNum, double price, double cost, double clockSpeed, int cores) : Component(name, serialNum, price, cost), clockSpeedGHz(clockSpeed), cores(cores) {}

// CPU destructor
CPU::~CPU() {}

// override infoString for CPU attributes using stringstream
string CPU::infoString() const {
    stringstream ss;
    ss << name << setw(13) << Component::getSerialNum() << setw(8) << fixed << setprecision(2) << clockSpeedGHz << " GHz, " << cores << " Cores" << setw(29) << right << fixed << setprecision(2) << price;
    return ss.str();
}

// accessors
// adds C to serialNum to indicate CPU
string CPU::getSerialNum() const {
    return "C" + serialNum;
}

double CPU::getClockSpeed() { return clockSpeedGHz; }

int CPU::getCores() { return cores; }
