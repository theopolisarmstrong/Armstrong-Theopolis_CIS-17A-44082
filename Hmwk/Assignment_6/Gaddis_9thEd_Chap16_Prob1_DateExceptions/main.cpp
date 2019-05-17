/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on May 17th, 2019, 11:38 AM
 * Purpose: Demonstrate Date class exceptions
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries
#include "Date.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    Date valid, invalid;
    
    //Initialize or input i.e. set variable values
    cout << "Setting valid date: 10/14/2018\n";
    try {
        valid.setMonth(10);
    }
    catch (Date::InvalidMonth e){
        cout << "Error: invalid month " << e.get() << endl;
    }
    try{
        valid.setDay(14);
    }
    catch (Date::InvalidDay e){
        cout << "Error: invalid day " << e.get() << endl;
    }
    valid.setYear(2018);
    
    cout << "Setting invalid date: 13/42/2000\n"; 
    try {
        invalid.setMonth(13);
    }
    catch (Date::InvalidMonth e){
        cout << "Error: invalid month " << e.get() << endl;
    }
    try{
        invalid.setDay(42);
    }
    catch (Date::InvalidDay e){
        cout << "Error: invalid day " << e.get() << endl;
    }
    invalid.setYear(2000);
    
    //Map inputs -> outputs
    cout << "Valid date:   ";
    valid.numeric();
    cout << "\nInvalid date: ";
    invalid.numeric();
    
    //Display the outputs

    //Exit stage right or left!
    return 0;
}