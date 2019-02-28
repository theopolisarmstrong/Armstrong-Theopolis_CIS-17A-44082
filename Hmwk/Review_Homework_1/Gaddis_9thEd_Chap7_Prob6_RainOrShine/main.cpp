/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on February 24th, 2019, 8:34 PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <fstream>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const char DAYS = 30;   //total days

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    const char MONTHS = 3;  //total months
    const char DAYS = 30;
    const char JUNE = 0, JULY = 1, AUGUST = 2;
    const char RAIN= 0, CLOUD = 1, SUN = 2; //which index in the stats array correspond to what condition
    
    ifstream data("RainOrShine.txt");
    char weather[3][30];
    char stats[3][3] = {};  //total conditions for each month
    char maxR = 0;  //month with the most rainy days
    char totalR, totalC, totalS;
    
    //Initialize or input i.e. set variable values
    for (int month = 0; month < 3; month++){
        for (int day = 0; day < 30; day++){
            data >> weather[month][day];
        }
    }
    
    //Map inputs -> outputs
    for (char month = 0; month < MONTHS; month++){  //calculate the rainy, cloudy and sunny days for each month
        for (char day = 0; day < DAYS; day++){
            switch(weather[month][day]){
                case 'R':
                    stats[month][0]++;
                    break;
                case 'C':
                    stats[month][1]++;
                    break;
                case 'S':
                    stats[month][2]++;
                    break;
            }
        }
    }
    
    for (char col = 0; col < 3; col ++){    //calculate the total rainy, cloudy and sunny days
        for (char month = 0; month < MONTHS; month++){
            switch(col){
                case RAIN:
                    totalR+=stats[month][col];
                    break;
                case CLOUD:
                    totalC+=stats[month][col];
                    break;
                case SUN:
                    totalS+=stats[month][col];
                    break;
            }
        }
    }
    
    for (char month = 0; month < MONTHS; month++){  //find month with the most rain
        if (stats[month][RAIN] > stats[maxR][RAIN]){
            maxR = month;
        }
    }
    
    //Display the outputs
    cout << "Total rainy days: " << static_cast<short>(totalR) << endl << "Total cloudy days: " << static_cast<short>(totalC) << endl << "Total sunny days: " << static_cast<short>(totalS) << endl;
    switch(maxR){
        case JUNE:
            cout << "June had the most rain.\n";
            break;
        case JULY:
            cout << "July had the most rain.\n";
            break;
        case AUGUST:
            cout << "August had the most rain.\n";
            break;
    }

    //Exit stage right or left!
    return 0;
}