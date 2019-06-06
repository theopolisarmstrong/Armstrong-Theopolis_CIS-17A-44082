/* 
 * File:   main.cpp
 * Author: Armstrong, Theopolis
 * Created on June 5th, 2019, 9:06 AM
 * Purpose: Menu for Spring 2019 Final problems
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <fstream>
using namespace std;

//User Libraries
#include "Prob1Random.h"
#include "Prob2Sort.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void prob1();
void prob2();

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    char choice = 0;
    
    //Initialize or input i.e. set variable values
    cout << "Enter a problem to run:\n";
    cout << "1. Random Sequence\n";
    cout << "2. Sort\n";
    cin >> choice;
    
    //Map inputs -> outputs
    switch(choice){
        case '1': { prob1(); break; }
        case '2': { prob2(); break; }
            
    }
    
    //Display the outputs

    //Exit stage right or left!
    return 0;
}

void prob1(){
    char n=5;
    char rndseq[]={18,33,56,79,125};
    int ntimes=100000;
    Prob1Random a(n,rndseq);
    for(int i=1;i<=ntimes;i++)
    {
            a.randFromSet();
    }
    int *x=a.getFreq();
    char *y=a.getSet();
    for(int i=0;i<n;i++)
    {
            cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
}

void prob2(){
    cout<<"The start of Problem 2, the sorting problem"<<endl;
    Prob2Sort<char> rc;
    bool ascending=true;
    ifstream infile;
    infile.open("Problem2.txt",ios::in);
    char *ch2=new char[10*16];
    char *ch2p=ch2;
    while(infile.get(*ch2)){cout<<*ch2;ch2++;}
    infile.close();
    cout<<endl;
    cout<<"Sorting on which column"<<endl;
    int column;
    cin>>column;
    char *zc=rc.sortArray(ch2p,10,16,column,ascending);
    for(int i=0;i<10;i++)
    {
            for(int j=0;j<16;j++)
            {
                    cout<<zc[i*16+j];
            }
    }
    delete []zc;
    cout<<endl;
}