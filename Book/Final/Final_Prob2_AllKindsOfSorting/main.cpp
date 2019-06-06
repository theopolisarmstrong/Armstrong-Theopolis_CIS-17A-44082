/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on June th, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <fstream>
using namespace std;

//User Libraries
#include "Prob2Sort.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
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
/*  No longer an issue
 *    cout << "Note: Issues reading characters from file to array.\nAnother student also mentioned this issue in the Final Canvas discussion\n";
 *    cout << "Last row in array (Kmlhmhc...) partially missing. Windows 10, NetBeans 9.0, CygWin GCC/G++ 7.4.0\n";
 */
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

    //Exit stage right or left!
    return 0;
}