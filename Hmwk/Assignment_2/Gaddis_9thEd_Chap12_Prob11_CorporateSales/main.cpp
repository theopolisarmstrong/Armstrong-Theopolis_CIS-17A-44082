/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 7th, 2019, 1:47 AM
 * Purpose: Get sales figures for each quarter for each company division
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <fstream> //File Input/Output
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Enumerators

//Structures
struct DivInfo{ //Info for company division
    char name[6]; //Division name
    int sales[4]; //Quarterly sales
};

//Function Prototypes
void inSales(DivInfo &); //Fill division info

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    const char QUARTER = 4; //Quarters stored in division sales
    DivInfo east = {"East"}, west = {"West"}, north = {"North"}, south = {"South"}, output; //Info for each quarter; division to hold input from file for output
    fstream divSales("divisions.dat", ios:: in | ios::out | ios::binary); //Binary file for division info
    
    //Initialize or input i.e. set variable values
    //Input division sales figures into structs
    inSales(east);
    inSales(west);
    inSales(north);
    inSales(south);
    
    //Map inputs -> outputs
    
    //Display the outputs
    //Write division info to binary file
    divSales.write(reinterpret_cast<char *>(&east), sizeof(east));
    divSales.write(reinterpret_cast<char *>(&west), sizeof(west));
    divSales.write(reinterpret_cast<char *>(&north), sizeof(north));
    divSales.write(reinterpret_cast<char *>(&south), sizeof(south));
    //Reads sales from binary output file
    divSales.seekg(0L, ios::beg); //Reset read position
    divSales.read(reinterpret_cast<char *>(&output), sizeof(output)); //Read first division's info
    while (!divSales.eof()){ //Read and output division info until EOF
        cout << "Name: " << output.name << "\nSales: ";
        for (int i = 0; i < QUARTER; i++){
            cout << output.sales[i] << ' ';
        }
        cout << endl;
        divSales.read(reinterpret_cast<char *>(&output), sizeof(output));
    }

    //Exit stage right or left!
    return 0;
}

void inSales(DivInfo &div){ //Fill division info
    int sale;
    cout << "Enter the quarterly sales for the " << div.name << " division: \n";
    for (int i = 0; i < 4; i++){
        cin >> sale;
        while (sale < 0){ //Validate input
            cout << "Error: negative sale amount out of range.";
            cin >> sale;
        }
        div.sales[i] = sale;
    }
}