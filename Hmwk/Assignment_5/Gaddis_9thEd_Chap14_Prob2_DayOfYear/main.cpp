/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on May 13th, 2019, 8:15 PM
 * Purpose: Output the month and day of the month given the day of the year
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries
#include "DayOfYear.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int days = 0;
    
    //Initialize or input i.e. set variable values
    cout << "Enter the day of the year: ";
    cin >> days;
    
    DayOfYear current(days);
    
    //Map inputs -> outputs
    
    //Display the outputs
    current.print();

    //Exit stage right or left!
    return 0;
}