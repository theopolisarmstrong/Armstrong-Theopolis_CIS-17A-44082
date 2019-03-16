/* 
 * File:   main.cpp
 * Author: Armstrong, Theopolis
 * Created on March 15th, 8:15 PM
 * Purpose: Insert a 0 at the beginning of an array and extend elements
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
int *getData(int &);//Read the array
int *augment(const int *,int);//Augment and copy the original array
void prntAry(const int *,int);//Print the array

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int *input = nullptr, *pushed = nullptr, size, augSize;
    augSize = size++;
    
    //Initialize or input i.e. set variable values
    input = getData(size);
    
    //Map inputs -> outputs
    pushed = augment(input, augSize);
    
    //Display the outputs
    prntAry(input, size - 1);
    cout << endl;
    prntAry(pushed, size);
    
    //De-allocate dynamic arrays and pointers
    delete [] input;

    //Exit stage right or left!
    return 0;
}

//Read the array
int *getData(int &size){
    cin >> size;
    int *array = new int[size];
    for (int i = 0; i < size; i++){
        cin >> array[i];
    }
    return array;
}

//Augment and copy the original array
int *augment(const int *array, int size){
    int *pushed = new int[size + 1];
    pushed[0] = 0;
    for (int i = 0; i < size + 1; i++){ //fill remained elements from original array
        pushed[i + 1] = array[i];
    }
    return pushed;
}

//Print the array
void prntAry(const int *array, int size){
    for (int i = 0; i < size; i++){
        (i == size - 1) ? cout << array[i] : cout << array[i] << ' ';
    }
}