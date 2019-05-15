/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on May 14th, 2019, 9:10 AM
 * Purpose: Converts work hours to days
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries
#include "NumDays.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int hours = 0, hours2 = 0;
    
    //Initialize or input i.e. set variable values
    cout << "Enter Employee 1's hours: ";
    cin >> hours;
    cout << "Enter Employee 2's hours: ";
    cin >> hours2;
    
    NumDays employee(hours);
    NumDays employee2(hours2);
    NumDays empPlus;
    NumDays empMinus;
    
    //Map inputs -> outputs
    
    //Display the outputs
    empPlus = employee + employee2;
    cout << "\n+ operator: \n";
    cout << "Work Hours: " << empPlus.getHours() << endl;
    cout << "Work Days: " << empPlus.getDays() << endl;
    empPlus++;
    cout << "++ operator: \n";
    cout << "Work Hours: " << empPlus.getHours() << endl;
    cout << "Work Days: " << empPlus.getDays() << endl;
    empMinus = employee - employee2;
    cout << "- operator: \n";
    cout << "Work Hours: " << empMinus.getHours() << endl;
    cout << "Work Days: " << empMinus.getDays() << endl;
    empMinus--;
    cout << "-- operator: \n";
    cout << "Work Hours: " << empMinus.getHours() << endl;
    cout << "Work Days: " << empMinus.getDays() << endl;

    //Exit stage right or left!
    return 0;
}