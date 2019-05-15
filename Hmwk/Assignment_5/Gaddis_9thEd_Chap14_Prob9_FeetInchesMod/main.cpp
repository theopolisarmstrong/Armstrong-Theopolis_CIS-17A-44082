/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 11th, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries
#include "FeetInches.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
string boolStr(const bool&);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    FeetInches compare1(5, 8), compare2(6, 2);
    
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    
    //Display the outputs
    cout << "compare1 <= compare2: " << boolStr(compare1 <= compare2) << endl;
    cout << "compare2 <= compare1: " << boolStr(compare2 <= compare1) << endl;
    cout << "compare1 >= compare2: " << boolStr(compare1 >= compare2) << endl;
    cout << "compare2 <= compare1: " << boolStr(compare2 <= compare1) << endl;
    cout << "compare1 != compare2: " << boolStr(compare1 != compare2) << endl;
    cout << "compare1 != compare1: " << boolStr(compare1 != compare1) << endl;

    //Exit stage right or left!
    return 0;
}

string boolStr(const bool &cond){
    string str;
    if (cond)
        str = "True";
    else
        str = "False";
    return str;
}