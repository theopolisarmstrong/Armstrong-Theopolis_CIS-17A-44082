/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on June 5th, 2019, 12:05 PM
 * Purpose: Final Problem 3 Spreadsheet Stuff
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries
#include "Prob3TableInherited.h"
//#include "Prob3Table.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    cout<<"Entering problem number 3"<<endl;
    int rows=5;
    int cols=6;
//    Prob3Table<int> tab("Problem3.txt",rows,cols);
    Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
    const int *naugT=tab.getTable();
    for(int i=0;i<rows;i++)
    {
            for(int j=0;j<cols;j++)
            {
                    cout<<naugT[i*cols+j]<<" ";
            }
            cout<<endl;
    }
    cout<<endl;
    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++)
    {
            for(int j=0;j<=cols;j++)
            {
                    cout<<augT[i*(cols+1)+j]<<" ";
            }
            cout<<endl;
    }

    //Exit stage right or left!
    return 0;
}