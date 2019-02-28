/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on February 24th, 2019, 10:30 PM
 * Purpose: Sort and search an array of strings using a binary search
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void sort(string words[], int size);    //selection sort names array
int search(const string words[], int size, string query); //binary search names array

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    const char NAMES = 20;
    string words[NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim", "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                        "Taylor, Terri", "Johnson, Jill", "James, Jean", "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
                        "Javens, Renee", "Harrison, Rose", "Setzer, Cathy", "Pike, Gordon", "Holland, Beth"};
    int index;
    string lastName, firstName, query;
    
    //Initialize or input i.e. set variable values
    cout << "Search for string\n";
    cout << "Enter a string to search: ";
    cin >> lastName >> firstName;
    query = lastName + ' ' + firstName;
    
    //Map inputs -> outputs
    sort(words, NAMES);
    index = search(words, NAMES, query);
    
    //Display the outputs
    if (index == -1) cout << '\'' << query << "' was not found.\n";
    else {
        cout << '\'' << query << "' was found at index " << index << ".\n";
    }

    //Exit stage right or left!
    return 0;
}

void sort(string words[], int size){
    int minIndex;
    string min;
    for(int start = 0; start < (size - 1); start ++){
        minIndex = start;
        min = words[start];
        for (int i = start + 1; i < size; i++){
            if (words[i] < min){
                min = words[i];
                minIndex = i;
            }
        }
        string swap = words[minIndex];
        words[minIndex] = words[start];
        words[start] = swap;
    }
}

int search(const string words[], int size, string query){
    int first = 0,
            last = size - 1,
            mid,
            index = -1;
    bool found = false;
    
    while (!found && first <= last){
        mid = (first + last) / 2;
        if (words[mid] == query){
            found = true;
            index = mid;
        }
        else if (words[mid] > query)
            last = mid - 1;
        else
            first = mid + 1;
    }
    return index;
}