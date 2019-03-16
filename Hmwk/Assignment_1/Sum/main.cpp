/* 
 * File:   main.cpp
 * Author: Armstrong, Theopolis
 * Created on March 15th, 2019, 6:12 PM
 * Purpose: Output an array of sums of previous elementscin the original array
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
int *getData(int &);            //Return the array size and the array from the inputs
int *sumAry(const int *,int);   //Return the array with successive sums
void prntAry(const int *,int);  //Print the array

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    
    //Display the outputs

    //Exit stage right or left!
    return 0;
}

//Return the array size and the array
int *getData(int &size){
    cin >> size;
    int *array = new int[size]; //Create dynamic array using size input
    for (char i = 0; i < size; i++){ //Fill dynamic array with input
        cin >> array[i];
    }
    return array; //Return new array address
}

//Return the array with successive sums
int *sumAry(const int *,int){
    
}

//Print the array
void prntDat(int *array, int size){
    for (int i = 0; i < size; i++){
        (i == size - 1) ? cout << array[i] : cout << array[i] << ' ';
    }
}