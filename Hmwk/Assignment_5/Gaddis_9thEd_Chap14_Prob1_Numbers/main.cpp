/* 
 * File: main.cpp
 * Author: Theopolis Armstrong
 * Created on May 13th, 2019, 7:57 PM
 * Purpose: Output number in words
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries
#include "Numbers.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int input;
    
    //Initialize or input i.e. set variable values
    cout << "Enter a number 0-9999: ";
    cin >> input;
    
    Numbers number(input);
    
    //Map inputs -> outputs
    
    //Display the outputs
    number.print();

    //Exit stage right or left!
    return 0;
}