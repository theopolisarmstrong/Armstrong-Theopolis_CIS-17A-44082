/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on May 16th, 2019, 6:59 AM
 * Purpose: Demonstrate ProductionWorker class
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//User Libraries
#include "ProductionWorker.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    string name = "Joe";
    int number = 53,
            day = 27, month = 7, year = 2016,
            shift = 1;
    float payRate = 17.93;
    
    //Initialize or input i.e. set variable values
    cout << "Initializing ProductionWorker...\n";
    
    ProductionWorker pwEmp(name, number, month, day, year, shift, payRate);
    
    //Map inputs -> outputs
    
    //Display the outputs
    cout << "Production Worker " << pwEmp.getName() << "'s employee data:\n";
    cout << "Employee number: " << pwEmp.getNumber() << endl;
    cout << "Hire Date: ";
    pwEmp.outDate();
    cout << endl << setprecision(2) << fixed;
    cout << "Shift: " << pwEmp.getShift() << "\tHourly Pay Rate: $" << pwEmp.getPayRate();

    //Exit stage right or left!
    return 0;
}