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
int **getData(int &,int &);                     //Get the Matrix Data
void prntDat(const int* const *,int,int);       //Print the Matrix
int **augment(const int * const *,int,int);    //Augment the original array
void destroy(int **,int);                       //Destroy the Matrix, i.e., reallocate memory

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int **input = nullptr, rowSize, colSize,    //2-D dynamic array pointer and dimension sizes
            **pushed = nullptr, augRow, augCol; //Augmented 2-D array pointer and dimension sizes
    
    //Initialize or input i.e. set variable values
    input = getData(rowSize, colSize);
    
    //Map inputs -> outputs
    pushed = augment(input, rowSize, colSize);
    augRow = rowSize + 1; //Set augmented matrix dimension sizes
    augCol = colSize + 1;
    
    //Display the outputs
    prntDat(input, rowSize, colSize); //Print original 2-D array
    cout << endl;
    prntDat(pushed, augRow, augCol); //Print augmented matrix
    
    //De-allocate arrays and pointers
    destroy(input, rowSize);
    destroy(pushed, rowSize);

    //Exit stage right or left!
    return 0;
}

//Get the Matrix Data
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

//Print the Matrix
void prntDat(const int* const *array, int rowSize, int colSize){
    for (int row = 0; row < rowSize; row++){
        for (int col = 0; col < colSize; col++){
            col != colSize - 1 ? cout << array[row][col] << ' ' : cout << array[row][col];
        }
        if (row != rowSize - 1) cout << endl;
    }
}

//Augment the original array
int **augment(const int * const *array, int rowSize, int colSize){
    int augRow = rowSize + 1, augCol = colSize + 1; //Augmented matrix sizes
    //Allocate 2-D dynamic array
    int **pushed = new int*[augRow];
    for (int i = 0; i < augRow; i++){
        pushed[i] = new int[augCol];
    }
    //Fill 0 row
    for (int col = 0; col < augCol; col++){
        pushed[0][col] = 0;
    }
    //Fill 0 column
    for (int row = 1; row < augRow; row++){
        pushed[row][0] = 0;
        for (int col = 1; col < augCol; col++){
            pushed[row][col] = array[row - 1][col - 1];
        }
    }
    return pushed;
}

//Destroy the Matrix, i.e., reallocate memory
void destroy(int **array, int rowSize){
    for (int row = 0; row < rowSize; row++){ //De-allocate rows
        delete [] array[row];
    }
    delete [] array;
}