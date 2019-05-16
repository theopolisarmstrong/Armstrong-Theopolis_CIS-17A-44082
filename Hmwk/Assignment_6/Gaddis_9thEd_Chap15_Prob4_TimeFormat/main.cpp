/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on May 16th, 2019, 8:46 AM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//User Libraries
#include "MilTime.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int hour, second;
    
    //Initialize or input i.e. set variable values
    cout << "Enter a time in military hours (2359:59): ";
    cin >> hour;
    cin.ignore();
    cin >> second;
    
    MilTime time(hour, second);
    
    //Map inputs -> outputs
    
    //Display the outputs
    cout << "Military format: " << time.getHour() << " hours " << time.getSec() << " seconds\n";
    cout << "Standard format: " << time.getStandHr() << ':' << setw(2) << setfill('0') << time.getMin() << ':' << setw(2) << setfill('0') << time.getSec() << endl;

    //Exit stage right or left!
    return 0;
}