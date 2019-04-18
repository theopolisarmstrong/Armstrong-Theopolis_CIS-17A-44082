/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on February 11th, 2019, 12:36 PM
 * Purpose: Calculate gross paycheck and overtime
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
#include <math.h>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const unsigned char CHARNUM = 48;
const float TRI = 3; 

//Structures
struct Emp{
    string name;
    int hours;
    float rate;
    float payNum;
    string payStr;
};

//Function Prototypes
char** new2d(char);
Emp getEmp();
Emp outEmp(Emp);

string tenToEng(char); //Convert tens place single digit to English words
string teenEng(char); //Converts ones place place to teens
string toEng(char); //Convert single digit to English words
string toStr(int); //Converts integer to string to words
int toInt(string); //Converts string number to int  "5" --> 5
string placeS(int); //Returns place name for each place
void reverse(char**, char);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    Emp* employs;
    int empNum = 0;
    int whole = 0, dec = 0;
    char** pay;
    char size = 0;
    int place = 1, triplet = 1; //Place of single digit, place of triplet
    
    //Initialize or input i.e. set variable values
    cout << "How many employees would you like to enter? ";
    cin >> empNum;
    //Allocate employee array
    employs = new Emp[empNum];
    //Input employee data
    //3 Jester Lavorre
    for (int i = 0; i < empNum; i++){
        cin.ignore();
        employs[i] = getEmp();
    }
    for (int i = 0; i < empNum; i++){
        outEmp(employs[i]);
    }
    
    
    
//    size = ceil(payIn.size() / TRI); //Find size of first dimension
//    //Allocate 2D array
//    pay = new2d(size);
//    //Copy string to 2D array
//    for (int i = 0, j = payIn.size()-1; i < size; i++){
//        for (int k = TRI-1; k >= 0; k--){
//            pay[i][k] = payIn[j];
//            j--;
//        }
//    }
//    reverse(pay, size); //Correct triplet order
//    //Set place to the highest place value
//    for (int i = 0; i < size - 1; i++)
//        place *= 10;
//    
//    for (int i = 0; i < size; i++){
//        for (int j = 0; j < TRI; j++){
//            cout << pay[i][j];
//        }
//        if (i != size-1) cout << ',';
//    }
//    cout << endl;
//    
//    //Map inputs -> outputs
//    cout << "Test: " << static_cast<int>(pay[0][0]) << endl;
//    for (int i = 0, t = size - 1; i < size; i++){
//            if (pay[i][0] != 0) cout << toEng(pay[i][0]) << " Hundred ";
//            if (pay[i][1] == '1'){ //Output teens
//                cout << teenEng(pay[i][2]) << ' ';
//            } else {
//                if (pay[i][1] != 0) cout << tenToEng(pay[i][1]) << ' ';
//                if (pay[i][2] != 0) cout << toEng(pay[i][2]) << ' ';
//            }
//        if (i != size) cout << placeS(t) << ' ';
//        t--;
//    }
//    cout << "Dollars";
    
    //Display the outputs
//    cout << "Pay: $" << employs[0].payNum << endl;
//    cout << "Pay: $" << employs[0].payStr;

    //Exit stage right or left!
    return 0;
}

char** new2d(char size){
    char** a = new char*[size];
    for (int i = 0; i < size; i++){
        a[i] = new char[3];
    }
}

Emp getEmp(){
    Emp temp;
    cout << "Enter the employee's information: \n";
    cout << "Name: ";
    getline(cin, temp.name);
    cout << "Hours: ";
    cin >> temp.hours;
    cout << "Pay rate: ";
    cin >> temp.rate;
    return temp;
}

Emp outEmp(Emp e){
    cout << "Lavish Chateau\n";
    cout << "Lavish Chateau, Nicodranis\n";
    cout << "Name: " << e.name << endl;
    cout << "rate: " << e.rate << endl;
    cout << "hours: " << e.hours << endl;
}

string toEng(char n){
    switch(n){
        case 1:
        case '1':
            return "One";
            break;
        case 2:
        case '2':
            return "Two";
            break;
        case 3:
        case '3':
            return "Three";
            break;
        case 4:
        case '4':
            return "Four";
            break;
        case 5:
        case '5':
            return "Five";
            break;
        case 6:
        case '6':
            return "Six";
            break;
        case 7:
        case '7':
            return "Seven";
            break;
        case 8:
        case '8':
            return "Eight";
            break;
        case 9:
        case '9':
            return "Nine";
            break;
    }
}
string tenToEng(char n){
    switch(n){
        case 2:
        case '2':
            return "Twenty";
            break;
        case 3:
        case '3':
            return "Thirty";
            break;
        case 4:
        case '4':
            return "Forty";
            break;
        case 5:
        case '5':
            return "Fifty";
            break;
        case 6:
        case '6':
            return "Sixty";
            break;
        case 7:
        case '7':
            return "Seventy";
            break;
        case 8:
        case '8':
            return "Eighty";
            break;
        case 9:
        case '9':
            return "Ninety";
            break;
    }
}
string teenEng(char n){
    switch(n){
        case 0:
        case '0':
            return "Ten";
            break;
        case 1:
        case '1':
            return "Eleven";
            break;
        case 2:
        case '2':
            return "Twelve";
            break;
        case 3:
        case '3':
            return "Thirteen";
            break;
        case 4:
        case '4':
            return "Fourteen";
            break;
        case 5:
        case '5':
            return "Fifteen";
            break;
        case 6:
        case '6':
            return "Sixteen";
            break;
        case 7:
        case '7':
            return "Seventeen";
            break;
        case 8:
        case '8':
            return "Eighteen";
            break;
        case 9:
        case '9':
            return "Nineteen";
            break;
    }
}
int toInt(string s){
    int n = 0, place = 1; //Place value; place
    //Convert each place to a number
    for(char i = s.size()-1; i >= 0; i--){
        n += (s[i] - CHARNUM) * place; //Set each place value to it's correct place
        place *= 10; //Move to next place value
    }
    return n;
}

string placeS(int c){
    string place;
    switch(c){
        case 1:
            return "Thousand";
            break;
        case 2:
            return "Million";
            break;
        case 3:
            return "Billion";
            break;
    }
    return place;
}

void reverse(char** a, char size){
    char* swap;
    for (int i = 0; i < size / 2; i++){
        swap = a[i];
        a[i] = a[size-1-i];
        a[size-1-i] = swap;
    }
}