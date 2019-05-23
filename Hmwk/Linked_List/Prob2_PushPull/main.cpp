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
    
    //Initialize or input i.e. set variable values
    cout << "Enter Simple Vector size: ";
    cin >> size;
    
    SimpleVector<int> sv(size);
    
    //Map inputs -> outputs
    for (int i = 0; i < sv.size(); i++){
        sv[i] = (rand() % 100) + 10;
    }
    //Push back 3 elements
    sv.push((rand() % 100) + 10);
//    sv.push((rand() % 100) + 10);
//    sv.push((rand() % 100) + 10);
    
    //Display the outputs
    for (int i = 0; i < sv.size(); i++){
        cout << sv[i] << ' ';
    }
    cout << endl;

    //Exit stage right or left!
    return 0;
}