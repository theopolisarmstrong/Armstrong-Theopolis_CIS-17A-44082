/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on March 26th, 2019, 8:13 AM
 * Purpose: Simulate vending machine operation
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> //Input/Output Stream Manipulation
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Structures
enum Name{COLA, ROOT, LEMON, GRAPE, CREAM, ERROR = 99, QUIT = 100};  //Menu choices and soda names
struct Soda{
    Name name; //Name of soda
    short cost; //Cost of soda
    char quant; //Quantity of soda available
};

//Function Prototypes
Name strSoda(const string &); //Validates input string and returns soda enum corresponding to validated soda name string
string sodaStr(const Name &); //Return soda name string corresponding to soda name enum
bool valid(short &, const short &, const short &); //Validate payed amount
string menu(const Soda [], const char &); //Display menu and return validated menu choice
short buy(const Name &, Soda []); //Commence purchase

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    string input; //Menu choice
    Name choice; //Menu choice as enum
    int invent = 5; //Inventory of sodas in machine
    Soda sodas[5] = {{COLA, 75, 20}, {ROOT, 75, 20}, {LEMON, 75, 20}, {GRAPE, 80, 20}, {CREAM, 80, 20}};
    short profit; //Total profits
    
    //Initialize or input i.e. set variable values
    do{
        //Output menu and receive input
        input = menu(sodas, invent);
        choice = strSoda(input);
        //Validate input
        while (choice == ERROR){
            cout << "Input error\n";
            input = menu(sodas, invent);
            choice = strSoda(input);
        }
        
        if (choice != QUIT){
            buy(choice, sodas);
            profit += sodas[choice].cost; //Calculate running profit
        }
    }while (choice != QUIT);
    
    //Map inputs -> outputs
    
    
    //Display the outputs
    cout << profit << endl;

    //Exit stage right or left!
    return 0;
}

bool valid(short & input, const short & min, const short & max){
    while (input > max || input < min){
        cout << "Error: Payment out of range\n";
        cin >> input;
    }
    return true;
}

string sodaStr(const Name & input){
    switch (input){
        case COLA:
            return "Cola";
            break;
        case ROOT:
            return "Root Beer";
        case LEMON:
            return "Lemon-Lime";
            break;
        case GRAPE:
            return "Grape Soda";
            break;
        case CREAM:
            return "Cream Soda";
            break;
    }
}

Name strSoda(const string & input){
    if (input == "Cola") return COLA;
    else if (input == "Root Beer") return ROOT;
    else if (input == "Lemon-Lime") return LEMON;
    else if (input == "Grape Soda") return GRAPE;
    else if (input == "Cream Soda") return CREAM;
    else if (input == "Quit") return QUIT;
    else return ERROR;
}

string menu(const Soda a[], const char & size){
    string input;
    
    for (int i = 0; i < size; i++){
        cout << setw(11) << left << sodaStr(a[i].name);
        cout << setw(2) << a[i].cost;
        cout << setw(4) << right << static_cast<int>(a[i].quant) << endl;
    }
    cout << "Quit\n";
    getline(cin, input);
    
    return input;
}

short buy(const Name & choice, Soda sodas[]){
    short payment;
    //Get and validate payment
    cin >> payment;
    valid(payment, 0, 100);
    //Calculate and output change
    cout << payment - sodas[choice].cost << endl;
    cin.ignore();

    sodas[choice].quant--; //Reduce available quantity of purchased soda
}