/* 
 * File:   main.cpp
 * Author: Armstrong, Theopolis
 * Created on March 15th, 2019, 5:12 PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
int *getData(int &);            //Fill the array
int *sort(const int *,int);     //Sort smallest to largest
int *reverse(const int *,int);  //Sort in reverse order
void prntDat(const int *,int);  //Print the array

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int *inArr, *sortArr, *revArr, size;
    
    //Initialize or input i.e. set variable values
    inArr = getData(size);
    
    //Map inputs -> outputs
    sortArr = sort(inArr, size);
    revArr = reverse(sortArr, size);
    
    //Display the outputs
    prntDat(sortArr, size);
    cout << endl;
    prntDat(revArr, size);

    //Exit stage right or left!
    return 0;
}

//Fill the array
int *getData(int &size){
    cin >> size;
    int *array = new int[size];
    for (int i = 0; i < size; i++){
        cin >> array[i];
    }
    return array;
}

//Sort smallest to largest
int *sort(const int *array, int size){
    //Copy data to new dynamic array
    int *sorted = new int[size];
    for (int i = 0; i < size; i++){
        sorted[i] = array[i];
    }
    //Selection sort copied array
    int minIndex, min;
    for (int i = 0; i < size - 1; i++){
        minIndex = i;
        min = sorted[i];
        for (int j = i + 1; j < size; j++){
            if (sorted[j] < min){
                min = sorted[j];
                minIndex = j;
            }
        }
        int swap;
        swap = sorted[i];
        sorted[i] = sorted[minIndex];
        sorted[minIndex] = swap;
    }
    
    return sorted;
}

//Sort in reverse order
int *reverse(const int *array, int size){
    int *revArr = new int[size];
    for (int j = 0, i = size - 1; i >= 0; i--){
        revArr[j] = array[i];
        j++;
    }
    return revArr;
}

//Print the array
void prntDat(const int *array, int size){
    for (int i = 0; i < size; i++){
        i != size - 1 ? cout << array[i] << ' ' : cout << array[i];
    }
}