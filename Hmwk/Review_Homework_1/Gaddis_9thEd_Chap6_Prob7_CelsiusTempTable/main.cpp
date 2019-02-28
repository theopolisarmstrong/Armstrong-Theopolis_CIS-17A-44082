/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on February 24th, 2019, 8:10 PM
 * Purpose: Generates a table of Celsius-Fahrenheit conversions
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> //Input/Output Stream Manipulation
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
float celsius (float fahren);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float fahren;
    
    //Initialize or input i.e. set variable values
    cout << "Celsius conversion table\n";
    fahren = 0;
    
    //Map inputs -> outputs
    for (;fahren <= 20; fahren++){
        cout << setprecision(2) << fixed;
        cout << fahren << " degrees Fahrenheit is " << celsius(fahren) << " degrees Celsius.\n";
    }
    
    //Display the outputs

    //Exit stage right or left!
    return 0;
}

float celsius (float fahren){
    return 5/9.0 * (fahren - 32);
}