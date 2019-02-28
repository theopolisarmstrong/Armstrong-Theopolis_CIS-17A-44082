/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on February 24th, 2019, 6:23 PM
 * Purpose: Calculates population prediction
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int pop, endPop;    //starting population and ending population
    float growth;   //percentage of population growth
    short days; //number of days the populations grows
    
    //Initialize or input i.e. set variable values
    cout << "Calculates projected population\n";
    cout << "Enter the starting population: ";
    cin >> pop;
    while(pop < 2){
        cout << "Error: population less than 2\n";
        cin >> pop;
    }
    cout << "Enter population growth percentage (ex. 15): ";
    cin >> growth;
    while(growth < 0){
        cout << "Error: growth is negative\n";
        cin >> growth;
    }
    cout << "Enter the number of days to grow the population: ";
    cin >> days;
    while(days < 1){
        cout << "Error: population less than 1\n";
        cin >> days;
    }
    
    //Map inputs -> outputs
    endPop = pop;
    growth /= 100;  //convert growth percentage to decimal
    for (short day = 0; day < days; day++){ //iterate through each day
        cout << "Population at " << day + 1 << ": " << endPop << endl;
        endPop += endPop * growth;
    }
    
    //Display the outputs
    cout << "Total predicted growth of " << pop << " after " << days << " days: " << endPop << endl;

    //Exit stage right or left!
    return 0;
}