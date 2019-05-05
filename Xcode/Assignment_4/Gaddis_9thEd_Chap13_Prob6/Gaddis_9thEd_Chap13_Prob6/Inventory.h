/*
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on May 5th, 2019, 5:12 AM
 * Purpose: Inventory class declaration
 */

#ifndef Inventory_h
#define Inventory_h

#include <iostream>
using namespace std;

class Inventory{
private:
    int itemNumber;
    int quantity;
    float cost;
    float totalCost;
public:
    Inventory() : itemNumber(0), quantity(0), cost(0.0), totalCost(0.0) {}
    Inventory(int num, int quant, float c) {itemNumber = num; quantity = quant; cost = c; }
    void setItemNumber(int num) { itemNumber = num; }
    void setQuantity(int quant) { quantity = quant; }
    void setCost(double c) { cost = c; }
    int getItemNumber() { return itemNumber; }
    int getQuantity() { return quantity; }
    float getCost() { return cost; }
    float getTotalCost() { return quantity * cost; }
};

#endif /* Inventory_h */
