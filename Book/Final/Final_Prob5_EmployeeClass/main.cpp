/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on June 5th, 2019, 5:44 PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries
#include "Employee.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
Employee Mark("Mark","Boss",215.50);
Mark.setHoursWorked(-3);
Mark.toString();
Mark.CalculatePay(Mark.setHourlyRate(20.0),
        Mark.setHoursWorked(25));
Mark.toString();
Mark.CalculatePay(Mark.setHourlyRate(40.0),
        Mark.setHoursWorked(25));
Mark.toString();
Mark.CalculatePay(Mark.setHourlyRate(60.0),
        Mark.setHoursWorked(25));
Mark.toString();

Employee Mary("Mary","VP",50.0);
Mary.toString();
Mary.CalculatePay(Mary.setHourlyRate(50.0),
        Mary.setHoursWorked(40));
Mary.toString();
Mary.CalculatePay(Mary.setHourlyRate(50.0),
        Mary.setHoursWorked(50));
Mary.toString();
Mary.CalculatePay(Mary.setHourlyRate(50.0),
        Mary.setHoursWorked(60));
Mary.toString();

    //Exit stage right or left!
    return 0;
}