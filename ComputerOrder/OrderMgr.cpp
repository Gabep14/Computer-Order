//
//  OrderMgr.cpp
//
//  Created by Gabriel Push on 2/13/24.
//

#include <stdio.h>
#include "OrderMgr.h"
#include <fstream>
#include <iostream>
#include "Order.h"

// OrderMgr constructor
OrderMgr::OrderMgr() {}

// OrderMgr destructor, uses auto& to loop through each order in the orders vector and set config vector using getSystem and getConfig accessors
OrderMgr::~OrderMgr() {
    for (auto& order : orders) {
           const vector<Component*>& config = order.getSystem().getConfig();
           for (Component* component : config) { // for each component in the config vector, delete it, freeing the memory
               delete component;
           }
       }
}

// read order from input filename
void OrderMgr::readOrder(const string& filename) {
    ifstream file(filename); // use ifstream using the file "filename"
    if (!file.is_open()) { // check if file is opened correctly
        cerr << "Error reading file: " << filename << endl;
        return;
    }
    
    // declare all variables needed to read input file into
    int orderNum;
    string custName;
    string component;
    string cpuName;
    string memoryName;
    string storageName;
    string cpuSerial;
    string memSerial;
    string storSerial;
    double cpuPrice;
    double cpuCost;
    double memPrice;
    double memCost;
    double storPrice;
    double storCost;
    int cores;
    double clockSpeed;
    int size;
    int speed;
    string deviceType;
    int capacity;
    double xFerSpeed;
    int lifetime;
    
    // while loop runs while file reads into component
    while (file >> component) {
        if (component == "//") { // check if info read from file is a comment
            file.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore comments using numeric_limits and streamsize to igore the line
            continue;
        }
        
        if (component == "[ORDER]") { // check if info read starts with [ORDER]
            file >> custName >> orderNum; // read data into customer name and order number
        }
        
        else if (component == "[CPU]") { // check if info read starts with [CPU]
            file >> cpuSerial >> cpuPrice >> cpuCost >> clockSpeed >> cores; // read data into CPU variables
            CPU* cpu = new CPU("CPU", cpuSerial, cpuPrice, cpuCost, clockSpeed, cores); // create new CPU object
            System sys; // object of System used to call addComponent to add cpu to config vector
            sys.addComponent(cpu);
            orders.emplace_back(orderNum, custName, sys); // adds a new Order object to orders vector using the order number, customer name, and System object sys
            
        } else if (component == "[MEMORY]") { // check if info read starts with [MEMORY]
            file >> memSerial >> memPrice >> memCost >> size >> speed; // read data into Memory variables
            Memory* memory = new Memory("MEMORY", memSerial, memPrice, memCost, size, speed); // create new Memory object
            System sys; // object of System used to call addComponent to add memory to config vector
            sys.addComponent(memory);
            orders.emplace_back(orderNum, custName, sys); // adds a new Order object to orders vector using the order number, customer name, and System object sys
            
        } else if (component == "[STORAGE]") { // check if info read starts with [STORAGE]
            file >> storSerial >> storPrice >> storCost >> deviceType >> capacity >> xFerSpeed >> lifetime; // read data into Storage variables
            Storage* storage = new Storage("STORAGE", storSerial, storPrice, storCost, deviceType, capacity, xFerSpeed, lifetime); // create new Storage object
            System sys; // object of System used to call addComponent to add storage to config vector
            sys.addComponent(storage);
            orders.emplace_back(orderNum, custName, sys); // adds a new Order object to orders vector using the order number, customer name, and System object sys
            
        } else if (component == "[END_ORDER]") { // check if info read starts with [END_ORDER]
            continue;
        } 
        else if (component == "[EOF]") { // check if info read starts with [EOF]
            break;
        }
    }
   file.close(); // ensure input file closes
}

// print invoices for filename
void OrderMgr::printInvoices(const string& filename) const {
    ofstream outFile(filename); // make ofstream object outFile using the filename
    if (!outFile.is_open()) { // check if outFile opens correctly
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    
    // made vector of strings to store customer names
    vector<string> custNames;
    for (const auto& order : orders) { // use auto& to loop through each order in orders vector
        bool foundCust = false; // initilize a bool to false to check if customer is found
        for (const auto& cust : custNames) { // use auto& to loop through each cust in custNames vector
            if (cust == order.getCustomerName()) { // check if cust is equal to the customer name of the order
                foundCust = true; // found customer, update to true
                break;
            }
        }
        if (!foundCust) { // if didn't find customer, add custoemr name to the custNames vector
            custNames.push_back(order.getCustomerName());
        }
    }
    
    // use auto& to loop through each cust in custNames vector
    for (const auto& cust : custNames) {
        bool custDetailsPrinted = false; // initialize a bool to false for customer details printed (not printed yet)
        double totalPrice = 0.0; // initialize double to track total price
      
        // use auto& to loop through each order in orders vector
        // this loop is so the invoice only shows details for a customer order once, not every time there is a CPU, Memory, or Storage object
        for (const auto& order : orders) {
            if (order.getCustomerName() == cust) { // check if customer name in orders vector is equal to cust
                if (!custDetailsPrinted) { // only print the new invoice if custDetailsPrinted is false, meaning the details have not been printed yet
                    outFile << "                  Gabe's Computer Manufacturer" << endl;
                    outFile << "                         -- INVOICE --        " << endl;
                    outFile << "To: " << cust << endl;
                    outFile << "Order Number: " << order.getOrderNum() << endl << endl;
                    outFile << "Custom system configured as below.         Serial #: " << order.getSystem().getSerialNum() << endl;
                    outFile << "------------------------------------------------------------------" << endl;
                    outFile << "Item      Serial#            Specification                   Price" << endl;
                    custDetailsPrinted = true; // update to true because details were printed
                }
                order.printInvoice(outFile); // call printInoice in Order class from order in orders using outFile
                totalPrice += order.getSystem().getTotalPrice(); // updates total price to getSystem from order in orders and getTotalPrice from that
            }
        }
        outFile << "                                                        ==========" << endl; // formatting to match example invoices
        outFile << right << setw(66) << fixed << setprecision(2) << totalPrice << endl << endl << endl; // display total price at end
    }
        outFile.close(); // ensure output file closes
}

// print summary to console
void OrderMgr::printSummary() const {
 // class CustomerTotals made inside printSummary to store total price, total cost, and total profit each initialized to 0.0
    class CustomerTotals {
    public:
            double totalPrice = 0.0;
            double totalCost = 0.0;
            double totalProfit = 0.0;
        };
    
    vector<string> customerNames; // create vector of customer names

    for (const auto& order : orders) { // use auto& to loop through each order in orders vector
          bool foundCustomer = false; // initialize bool to false for if customer is found
          for (auto& customer : customerNames) { // use auto& to loop through each customer in customerNames vector
              if (customer == order.getCustomerName()) { // check if customer in customerNames is equal to the customer name in order of orders vector
                  foundCustomer = true; // if met, set found to true
                  break;
              }
          }

          if (!foundCustomer) { // if didnt find customer, add the customer name from order in orders vector to back of customerNames vector
              customerNames.push_back(order.getCustomerName());
          }
      }
    // formatting
     cout << "               Gabe's Computer Manufacturer" << endl;
     cout << "                -- DAILY ORDER SUMMARY -- " << endl;
     cout << "Order #  Customer                  Price         Cost       Profit" << endl;
     cout << "------------------------------------------------------------------" << endl;
    
    // make daily total variables
    double dailyTotalPrice = 0.0;
        double dailyTotalCost = 0.0;
        double dailyTotalProfit = 0.0;

    // use auto& to loop through each customer in customerNames vector
      for (const auto& customer : customerNames) {
          CustomerTotals totals; // create totals object of CustomerTotals class
          int orderNum = 0; // initialize the order number to 0
          for (const auto& order : orders) { // loop through each order in orders vector
              if (order.getCustomerName() == customer) { // check if customer name of order in orders is equal to customer
                  orderNum = order.getOrderNum(); // if met, set orderNum to order number of order in orders
                  double price = order.getSystem().getTotalPrice(); // declare and initialize price with price of order in orders using System
                  double cost = order.getSystem().getTotalCost(); // declare and initialize cost with cost of order in orders using System
                  double profit = price - cost; // declare and initialize profit with price - cost to get the difference

                  totals.totalPrice += price; // update totals object of totalPrice with price
                  totals.totalCost += cost; // update totals object of totalCost with cost
                  totals.totalProfit += profit; // update totals object of totalProfit with profit
              }
          }

// formatting
          cout <<  orderNum << "    "  << setw(15) << left << customer  << setw(16) << right << fixed << setprecision(2) << totals.totalPrice  << setw(14) << right << fixed << setprecision(2) << totals.totalCost << setw(12) << right << fixed << setprecision(2) << totals.totalProfit << endl;

          // update the dailyTotals with totals objects of each
                  dailyTotalPrice += totals.totalPrice;
                  dailyTotalCost += totals.totalCost;
                  dailyTotalProfit += totals.totalProfit;
      }
// formatting
    // display each daily total at end of summary
    cout << "------------------------------------------------------------------" <<endl;
    cout << "Daily Total:                     " << fixed << setprecision(2) << dailyTotalPrice << setw(14) << dailyTotalCost << setw(12) << dailyTotalProfit << endl << endl;

  }
