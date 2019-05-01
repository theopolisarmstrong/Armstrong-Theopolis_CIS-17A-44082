/*
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 30th, 2019, 4:58 PM
 * Purpose: RetailItem class declaration
 */

#ifndef RetailItem_h
#define RetailItem_h

#include <iostream>
using namespace std;

class RetailItem{
private:
    string description = "";
    int unitsOnHand = 0;
    float price = 0.0;
public:
    RetailItem(string desc, int u, float p);
    void setDesc(string desc){ description = desc; }
    void setUnits(int u){ unitsOnHand = u; }
    void setPrice(float p){ price = p; }
    string getDesc() const { return description; }
    int getUnits() const { return unitsOnHand; }
    float getPrice() const { return price; }
};

#endif /* RetailItem_h */
