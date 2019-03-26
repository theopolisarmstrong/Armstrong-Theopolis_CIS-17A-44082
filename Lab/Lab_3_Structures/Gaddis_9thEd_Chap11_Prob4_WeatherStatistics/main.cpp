/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on March 26th, 2019, 4:04 AM
 * Purpose: Read and display movie information to and from structures
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  //Input/Output Stream Manipulation
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Structures
struct Weather{
    string month;
    char rain;
    char maxTemp;
    char minTemp;
    float avgTemp;
};

//Function Prototypes
bool valid(char, char, char); //Validate weather data input
void setWeath(Weather &); //Set weather data
void getWeath(const Weather &); //Get monthly weather data

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    Weather year[12]; //weather data for each month
    char max = 0; //Highest temperature in the year
    char min = 0; //Lowest temperature in the year
    char maxTPos = 0; //Index of the highest temperature's month
    char minTPos = 0; //Index of the lowest temperature's month
    char totRain = 0; //Total rain for the year
    float avgYTemp = 0; //Average yearly temperature (average of monthy average temps)
    float avgRain = 0; //Average yearly rainfall
    
    //Initialize or input i.e. set variable values
    for (int i = 0; i < 12; i++){
        setWeath(year[i]);
    }
    //Set lowest and highest temperatures to starting month's values
    min = year[0].minTemp;
    max = year[0].maxTemp;
    
    //Map inputs -> outputs
    //Calculate average temperature for each month
    for (int i = 0; i < 12; i++){
        year[i].avgTemp = (year[i].minTemp + year[i].maxTemp) / 2.0;
    }
    //Calculate output calculations
    for (int i = 0; i < 12; i++){
        avgYTemp += year[i].avgTemp; //Total monthy temperatures
        
        if (year[i].minTemp < min){ //Find lowest temperature and index
            min = year[i].minTemp;
            minTPos = i;
        }
        if (year[i].maxTemp > max){ //Find highest temperature and index
            max = year[i].maxTemp;
            maxTPos = i;
        }
        
        totRain += year[i].rain; //Total monthly rainfall
    }
    
    avgRain = totRain / 12.0;  //Calculate average rainfall
    avgYTemp /= 12; //Calculate average yearly temperature
    
    //Display the outputs
    cout << "Average Rainfall " << setprecision(1) << fixed << avgRain << " inches/month\n";
    cout << "Lowest  Temperature " << year[minTPos].month << "  " << static_cast<int>(year[minTPos].minTemp) << " Degrees Fahrenheit\n";
    cout << "Highest Temperature " << year[maxTPos].month << "  " << static_cast<int>(year[maxTPos].maxTemp) << " Degrees Fahrenheit\n";
    cout << "Average Temperature for the year " << setprecision(0) << fixed << avgYTemp << " Degrees Fahrenheit\n";

    //Exit stage right or left!
    return 0;
}

bool valid(char & temp, char min, char max){
    while (temp < min || temp > max){
        cout << "Error: Temperature outside of range [-100, +140]\n";
        cin >> temp;
    }
    return true;
}

void setWeath(Weather & m){
    short input;
    
    cin >> m.month;
    cin >> input;
    m.rain = input;
    cin >> input;
    m.minTemp = input;
    cin >> input;
    m.maxTemp = input;
}

void getWeath(const Weather & m){
    cout << setw(9) << left << m.month << endl;
    cout << "Rain: " << setw(2) << static_cast<int>(m.rain) << endl;
    cout << "Min temp: " << setw(3) << left << static_cast<int>(m.minTemp) << endl;
    cout << "Max temp: " << setw(3) << static_cast<int>(m.maxTemp) << endl;
    cout << "Average temp: " <<  setw(3) << left << static_cast<int>(m.avgTemp) << endl;
}