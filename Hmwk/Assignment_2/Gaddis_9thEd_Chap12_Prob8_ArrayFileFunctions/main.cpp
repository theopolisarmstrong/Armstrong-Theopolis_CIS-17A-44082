/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 7th, 2019, 1:11 AM
 * Purpose: Output the contents of an array to a file, read file to another array and output array
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <fstream> //File Input/Output
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void arrayToFile(const string, const int [], const int); //Output the contents of an array to file
void fileToArray(const string, int [], const int); //Input file contents to array

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    const int SIZE = 20;
    int nums[SIZE] = {4, 767, 4, 54, 5, 16, 45, 7, 845, 65, 5, 8, 95, 9, 27, 6, 3, 0, 79, 37}; //Numbers to output to file
    int fNums[SIZE]; //Numbers read from file
    string name = "nums.txt"; //Name of input file
    
    //Initialize or input i.e. set variable values
    arrayToFile(name, nums, SIZE);
    
    //Map inputs -> outputs
    fileToArray(name, fNums, SIZE);
    
    //Display the outputs
    cout << "Array read from file: \n";
    for (int i = 0; i < SIZE; i++)
        cout << fNums[i] << ' ';
    cout << endl;

    //Exit stage right or left!
    return 0;
}

void arrayToFile(const string name, const int array[], const int size){ //Output the contents of an array to file
    fstream file(name, ios::out | ios::binary); //Open file in binary output mode
    file.write(reinterpret_cast<const char *>(array), size * sizeof(int)); //Write the contents of the array to the file
    file.close();
}

void fileToArray(const string name, int array[], const int size){ //Input file contents to array
    fstream file(name, ios::in | ios::binary);//Open file in binary input mode
    file.read(reinterpret_cast<char *>(array), size * sizeof(int)); //Read the contents to the array
    file.close();
}