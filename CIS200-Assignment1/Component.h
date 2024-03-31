//
//  Component.h
//  CIS200-Assignment1
//
//  Created by Gabriel Push on 1/29/24.
//

#pragma once
#include <iostream>
using namespace std;

class Component {
protected:
    string name;
    string serialNum;
    double price;
    double cost;
    
public:
    Component(const string& name, const string& serialNum, double price, double cost); // constructor
    virtual ~Component(); // destructor
    virtual string infoString() const;  // virtual, returns string with basic info of computer component
    void displayInfo() const;  //displays infoString
    // accessors
    string getName();
    string getSerialNum() const;
    double getPrice();
    double getCost();
};


