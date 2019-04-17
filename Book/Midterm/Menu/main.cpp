/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 17th, 2019, 3:15 AM
 * Purpose: Menu project for Midterm problems
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

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
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
//Problem 1 functions
void valid(float &input, string error);
float inLoop(const float);
//Problem 2 functions

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='4');
    
    //Exit stage right!
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Menu
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Checking Account Balance program (Problem 1)"<<endl;
    cout<<"Type 2 for Gross Employee Pay program (Problem 2)"<<endl;
    cout<<"Type 3 for Ternary Op example"<<endl;   
    cout<<"Type 4 for Switch-Case example"<<endl<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 1
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm1(){
    cin.ignore(); //Ignore menu choice input
    cout<<"Problem 1"<<endl;
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

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 2
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm2(){
    cout<<"Problem 2"<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 3
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm3(){
    cout<<"Problem 3"<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 4
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm4(){
    cout<<"problem 4"<<endl;
}