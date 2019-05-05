/*
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on May 5th, 2019, 12:20 AM
 * Purpose: Calculate the payroll of 7 employees using PayRoll class
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> //Input/Output Manipulation
using namespace std;

//User Libraries
#include "PayRoll.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
bool valid(char, const char); //Validate hours input against maximum allowed value

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    const float RATE = 15.42;
    const int MAX_HOURS = 60;
    const int EMP_NUM = 7;
    PayRoll employees[EMP_NUM];
    int hours = 0;
    
    //Initialize or input i.e. set variable values
    //Set employees' hours
    for (char i = 0; i < EMP_NUM; i++)
        employees[i].setRate(RATE);
    //Input and set employees' horus
    for (char i = 0; i < EMP_NUM; i++){
        cout << "Enter employee " << i+1 << "'s hours: ";
        cin >> hours;
        //Validate hours input
        while(!valid(hours, MAX_HOURS)){
            cout << "Error: exceeded maximum hours\n" << "Re-enter employee " << i+1 << "'s hours: ";
            cin >> hours;
        }
        employees[i].setHours(hours);
    }
    
    //Map inputs -> outputs
    
    //Display the outputs
    for (char i = 0; i < EMP_NUM; i++){
        cout << setprecision(2) << fixed;
        cout << "Employee " << i+1 << "'s gross pay: $" << employees[i].getPay() << endl;
    }
    
    //Exit stage right or left!
    return 0;
}

bool valid(char val, const char max){
    if (val > max)
        return false;
    else return true;
}

//22 25 40 12 3 39 50
