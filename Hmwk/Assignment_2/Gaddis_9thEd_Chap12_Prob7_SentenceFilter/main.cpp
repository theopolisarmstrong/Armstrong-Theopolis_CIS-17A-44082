/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 6th, 2019, 10:47 PM
 * Purpose: Filter a sentence and output corrected sentence to an output file.
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <fstream>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
bool openFile(string, fstream &); //Opens file for input, checks for errors while opening

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    fstream inSent, outSent("output.txt", ios::out); //File containing sentence; file to contain new sentence
    string name = "sentence.txt", sent, oldSent; //Name of input file; new altered sentence; string to output file contents
    char letter; //Character read from input file
    
    //Initialize or input i.e. set variable values
    cout << "Enter file name containing a sentence: ";
    cin >> name;
    openFile(name, inSent);
    
    //Map inputs -> outputs
    getline(inSent, oldSent); //Copy original sentence
    inSent.seekg(0L, ios::beg); //Reset read carriage
    
    letter = toupper(inSent.get()); //Read the first letter from the sentence as uppercase
    while(inSent){ //Check for EOF
        sent += letter; //Add next letter to the sentence string
        letter = tolower(inSent.get()); //Read subsequent letters from the sentence as lowercase
    }
    
    
    //Display the outputs
    cout << "\nOld sentence: \n" << oldSent << endl;
    cout << "New sentence: \n" << sent << endl;
    
    cout << "\nOutputting new sentence to output file.\n";
    outSent << sent; //Send new sentence to output file
    
    inSent.close();
    outSent.close();

    //Exit stage right or left!
    return 0;
}

bool openFile(string name, fstream & file){
    file.open(name, ios::in);  //Open input file
    if (file.fail()){ //Check for file opening errors
        cout << "Error opening file.\n";
        return 0;
    }
}