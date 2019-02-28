/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 24th, 2019, 5:17 PM
 * Purpose: Calculate the area of various shapes
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float PI = 3.14159;

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float size1, size2;
    float area; //calculated area
    char choice;    //menu choice
    
    //Initialize or input i.e. set variable values
    cout << "Geometry Calculator\n";
    cout << "\t1. Calculate the Area of a Circle\n";
    cout << "\t2. Calculate the Area of a Rectangle\n";
    cout << "\t3. Calculate the Area of a Triangle\n";
    cout << "\t4. Quit\n";
    cout << "Enter your choice (1-4): ";
    cin >> choice;
    choice-=48;
    
    //Map inputs -> outputs
    switch(choice){
        case 1: //circle
            cout << "Enter the radius: ";
            cin >> size1;
            area = PI * (size1*size1);
            break;
        case 2: //rectangle
            cout << "Enter the length and width: ";
            cin >> size1 >> size2;
            area = size1 * size2;
            break;
        case 3: //triangle
            cout << "Enter the base and height: ";
            cin >> size1 >> size2;
            area = size1 * size2 * 0.5;
            break;
        case 4:
            return 0;
            break;
    }
    
    //Display the outputs
    cout << "Area: " << area << endl;

    //Exit stage right or left!
    return 0;
}