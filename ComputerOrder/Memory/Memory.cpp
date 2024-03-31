//
//  Memory.cpp
//  CIS200-Assignment1
//
//  Created by Gabriel Push on 2/8/24.
//

#include <stdio.h>
#include "Memory.h"
#include <sstream>
#include <fstream>


// Memory constructor initializing attirbutes and base class Component attibutes
Memory::Memory(const string& name, const string serialNum, double price, double cost, int sizeGB, int speedMHz) : Component(name, serialNum, price, cost), sizeGB(sizeGB), speedMHz(speedMHz) {}

// Memory destructor
Memory::~Memory(){}

// override infoString for Memory attributes using stringstream
string Memory::infoString() const {
    stringstream ss;
    ss << name << setw(10) << Component::getSerialNum() << setw(6) << sizeGB << "GB, " << speedMHz << "MHz" << setw(33) << right << fixed << setprecision(2) << price;
    return ss.str();
}

// accessors
// adds M to serialNum to indicate Memory
string Memory::getSerialNum() const {
    return "M" + serialNum;
}

int Memory::getSize() { return sizeGB; }

int Memory::getSpeed() { return speedMHz; }
