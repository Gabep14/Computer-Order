//
//  System.h
//  CIS200-Assignment1
//
//  Created by Gabriel Push on 2/8/24.
//

#pragma once
#include "Component.h"
#include "CPU.h"
#include "Memory.h"
#include "Storage.h"
#include <vector>

// class System to aggregate instances of CPU, Memory, and Storage
class System {
private:
    vector<Component*> config; // vector to store Components
    string serialNum; // serialNum for System
    string custName; // name of customer
    double totalPrice;
    double totalCost;
public:
    System(); // System constructor
    ~System(); // System destructor
    void addComponent(Component* component); // add Component to vector
    void printInvoice(ofstream& out) const;  // print invoice using ofstream
    void displayInfo() const;  // display info
    // accessors
    vector<Component*> getConfig() const; // get vector config
    double getTotalPrice() const;
    double getTotalCost() const;
    string getSerialNum() const;
    string getCustName();
};
