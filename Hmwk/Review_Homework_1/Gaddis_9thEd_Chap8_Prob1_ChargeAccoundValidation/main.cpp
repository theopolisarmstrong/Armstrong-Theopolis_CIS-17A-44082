/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on February 24th, 2019, 11:10 PM
 * Purpose:  Validate charge account numbers
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
int search(const int words[], int size, int query); //binary search names array

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    const char ACCOUNTS = 20;
    int account[ACCOUNTS] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 8080152,
                                4562555, 5552012, 5050552, 7825877, 1250255, 10005231, 654231,
                                3852085, 7576651, 7881200, 4581002};
    int index;
    int query;
    
    //Initialize or input i.e. set variable values
    cout << "Charge Account Validation\n";
    cout << "Enter an account number: ";
    cin >> query;
    
    //Map inputs -> outputs
    index = search(account, ACCOUNTS, query);
    
    //Display the outputs
    if (index == -1) cout << '\'' << query << "' is not valid.\n";
    else {
        cout << '\'' << query << "' is valid.\n";
    }

    //Exit stage right or left!
    return 0;
}

int search(const int accounts[], int size, int query){
    int index = -1;
    for (int i = 0; i < size; i++){
        if (accounts[i] == query){
            return i;
        }
    }
    return index;
}