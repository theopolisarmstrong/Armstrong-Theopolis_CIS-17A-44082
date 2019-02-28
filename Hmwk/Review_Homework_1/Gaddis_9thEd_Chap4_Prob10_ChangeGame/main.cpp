/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on February 24th, 2019 3:21 PM
 * Purpose:  Game which requires player to create 1 dollar using pennies, nickles, dimes and quarters
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
    const char DOLLAR = 100; //dollar amount
    short penny, nickel, quarter, dime, total;
    
    //Initialize or input i.e. set variable values
    cout << "Make a dollar using coins.\n";
    cout << "Enter the number of pennies: \n";
    cin >> penny;
    cout << "Enter the number of nickles: \n";
    cin >> nickel;
    cout << "Enter the number of dimes: \n";
    cin >> dime;
    cout << "Enter the number of quarters: \n";
    cin >> quarter;
    
    //convert respective coin amounts
    nickel*=5;
    dime*=10;
    quarter*=25;
    
    total = penny + nickel + dime + quarter;
    
    //Map inputs -> outputs
    
    //Display the outputs
    (total == DOLLAR) ? cout << "Correct! Your coins equal a dollar.\n" : cout << "Incorrect. You were off by " << DOLLAR - total << ".\n";

    //Exit stage right or left!
    return 0;
}