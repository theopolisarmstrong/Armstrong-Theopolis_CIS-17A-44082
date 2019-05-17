/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on May 17th, 2019, 1:51 PM
 * Purpose: Demonstrates total function template
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes;
template <class T>
T total(T numVals){
    T input = 0, total = 0;
    
    cout << "Enter " << numVals << " values: \n";
    for (int i = 0; i < numVals; i++){
        cin >> input;
        total += input;
        cout << "Current total: " << total << endl;
    }
    return total;
}

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int iTotal;
    float fTotal;
    char cTotal;
    
    //Initialize or input i.e. set variable values
    cout << "Integers: \n";
    iTotal = total(static_cast<int>(5));
    cout << "Floating-point: \n";
    fTotal = total(static_cast<float>(5));
    cout << "Characters: \n";
    cTotal = total(static_cast<char>(5));
    
    //Map inputs -> outputs
    cout << endl;
    cout << "Final integer total: " << iTotal << endl;
    cout << "Final floating-point total: " << fTotal << endl;
    cout << "Final character total: " << static_cast<int>(cTotal) << endl;
    
    //Display the outputs

    //Exit stage right or left!
    return 0;
}