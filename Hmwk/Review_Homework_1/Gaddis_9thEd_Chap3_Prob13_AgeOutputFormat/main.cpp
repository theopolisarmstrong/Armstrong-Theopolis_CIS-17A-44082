/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on February 24th, 2019, 2:39 PM
 * Purpose:  Convert U.S. dollars to Japanese yen and European Euros
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  //Input/Output Stream Manipulation Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
float YEN_PER_DOLLAR = 110.773;
float EUROS_PER_DOLLAR = 0.882070;

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float dollar, yen, euro;
    
    //Initialize or input i.e. set variable values
    cout << "Converts U.S. dollars to Yen and Euros.\n";
    cout << "Enter the amount of U.S. dollars:\n";
    cin >> dollar;
    
    //Map inputs -> outputs
    yen = dollar * YEN_PER_DOLLAR;  //convert dollar to yen
    euro = dollar * EUROS_PER_DOLLAR;   //convert dollar to euro
    
    //Display the outputs
    cout << setprecision(2) << fixed << endl;
    cout << "Dollars: $" << dollar << endl << "Yen: ¥" << yen << endl << "Euros: €" << euro << endl;

    //Exit stage right or left!
    return 0;
}