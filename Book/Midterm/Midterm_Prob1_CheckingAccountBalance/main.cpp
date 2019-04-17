/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 17th, 2019, 3:22 AM
 * Purpose: Check checking account balance using dynamic structures
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> //Input/Output Manipulation
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Structures
struct Checking{
    string name; //Account holder name
    string address; //Account holder address
    unsigned int number; //Account number (5 digits)
    float balance; //Account balance
    float totCheck; //Total monthly check withdrawals
    float totDep; //Total deposits
};

//Function Prototypes
void valid(float &input, string error);
float inLoop(const float);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    const float ODF  = 20; //Overdraft fee
    
    Checking* account = new Checking;
    float input, odBal=0; //Loop input; estimated overdraft balance
    
    //Initialize or input i.e. set variable values
    cout << "Enter checking account information.\n";
    cout << "Name: ";
    getline(cin, account->name);
    cout << "Address: ";
    getline(cin, account->address);
    cout << "Account number (5 digits): ";
    cin >> input;
    valid(input, "Error: account number out of range. Enter a 5 digit account number: ");
    account->number = input;
    cout << "Starting Balance: ";
    cin >> account->balance;
    cout << "Value of each check written this month (Enter a 0 to continue): \n";
    account->totCheck = inLoop(0);
    cout << "Value of each deposit this month (Enter a 0 to continue): \n";
    account->totDep = inLoop(0);
    
    //Map inputs -> outputs
    account->balance += (account->totDep - account->totCheck);
    if(account->balance < 0){
        odBal = account->balance - ODF;
    }
    
    //Display the outputs
    cout << setw(16) << left << "Account name: " << account->name << endl;
    cout << setw(16) << left << "Address: " << account->address << endl;
    cout << setw(16) << left << "Account number: " << setfill('0') << setw(5) << account->number << endl;
    cout << setprecision(2) << fixed;
    cout << setw(16) << left << "Total balance : $" << account->balance << endl;
    if(odBal) cout << "\nYou will be charged an overdraft fee of $" << ODF
                   << ".\nYour new estimated balance is $" << odBal << ".\n";
    

    //Exit stage right or left!
    return 0;
}

void valid(float &input, string error){
    while (input > 99999){
        cout << error << endl;
        cin >> input;
    }
}

float inLoop(const float exit){
    float input, total = 0;
    
    cin >> input;
    while(input != exit){
        total += input;
        cin >> input;
    }
    return total;
}