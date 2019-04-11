/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 7th, 2019, 5:04 PM
 * Purpose: Calculates the average words per sentence from a file
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <fstream> //File Input/Output
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
int count(string);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    fstream text("text.txt", ios::in);
    string sentenc;
    int average = 0, sentNum = 0; //Average number of words; number of sentences
    
    //Initialize or input i.e. set variable values
    //Read each sentence and count the words
    while(!text.eof()){
        getline(text, sentenc);
        sentNum++;
        average += count(sentenc);
    }
    
    //Map inputs -> outputs
    average /= sentNum; //Average word count sum
    
    //Display the outputs
    cout << "Average words per sentence: " << average << endl;

    //Exit stage right or left!
    return 0;
}

int count(string sent){ //Find the number of words in a sentence
    int sum; //Word count
    (sent == "") ? sum = 0 : sum = 1; //Check for an empty sentence
    for (int i = 0; i < sent.size(); i++){ //Loop through the sentence
        if (sent[i] == ' ' && sent[i-1] != ' ') //Check for a space between each word
            sum++;
    }
    return sum;
}