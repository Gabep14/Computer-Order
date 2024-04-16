//
//  Storage.h
//
//  Created by Gabriel Push on 2/8/24.
//

#pragma once
#include "Component.h"

// Storage class inherits from public Component
class Storage : public Component {
private:
    string serialNum; // Storage serialNum
    string deviceType;
    int capacityGB;
    double xferSpeed; // in MB/s
    int lifetime; // in 1,000's of hours between failure
    
public:
    Storage(const string& name, const string& serialNum, double price, double cost, const string& deviceType, int capacityGB, double xferSpeed, int lifetime);  // Storage constructor
    ~Storage();  // Storage destructor
    string infoString() const override;   // override infoString for Storage attributes
    // accessors
    string getSerialNum() const;
    string getDevice();
    int getCapacity();
    double getXFerSpeed();
    int getLifetime();
};


