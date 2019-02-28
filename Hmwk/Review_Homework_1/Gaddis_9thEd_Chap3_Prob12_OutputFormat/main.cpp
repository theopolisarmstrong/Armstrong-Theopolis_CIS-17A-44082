/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on February 24th, 2019, 2:02 PM
 * Purpose:  Convert Celsius temperature to Fahrenheit
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float celsius;
    float fahren;
    
    //Initialize or input i.e. set variable values
    cout << "Converts Celsius to Fahrenheit\n";
    cout << "Input Celsius temperature: \n";
    cin >> celsius;
    
    //Map inputs -> outputs
    fahren = (9.0 / 5) * celsius + 32;  //Convert celsius to fahrenheir
    
    //Display the outputs
    cout << "Celsius: " << celsius << endl << "Fahrenheit: " << fahren << endl;

    //Exit stage right or left!
    return 0;
}