/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on June 5th, 2019, 3:53 PM
 * Purpose: Create savings account class
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries
#include "SavingsAccount.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    srand(time(0));
    SavingsAccount mine(-300);

    for(int i=1;i<=10;i++)
    {
            mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    mine.toString();
    cout<<"Balance after 7 years given 10% interest = "
            <<mine.Total((float)(0.10),7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "
            <<mine.TotalRecursive((float)(0.10),7)
            <<" Recursive Calculation "<<endl;

    //Exit stage right or left!
    return 0;
}