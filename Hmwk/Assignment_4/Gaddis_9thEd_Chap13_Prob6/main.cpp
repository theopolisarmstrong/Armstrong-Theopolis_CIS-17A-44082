/*
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on May 5th, 2019, 5:12 AM
 * Purpose: Create and demonstrate an inventory class w/ overloaded contructors
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> //Input/Output Stream Manipulation
using namespace std;

//User Libraries
#include "Inventory.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    Inventory *item;
    int itemNumber, quantity;
    float cost;
    
    //Initialize or input i.e. set variable values
    cout << "Enter the item's number: ";
    cin >> itemNumber;
    cout << "Enter the item's quantity: ";
    cin >> quantity;
    cout << "Enter the item's cost: $";
    cin >> cost;
    
    item = new Inventory(itemNumber, quantity, cost);
    
    //Map inputs -> outputs
    
    //Display the outputs
    cout << "Item Number: " << item->getItemNumber() << endl;
    cout << "Quantity: " << item->getQuantity() << endl;
    cout << setprecision(2) << fixed;
    cout << "Individual cost: $" << item->getCost() << endl;
    cout << "Total cost: $" << item->getTotalCost() << endl;
    
    //Exit stage right or left!
    delete item;
    return 0;
}
