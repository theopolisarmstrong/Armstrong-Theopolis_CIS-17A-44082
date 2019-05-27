/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on May 23th, 2019, 12:33 AM
 * Purpose: Fill Simple Vector with a number of random 2 digit numbers
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <stdlib.h>
#include <time.h>
using namespace std;

//User Libraries
#include "SimpleVector.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(time(0));
    
    //Declare Variables
    int size = 0;
    SimpleVector<int> sv;
    
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    //Push back 3 elements
    sv.append((rand() % 100) + 10);
    sv.append((rand() % 100) + 10);
    //Pull/delete 4 elements
    sv.insert((rand() % 100) + 10);
    //Delete 
    
    
    //Display the outputs
    sv.display();

    //Exit stage right or left!
    return 0;
}