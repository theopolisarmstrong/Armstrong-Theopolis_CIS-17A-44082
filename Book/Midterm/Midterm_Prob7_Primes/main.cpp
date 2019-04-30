/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 20th, 2019, 10:21 AM
 * Purpose: Find the prime factors of a given number
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <math.h> //Math Functions
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Structures
struct Prime{
    unsigned char prime;
    unsigned char power;
};
struct Primes{
    Prime *prime;
    unsigned char nPrimes;
};

//Function Prototypes
Primes *factor(int); //Input an integer, return all prime factors
void prntPrm(Primes *); //Output all prime factors

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    Primes *ans;
    int num;
    
    //Initialize or input i.e. set variable values
    cout << "Enter a number between 2 and 10,000: ";
    cin >> num;
    
    //Map inputs -> outputs
    ans = factor(num);
    
    //Display the outputs
    prntPrm(ans);

    //Exit stage right or left!
    return 0;
}

Primes *factor(int n){
    Primes *p = new Primes;
    return p;
}

void prntPrm(Primes *p){
    
}