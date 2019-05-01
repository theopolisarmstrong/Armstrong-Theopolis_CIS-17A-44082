/*
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 30th, 2019, 6:15 PM
 * Purpose: Calculate birth and death rates
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries
#include "Population.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
bool valid(int, const int&);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    const int POP_MIN = 1;
    const int BIR_MIN = 0;
    const int DEA_MIN = 0;
    Population population;
    int pop, dea, bir;
    
    //Initialize or input i.e. set variable values
    cout << "Enter population: ";
    cin >> pop;
    while (!valid(pop, POP_MIN)){
        cout << "Error: Population input out of range.\n" << "Enter a valid population number: ";
        cin >> pop;
    }
    cout << "Enter birth rate: ";
    cin >> bir;
    while (!valid(bir, BIR_MIN)){
        cout << "Error: Birth rate input out of range.\n" << "Enter a valid birth rate: ";
        cin >> bir;
    }
    cout << "Enter death rate: ";
    cin >> dea;
    while (!valid(dea, DEA_MIN)){
        cout << "Error: Death rate input out of range.\n" << "Enter a valid death rate: ";
        cin >> dea;
    }
    
    //Map inputs -> outputs
    population.setPop(pop);
    population.setBir(bir);
    population.setDea(dea);
    
    //Display the outputs
    cout << "Birth rate: " << population.birRate() << endl;
    cout << "Death rate: " << population.deaRate() << endl;
    
    //Exit stage right or left!
    return 0;
}

bool valid(int val, const int &min){
    if(val < min) return false;
    else return true;
}
