/* 
 * File:   main.cpp
 * Author: Armstrong, Theopolis
 * Created on March 15th, 2019, 3:18 PM
 * Purpose: Find the median of an array using dynamic memory allocation
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> //Input/Output Stream Manipuation Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
int *getData(int &);        //Return the array size and the array
void prntDat(int *,int);    //Print the integer array
float *median(int *,int);   //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float *);      //Print the median Array

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int *input = nullptr, size;
    float *medians = nullptr;
    
    //Initialize or input i.e. set variable values
    input = getData(size);
    
    //Map inputs -> outputs
    medians = median(input, size);
    
    //Display the outputs
    prntDat(input, size);
    cout << endl;
    prntMed(medians);
    
    //Delete allocated memory
    delete [] input;
    delete [] medians;

    //Exit stage right or left!
    return 0;
}

int *getData(int &size){ //Return the array size and the array
    cin >> size;
    int *array = new int[size]; //Create dynamic array using size input
    for (char i = 0; i < size; i++){ //Fill dynamic array with input
        cin >> array[i];
    }
    return array; //Return new array address
}

void prntDat(int *array, int size){ //Print the integer array
    for (int i = 0; i < size; i++){
        (i == size - 1) ? cout << array[i] : cout << array[i] << ' ';
    }
}

float *median(int *array, int size){ //Fill the median Array with the Float array size, the median, and the integer array data
    char medSize = size + 2; //Size of median array
    float *medArr = new float[medSize];
    medArr[0] = medSize;
    
    //Copy array to new array
    int *sorted = new int(size);
    for (int i = 0; i < size; i++){
        sorted[i] = array[i];
    }
    
    //Selection sort new array
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
    
    //Calculate and assign median to second element in median array
    if (size == 0)
        medArr[1] = 0;
    else if (size % 2 == 0)
        medArr[1] = (sorted[(size - 1) / 2] + sorted[((size - 1) / 2) + 1]) / 2.0;
    else
        medArr[1] = sorted[(size - 1) / 2];
    
    //Copy original array to fill median array
    for (char i = 0; i < size; i++){
        medArr[i+2] = array[i];
    }
    return medArr;
}

void prntMed(float *array){ //Print the median Array
    cout << static_cast<short>(array[0]) << ' '; //Output size (first element)
    cout << setprecision(2) << fixed; //Output remaining elements array
    for (char i = 1; i < array[0]; i++){
        (i == array[0] - 1) ? cout << array[i] : cout << array[i] << ' ';
    }
}