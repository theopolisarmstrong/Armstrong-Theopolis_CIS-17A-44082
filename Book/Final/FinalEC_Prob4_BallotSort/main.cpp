/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on June th, 2019, 5:52 PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <fstream>
#include <regex>
using namespace std;

//User Libraries
#include "Prob2Sort.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    Prob2Sort<string> rc;
    bool ascending=true;
    ifstream infile;
    infile.open("Ballot.txt",ios::in);
    char *ch2=new char[10*16];
    char *ch2p=ch2;
    while(infile.get(*ch2)){cout<<*ch2;ch2++;}
    infile.close();
    char *zc=rc.sortArray(ch2p,10,16);
    for(int i=0;i<10;i++)
    {
            for(int j=0;j<16;j++)
            {
                    cout<<zc[i*16+j];
            }
    }
    delete []zc;
    cout<<endl;

    //Exit stage right or left!
    return 0;
}