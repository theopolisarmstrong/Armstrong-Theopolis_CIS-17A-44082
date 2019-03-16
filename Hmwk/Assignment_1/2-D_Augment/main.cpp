/* 
 * File:   main.cpp
 * Author: Armstrong, Theopolis
 * Created on March 15th, 2019, 9:31 PM
 * Purpose: Augment a 0 in a column and row
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
int **getData(int &,int &);                 //Return the 2-D array and its size.
void prntDat(const int* const *,int,int);   //Print the 2-D Array
void destroy(int **,int,int);               //Deallocate memory
void **augment(int **,int,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int **input = nullptr, **pushed = nullptr, rowSize, colSize, augRow, augCol;
    augRow = rowSize++;
    augCol = colSize++;
    
    //Initialize or input i.e. set variable values
    input = getData(rowSize, colSize);
    
    //Map inputs -> outputs
    
    
    //Display the outputs
    prntDat(input, rowSize, colSize);
    prntDat(input, rowSize, colSize);
    
    //De-allocate arrays and pointers
    destroy(input, rowSize, colSize);
    destroy(input, rowSize, colSize);

    //Exit stage right or left!
    return 0;
}

//Return the 2-D array and its size.
int **getData(int &rowSize, int &colSize){
    cin >> rowSize >> colSize;
    int **array = new int*[rowSize];
    for (int i = 0; i < rowSize; i++){ //Create 2nd dimension
        array[i] = new int[colSize];
    }
    for (int row = 0; row < rowSize; row++){ //Fill both dimensions
        for (int col = 0; col < colSize; col++){
            cin >> array[row][col];
        }
    }
    return array;
}

//Print the 2-D Array
void prntDat(const int* const *array, int rowSize, int colSize){
    for (int row = 0; row < rowSize; row++){
        for (int col = 0; col < colSize; col++){
            col != colSize - 1 ? cout << array[row][col] << ' ' : cout << array[row][col];
        }
        cout << endl;
    }
}

//De-allocate memory
void destroy(int **array, int rowSize, int colSize){
    for (int row = 0; row < rowSize; row++){ //De-allocate rows
        delete [] array[row];
    }
    delete [] array;
}