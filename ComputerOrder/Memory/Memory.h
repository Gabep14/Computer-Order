//
//  Memory.h
//  CIS200-Assignment1
//
//  Created by Gabriel Push on 2/8/24.
//

#pragma once
#include "Component.h"

// Memory class inheriting from public Component
class Memory : public Component {
private:
    string serialNum; // Memory serialNum
    int sizeGB;
    int speedMHz;
public:
    Memory(const string& name, const string serialNum, double price, double cost, int sizeGB, int speedMHz); // Memory constructor
    ~Memory(); // Memory destructor
    string infoString() const override;  // override infoString for Memory
    // accessors
    string getSerialNum() const;
    int getSize();
    int getSpeed();
};
