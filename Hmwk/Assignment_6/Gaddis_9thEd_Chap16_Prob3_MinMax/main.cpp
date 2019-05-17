/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on May 17th, 2019, 12:44 AM
 * Purpose: Demonstrate minimum & maximum template functions
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries
#include "MinMax.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int iVal1 = 5, iVal2 = 8;
    float dVal1 = 3.9, dVal2 = 3.1;
    char cVal1 = 'i', cVal2 = 'g';
    
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    
    //Display the outputs
    cout << "Integer 1: " << iVal1 << endl;
    cout << "Integer 2: " << iVal2 << endl;
    cout << "Minimum: " << minimum(iVal1, iVal2) << endl;
    cout << "Maximum: " << maximum(iVal1, iVal2) << endl;
    cout << endl;
    cout << "Double 1: " << dVal1 << endl;
    cout << "Double 2: " << dVal2 << endl;
    cout << "Minimum: " << minimum(dVal1, dVal2) << endl;
    cout << "Maximum: " << maximum(dVal1, dVal2) << endl;
    cout << endl;
    cout << "Character 1: " << cVal1 << endl;
    cout << "Character 2: " << cVal2 << endl;
    cout << "Minimum: " << minimum(cVal1, cVal2) << endl;
    cout << "Maximum: " << maximum(cVal1, cVal2) << endl;
    

    //Exit stage right or left!
    return 0;
}