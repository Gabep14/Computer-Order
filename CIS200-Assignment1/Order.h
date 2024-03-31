//
//  Order.h
//  CIS200-Assignment1
//
//  Created by Gabriel Push on 2/8/24.
//

#pragma once
#include "System.h"

// class Order to hold complete order
class Order {
private:
    int orderNum;
    string custName;
    System sysInfo; // create instance of System with info of computer system for the order
 public:
    Order(int orderNum, const string& custName, const System& sysInfo); // Order constructor
    ~Order(); // Order destructor
    void printInvoice(ofstream& outFile) const; // print order invoice using ofstream
    // accessors
    System getSystem() const; // get the System
    string getCustomerName() const;
    int getOrderNum() const;
    double getOrderPrice();
    double getOrderCost() const;
};



