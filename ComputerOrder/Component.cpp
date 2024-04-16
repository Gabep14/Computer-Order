//
//  Component.cpp
//
//  Created by Gabriel Push on 2/8/24.
//

#include <stdio.h>
#include "Component.h"
#include <sstream>
#include <fstream>

// initialize Component constructor
Component::Component(const string& name, const string& serialNum, double price, double cost) : name(name), serialNum(serialNum), price(price), cost(cost) {}

// destructor
Component::~Component() {}

// using stringstream to return a string of name, price, and cost for every Component
string Component::infoString() const {
    stringstream ss;
    ss << left << fixed << setprecision(2) << name << " #" << serialNum << " Price: " << price << " Cost: " << cost << endl;
    return ss.str();
}

// displays infoString
void Component::displayInfo() const {
    cout << infoString() << endl;
}

// accessors, get attributes

string Component::getName() { return name; }

string Component::getSerialNum() const { return serialNum; }

double Component::getPrice() { return price; }

double Component::getCost() { return cost; }
