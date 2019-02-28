/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 24th, 2019, 4:02 PM
 * Purpose:  Lists materials that will boil and freeze at a given temperature
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
    const short eFreeze = -173; //ethyl alcohol freezing point
    const short eBoil = -38;    //ethyl alcohol boiling point
    const short mFreeze = -362; //mercury freezing point
    const short mBoil = 676;    //mercury boiling point
    const short oFreeze = -362; //oxygen freezing point
    const short oBoil = -306;   //oxygen boiling point
    const short wFreeze = 32;   //water freezing point
    const short wBoil = 212;    //water boiling point
    float temp; //testing temperature
    
    //Initialize or input i.e. set variable values
    cout << "Displays the substances which will boil and freeze at a given temperature.\n";
    cout << "Enter a temperature in Fahrenheit.\n";
    cin >> temp;
    
    //Map inputs -> outputs
    //Test ethyl alcohol
    if (temp <= -173) cout << "Ethyl alcohol will freeze.\n";
    if (temp >= 172) cout << "Ethyl alcohol will boil.\n";
    //Test mercury
    if (temp <= -38) cout << "Mercury will freeze.\n";
    if (temp >= 676) cout << "Mercury will boil.\n";
    //Test oxygen
    if (temp <= -362) cout << "Oxygen will freeze.\n";
    if (temp >= -306) cout << "Oxygen will boil.\n";
    //Test water
    if (temp <= 32) cout << "Water will freeze.\n";
    if (temp >= 212) cout << "Water will boil.\n";
    
    //Display the outputs

    //Exit stage right or left!
    return 0;
}