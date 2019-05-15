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
//    string month = "";
//    int days = 0;
    
    DayOfYear endYear("December", 31);
    DayOfYear startYear("January", 1);
    
    //Initialize or input i.e. set variable values
//    cout << "Enter the month (case sensitive, e.x. 'January'): ";
//    cin >> month;
//    cout << "Enter the day of the month (1-31): ";
//    cin >> days;
    cout << "Start of year object month-day input values: January 1\n";
    cout << "End of year object month-day input values: December 31\n";
    
    //Map inputs -> outputs
    cout << "Decrementing start of year...\n";
    startYear--;
    cout << "Incrementing end of year...\n";
    endYear++;
    
    //Display the outputs
    cout << "New start of year object value: ";
    startYear.print();
    cout << "End of year object values: ";
    endYear.print();

    //Exit stage right or left!
    return 0;
}