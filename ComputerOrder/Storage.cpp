//
//  Storage.cpp
//  CIS200-Assignment1
//
//  Created by Gabriel Push on 2/8/24.
//

#include <stdio.h>
#include "Storage.h"
#include <sstream>
#include <fstream>


// Storage constructor initializing attributes and base class Component
Storage::Storage(const string& name, const string& serialNum, double price, double cost, const string& deviceType, int capacityGB, double xferSpeed, int lifetime) : Component(name, serialNum, price, cost), deviceType(deviceType), capacityGB(capacityGB), xferSpeed(xferSpeed), lifetime(lifetime) {}

// Storage destructor
Storage::~Storage(){}

// override infoString for Storage attributes using stringstream
string Storage::infoString() const {
    stringstream ss;
    ss << name << setw(9) << Component::getSerialNum() << setw(7) << capacityGB << "GB " << deviceType << ", Xfer:" << fixed << setprecision(2) << xferSpeed << "MB/s, " << "MTBF:" << lifetime << "hrs " << setw(7) << right << fixed << setprecision(2) << price;
    return ss.str();
    }

// acesssors
// adds S to serialNum to indicate Storage serialNum
string Storage::getSerialNum() const {
    return "S" + serialNum;
}

string Storage::getDevice() { return deviceType; }

int Storage::getCapacity() { return capacityGB; }

double Storage::getXFerSpeed() { return xferSpeed; }

int Storage::getLifetime() { return lifetime; }

