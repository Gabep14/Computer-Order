//
//  OrderMgr.h
//
//  Created by Gabriel Push on 2/13/24.
//

#pragma once
#include <iostream>
#include "Order.h"

// class OrderMgr to hold the orders and methods
class OrderMgr {
private:
    vector<Order> orders; // vector of Orders
    int orderNum;
public:
    OrderMgr(); // OrderMgr constructor
    ~OrderMgr(); // OrderMgr destructor
    void readOrder(const string& filename); // reads order using string pointer
    void printInvoices(const string& filename) const; // prints invoices using string pointer
    void printSummary() const; // prints summary to console
};
