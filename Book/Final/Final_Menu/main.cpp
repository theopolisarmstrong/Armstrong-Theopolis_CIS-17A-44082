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
#include "Prob3TableInherited.h"
#include "SavingsAccount.h"
#include "Employee.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    char choice = 0;
    
    //Initialize or input i.e. set variable values
    while(choice == 0 || choice > '0' && choice < '7'){
        cout << "Enter a problem to run:\n";
        cout << "1. Random Sequence (extra credit included)\n";
        cout << "2. Sort\n";
        cout << "3. Spreadsheet Stuff\n";
        cout << "4. Savings Account Class\n";
        cout << "5. Employee Class\n";
        cout << "6. Conversions\n";
        cin >> choice;

        //Map inputs -> outputs
        switch(choice){
            case '1': { prob1(); break; }
            case '2': { prob2(); break; }
            case '3': { prob3(); break; }
            case '4': { prob4(); break; }
            case '5': { prob5(); break; }
            case '6': { prob6(); break; }
        }
    }
    
    //Display the outputs

    //Exit stage right or left!
    return 0;
}

void prob1(){
    char n=5;
    char rndseq[]={18,33,56,79,125};
    int ntimes=100000;
    Prob1Random<char> a(n,rndseq);
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

void prob3(){
    cout<<"Entering problem number 3"<<endl;
    int rows=5;
    int cols=6;
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
}

void prob4(){
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
}

void prob5(){
    Employee Mark("Mark","Boss",215.50);
    Mark.setHoursWorked(-3);
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(20.0),
            Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(40.0),
            Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(60.0),
            Mark.setHoursWorked(25));
    Mark.toString();

    Employee Mary("Mary","VP",50.0);
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(40));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(50));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(60));
    Mary.toString();
}

void prob6(){
    unsigned short a = 0x3C0; //Extra byte to accommodate whole number
    unsigned short b = 0xB334;
    unsigned int c = 0x59E66667;
    unsigned int product = 0;
    //a)
    cout << "3.75 base 10 = 3.6 base 8 = 3.C base 16 = 11.11 base 2    Hex Float: 78000002    Scaled 1 byte: 0x3C0\n";
    product = a * 7;
    product >>= 8; //2^-8
    cout << "  (" << a << " * 16^-2) * 7 = " << product << endl;
    cout << "  3.75 = 0 10000000 11100000000000000000000\n";
    //b)
    cout << "0.7 base 10 = ~0.54632 base 8 = ~0.B334 base 16 = ~0.1011001100 base 2    Hex Float: \tScaled 2 bytes: 0xB334\n";
    product = b * 7;
    product >>= 16; //2^-16
    cout << "  (" << b << " * 16^-4) * 7 = " << product << endl;
    cout << "  0.7 = 0 01111110 01100110011001100110011\n";
    //c)
    cout << "89.9 base 10 = 131.7146 base 8 = ~59.E667 base 16 = ~1011001.11100110011001 base 2    Hex Float: 5DCCCC06    Scaled 3 bytes: 0x59E66667\n";
    product = c * 7;
    product >>= 24; //2^-24
    cout << "  (" << c << " * 16^-8) * 7 = " << product << endl;
    cout << "  89.9 = 0 10000101 0110011110011001101101\n";
}