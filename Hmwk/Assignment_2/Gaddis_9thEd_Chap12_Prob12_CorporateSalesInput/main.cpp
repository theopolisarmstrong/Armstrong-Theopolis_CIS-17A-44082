/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 7th, 2019, 11:55 AM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <fstream> //File Input/Output
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Structures
struct DivInfo{ //Info for company division
    char name[6]; //Division name
    int sales[4]; //Quarterly sales
    int total = 0; //Total division sales
    int average = 0; //Average division sales
};

//Function Prototypes
void highest(const int [], int &, char &, const int &); //Finds the minimum and maximum quarters
void lowest(const int [], int &, char &, const int &); //Finds the minimum and maximum quarters

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    const char NUMDIVS = 4; //Number of corporate divisions
    const char QUARTER = 4; //Number of quarterly sales records
    const char DIVSIZE = sizeof(DivInfo) - 2 * sizeof(int); //Size of division info in file (negates total and average variables)
    
    DivInfo divs[NUMDIVS]; //Corporate divisions' info
    int qSales[QUARTER] = {0}, totSale = 0; //Corporate total quarterly sales; total sales
    int high = 0, low = 0; //Highest quarterly sales; lowest quarterly sales
    char highPos = 1, lowPos = 1; //Highest quarter; lowest quarter
    fstream divSales("divisions.dat", ios::in | ios::binary); //Division info file
    
    //Initialize or input i.e. set variable values
    //Check for file opening error
    if (!divSales){
        cout << "Error opening file\n";
        return 0;
    }
    //Read division info
    int i = 0;
    while(!divSales.eof()){
        divSales.read(reinterpret_cast<char *>(&divs[i]), DIVSIZE);
        i++;
    }
    
    //Map inputs -> outputs
    //Calculate quarterly sales between all divisions, and corporate quarterly total
    for (i = 0; i < QUARTER; i++){
        for (int j = 0; j < NUMDIVS; j++){ //Calculate quarterly total
            qSales[i] += divs[j].sales[i];
        }
    }
    //Find highest and lowest quarters
    low = high = divs[0].sales[0]; //Initialize high and low quarterly sales
    highest(qSales, high, highPos, QUARTER);
    lowest(qSales, low, lowPos, QUARTER);
    //Calculate corporate total, division total, division average, high and low quarterly sales
    for (i = 0; i < NUMDIVS; i++){
        for (int j = 0; j < QUARTER; j++){ //Calculate division total
            divs[i].total += divs[i].sales[j];
            totSale += divs[i].sales[j]; //Calculate corporate total
        }
        divs[i].average = divs[i].total / QUARTER; //Calculate division average sales
    }
    
    //Display the outputs
    //Total quarterly sales
    for (i = 0; i < QUARTER; i++){
        cout << "Total sales for quarter " << i + 1 << ": $" << qSales[i] << endl;
    }
    //Total corporate sales
    cout << "Total yearly sales: $" << totSale << endl;
    //Division yearly total and quarterly average
    for (i = 0; i < NUMDIVS; i++){
        cout << divs[i].name << " division: \n";
        cout << "  Division yearly total: $" << divs[i].total << "\n  Division quarterly average: $" << divs[i].average << endl;
    }
    cout << "Corporate high was during quarter " << static_cast<int>(highPos) << " at $" << high << endl
            << "Corporate low was during quarter " << static_cast<int>(lowPos) << " at $" << low;

    //Exit stage right or left!
    return 0;
}

void lowest(const int array[], int & low, char & lowPos, const int & size){ //Find the low quarterly sales
    for (int i = 0; i < size; i++){
        if (array[i] < low){
            low = array[i];
            lowPos = i + 1;
        }
    }
}

void highest(const int array[], int & high, char & highPos, const int & size){ //Finds the lowest quarter sales
    //Find high and low corporate totals
    for (int i = 0; i < size; i++){
        //Find the high quarterly sales
        if (array[i] > high){
            high = array[i];
            highPos = i + 1;
        }
    }
}