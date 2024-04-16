//
//  main.cpp
//
//  Created by Gabriel Push on 1/29/24.
//

#include <iostream>
#include "Component.h"
#include "CPU.h"
#include "Memory.h"
#include "Storage.h"
#include "System.h"
#include "Order.h"
#include "OrderMgr.h"


int main() {
    
    OrderMgr orderMgr; // create orderMgr object of OrderMgr
   
    orderMgr.readOrder("Orders.txt"); // call readOrder of "Orders.txt" using orderMgr object
    orderMgr.printInvoices("Invoices.txt"); // call printInvoices creating file "Invoices.txt" using orderMgr object
    orderMgr.printSummary(); // print summary to console using orderMgr object
    
    return 0;
}
