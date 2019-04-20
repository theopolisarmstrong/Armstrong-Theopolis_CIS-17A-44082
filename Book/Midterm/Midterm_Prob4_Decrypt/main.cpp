/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 19th, 2019, 1:39 PM
 * Purpose: Decrypts a 4 digit integer
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const unsigned char CHARNUM = 48;

//Function Prototypes
bool valid(const char[], const unsigned char); //Validate C-string
void decrypt(char[], const unsigned char); //Decrypt number array

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    const unsigned char SIZE = 4;
    
    char in[4] = {0};
    short data = 0;
    short eData = 0;
    
    //Initialize or input i.e. set variable values
    cout << "Enter an encrypted 4-digit integer using digits : ";
    cin >> in;
    while(!valid(in, SIZE)){
        cout << "Error: integer out of range\nEnter a new integer: ";
        cin >> in;
    }
    
    //Map inputs -> outputs
    //Convert C-string to integers
    decrypt(in, SIZE);
    
    //Display the outputs
    cout << "Decrypted Number: " << in;

    //Exit stage right or left!
    return 0;
}

bool valid(const char s[], const unsigned char size){
    for (char i = 0; i < size; i++){
        if (s[i] < '0' || s[i] > '7')
            return false;
    }
    return true;
}

void decrypt(char s[], const unsigned char size){
    char swap;
    //Swap elements 1 & 3
    swap = s[0];
    s[0] = s[2];
    s[2] = swap;
    //Swap elements 2 & 4
    swap = s[1];
    s[1] = s[3];
    s[3] = swap;
    //Arithmetic encryption
    for (char i = 0; i < size; i++){
        switch(s[i]){
            case '6':
                s[i] = '1';
                break;
            case '7':
                s[i] = '2';
                break;
            case '0':
                s[i] = '3';
                break;
            case '1':
                s[i] = '4';
                break;
            case '2':
                s[i] = '5';
                break;
            case '3':
                s[i] = '6';
                break;
            case '4':
                s[i] = '7';
                break;
        }
    }
}