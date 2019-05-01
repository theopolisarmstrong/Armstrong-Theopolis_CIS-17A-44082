/*
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 30th, 2019, 4:55 PM
 * Purpose: Hold retail item data
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries
#include "RetailItem.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    const int ITEMS = 3;
    RetailItem inventory[ITEMS] = {RetailItem("Jacket", 12, 59.95), RetailItem("Designer Jeans", 40, 34.95), RetailItem("Shirt", 20, 24.95)};
    
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    
    //Display the outputs
    cout << "\t\t Description\tUnits On Hand\tPrice\n";
    cout << "Item #1: " << inventory[0].getDesc() << "\t\t\t" << inventory[0].getUnits() << "\t\t\t\t$" << inventory[0].getPrice() << endl;
    cout << "Item #2: " << inventory[1].getDesc() << "\t" << inventory[1].getUnits() << "\t\t\t\t$" << inventory[1].getPrice() << endl;
    cout << "Item #3: " << inventory[2].getDesc() << "\t\t\t" << inventory[2].getUnits() << "\t\t\t\t$" << inventory[2].getPrice() << endl;
    
    //Exit stage right or left!
    return 0;
}
