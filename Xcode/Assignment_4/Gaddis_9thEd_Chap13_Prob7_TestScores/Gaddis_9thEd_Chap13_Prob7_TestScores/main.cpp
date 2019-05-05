/*
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on May 5th, 2019, 5:32 PM
 * Purpose: Input test scores and calculate average based on the following UML class diagram
 * ---------------------------------------------------
 * |                  TestScores                     |
 * |-------------------------------------------------|
 * | - scores : int[3]                               |
 * |-------------------------------------------------|
 * | + TestScores() :                                |
 * | + setScore(score : int, index : char) : void    |
 * | + getScore() : int                              |
 * | + getAvg() : int                                |
 * ---------------------------------------------------
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries
#include "TestScores.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    TestScores student;
    int score;
    
    //Initialize or input i.e. set variable values
    for (char i = 0; i < 3; i++){
        cout << "Enter a test score: ";
        cin >> score;
        student.setScore(score, i);
    }
    
    //Map inputs -> outputs
    
    //Display the outputs
    cout << "Average score: " << student.getAvg() << endl;
    
    //Exit stage right or left!
    return 0;
}
