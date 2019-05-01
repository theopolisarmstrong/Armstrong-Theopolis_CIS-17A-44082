/*
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 30th, 2019, 5:35 PM
 * Purpose: Use circle class and calculation member functions
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries
#include "Circle.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    Circle *circ = nullptr;
    float radius = 0.0;
    
    //Initialize or input i.e. set variable values
    cout << "Enter a radius: ";
    cin >> radius;
    
    circ = new Circle(radius);
    
    //Map inputs -> outputs
    
    //Display the outputs
    cout << "Area: " << circ->getArea() << endl;
    cout << "Diameter: " << circ->getDiameter() << endl;
    cout << "Circumference: " << circ->getCircumference() << endl;
    
    //Exit stage right or left!
    delete circ;
    return 0;
}
