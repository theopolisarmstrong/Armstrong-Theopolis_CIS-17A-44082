/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on May 16th, 2019, 10:01 AM
 * Purpose: Demonstrate Essay class
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries
#include "Essay.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int grammar = 0, spelling = 0, length = 0, content = 0;
    
    //Initialize or input i.e. set variable values
    cout << "Enter the paper's scores:\n";
    cout << "Grammar: ";
    cin >> grammar;
    cin.ignore();
    cout << "Spelling: ";
    cin >> spelling;
    cin.ignore();
    cout << "Length: ";
    cin >> length;
    cin.ignore();
    cout << "Content: ";
    cin >> content;
    
    Essay essay(grammar, spelling, length, content);
    
    //Map inputs -> outputs
    
    //Display the outputs
    cout << "\nCriteria scores:\n";
    cout << "Grammar: " << essay.getGrammar() << endl;
    cout << "Spelling: " << essay.getSpelling() << endl;
    cout << "Length: " << essay.getLength() << endl;
    cout << "Content: " << essay.getContent() << endl;
    cout << "Total essay score: " << essay.getScore() << endl;

    //Exit stage right or left!
    return 0;
}