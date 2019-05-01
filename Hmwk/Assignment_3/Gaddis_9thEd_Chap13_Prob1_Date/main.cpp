/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 29th, 2019, 9:13 PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries
#include "Date.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
bool valid(int&, const int, const int); //Validate input between min and max

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    const int DAY_MIN = 1; //Minimum input value for day
    const int DAY_MAX = 31; //Maximum input value for day
    const int MONTH_MIN = 1; //Minimum input value for month
    const int MONTH_MAX = 12; //Maximum input value for month
    int month, day, year; //Date input
    
    Date current; //Current day
    
    //Initialize or input i.e. set variable values
    //Input month
    cout << "Enter the month: ";
    cin >> month;
    while(!valid(month, MONTH_MIN, MONTH_MAX)){
        cout << "Error: Month is out of range\n" << "Enter the Month: ";
        cin.ignore();
        cin >> month;
    }
    //Input day
    cout << "Enter the day: ";
    cin.ignore();
    cin >> day;
    while(!valid(day, DAY_MIN, DAY_MAX)){
        cout << "Error: Day is out of range\n" << "Enter the day: ";
        cin.ignore();
        cin >> day;
    }
    //Input year
    cout << "Enter the year: ";
    cin.ignore();
    cin >> year;
    
    //Map inputs -> outputs
    current.setMonth(month);
    current.setDay(day);
    current.setYear(year);
    
    //Display the outputs
    cout << endl;
    current.numeric();
    cout << endl;
    current.expand();
    cout << endl;
    current.mla();
    cout << endl;

    //Exit stage right or left!
    return 0;
}

bool valid(int& input, const int min, const int max){
    if (input < min || input > max)
        return false;
    return true;
}