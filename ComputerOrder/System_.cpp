//
//  System_.cpp
//
//  Created by Gabriel Push on 2/8/24.
//

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "System.h"
#include <fstream>
using namespace std;

// System constructor initializing attributes
System::System() : totalPrice(0.0), totalCost(0.0) { }

// System destructor
System::~System() {
}

// add component to vector config and update totalPrice and totalCost using pointers to accessors
void System::addComponent(Component* component) {
    config.push_back(component);
    totalPrice += component->getPrice();
    totalCost += component->getCost();
}

// print invoice using ofstream and auto& to loop through each component in the config vector, using a pointer to infoString for each Component(CPU, Memory, Storage)
void System::printInvoice(ofstream& out) const {
    for (auto& component : config) {
        out << component->infoString() << endl;
    }
}

// display info for System
void System::displayInfo() const {
    std::cout << "Rich's Computer Manufacturer" << std::endl;
    std::cout << " -- System Information -- " << std::endl << std::endl;
    for (auto& component : config) {
        component->displayInfo();
    }
    std::cout << "Total Price: $" << std::fixed << std::setprecision(2) << totalPrice << std::endl;
    std::cout << "Total Cost: $" << std::fixed << std::setprecision(2) << totalCost << std::endl;
}

// accessors
vector<Component*> System::getConfig() const {
    return config;
}

double System::getTotalCost() const { return totalCost; }

double System::getTotalPrice() const { return totalPrice; }

// made a counter starting at 0 for serialNum
int counter = 0;
// add 1 to counter each time getSerialNum is called, and add it to "A0000" to generate serial num for the order
string System::getSerialNum() const {
    counter++;
    return "A0000" + to_string(counter);
}

string System::getCustName() { return custName; }
