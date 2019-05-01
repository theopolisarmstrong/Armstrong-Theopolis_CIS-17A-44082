/*
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 30th, 2019, 4:58 PM
 * Purpose: RetailItem class definition
 */

#include "RetailItem.h"

RetailItem::RetailItem(string desc, int u, float p){
    description = desc;
    unitsOnHand = u;
    price = p;
}
