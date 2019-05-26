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
    SimpleVector<int> sv(size); //Create SimpleVector
    //Map inputs -> outputs
    for (int i = 0; i < sv.size(); i++){
        sv[i] = (rand() % 100) + 10;
    }
    SimpleVector<int> svOld(sv); //Save sv state
    //Push back 3 elements
    sv.push((rand() % 100) + 10);
    sv.push((rand() % 100) + 10);
    sv.push((rand() % 100) + 10);
    SimpleVector<int> svPush(sv); //Save pushed state
    //Pull/delete 2 elements
    sv.pull();
    sv.pull();
    
    //Display the outputs
    cout << "Original SimpleVector: ";
    for (int i = 0; i < svOld.size(); i++){
        cout << svOld[i] << ' ';
    }
    cout << endl;
    cout << "Adding three elements: ";
    for (int i = 0; i < svPush.size(); i++){
        cout << svPush[i] << ' ';
    }
    cout << endl;
    cout << "Pulling four elements: ";
    for (int i = 0; i < sv.size(); i++){
        cout << sv[i] << ' ';
    }
    cout << endl;

    //Exit stage right or left!
    return 0;
}