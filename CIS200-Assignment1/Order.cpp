//
//  Order.cpp
//  CIS200-Assignment1
//
//  Created by Gabriel Push on 2/8/24.
//


#include "Order.h"
#include <fstream>
#include <iostream>


// Order constructor
Order::Order(int orderNum, const string& custName, const System& sysInfo) : orderNum(orderNum), custName(custName), sysInfo(sysInfo) {}

// Order destructor
Order::~Order() {}

// print invoice for order using ofstream and calling the sysInfo instance of System printInvoice
void Order::printInvoice(ofstream& outFile) const {
       sysInfo.printInvoice(outFile);
    }

// accessors
// gets the System info
System Order::getSystem() const { return sysInfo; }

string Order::getCustomerName() const { return custName; }

int Order::getOrderNum() const { return orderNum; }

double Order::getOrderCost() const { return sysInfo.getTotalPrice(); }

double Order::getOrderPrice() { return sysInfo.getTotalPrice(); }
