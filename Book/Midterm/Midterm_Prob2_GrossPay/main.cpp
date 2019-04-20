/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on February 11th, 2019, 12:36 PM
 * Purpose: Calculate gross paycheck and overtime
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> //Input/Output Manipulation
#include <math.h> //Math Functions
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const unsigned char CHARNUM = 48;
const float TRI = 3;
const unsigned char DUB_HRS = 40;
const unsigned char TRIP_HRS = 50;

//Structures
struct Emp{
    string name;
    float hours;
    float rate; //Hourly rate
    float payNum; //Numeric amount
    string payStr; //English amount
};

//Function Prototypes
bool inEmp(Emp&);
void outEmp(const Emp, const string, const string);

float calcPay(const float&, const float&);
string toEng(const float &);
string convert(char**, const char&);

char** new2D(const char, const char);

string tenToEng(char); //Convert tens place single digit to English words
string teenEng(char); //Converts ones place place to teens
string toEng(char); //Convert single digit to English words
string toStr(int); //Converts integer to string to words
string placeS(int); //Returns place name for each place

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    const string COMPANY = "Picus Communications Corporation"; //Company name
    const string ADDRESS = "4545 Pierre-de-Coubertin Avenue"; //Company address
    const int MAXEMP = 1000; //Maximum number of employees in employs array
    
    Emp employs[MAXEMP];
    int empNum = 0; //Number of entered employees
    
    //Initialize or input i.e. set variable values
    //Input employee data
    while(inEmp(employs[empNum])){
        cin.ignore();
        empNum++;
    }
    
    //Map inputs -> outputs
    //Calculate pay
    for (int i = 0; i < empNum; i++){
        employs[i].payNum = calcPay(employs[i].hours, employs[i].rate);
    }
    //Convert pay to English
    for (int i = 0; i < empNum; i++){
        employs[i].payStr = toEng(employs[i].payNum);
    }
    
    //Display the outputs
    cout << endl;
    for (int i = 0; i < empNum; i++){
        outEmp(employs[i], COMPANY, ADDRESS);
        cout << endl;
    }

    //Exit stage right or left!
    return 0;
}

bool inEmp(Emp &e){
    float in;
    cout << "Enter the employee's information: \n";
    cout << "Name: ";
    getline(cin, e.name);
    cout << "Hours: ";
    cin >> in;
    if (in < 0) return false;
    e.hours = in;
    cout << "Pay rate: ";
    cin >> in;
    if (in < 0) return false;
    e.rate = in;
    return true;
}
void outEmp(const Emp e, const string company, const string address){
    cout << setprecision(2) << fixed;
    cout << company << '\n';
    cout << address << '\n';
    cout << "Name: " << e.name << '\t';
    cout << "Amount: $" << e.payNum << endl;
    cout << "Amount: " << e.payStr << endl;
    cout << "Signature Line: \n";
}

float calcPay(const float &hours, const float &rate){
    float pay = 0;
    if (hours <= DUB_HRS){ //Calculate normal hours
        return hours * rate;
    } else if (hours > DUB_HRS && hours < DUB_HRS){ //Calculate with double hours
        return (DUB_HRS * rate) + (2 * (hours - DUB_HRS) * rate);
    } else if (hours > TRIP_HRS){ //Calculate with double and triple hours
        return (DUB_HRS * rate) + (2 * (TRIP_HRS - DUB_HRS) * rate) + (3 * (hours - TRIP_HRS) * rate);
    }
    return pay;
}
//Groups digits in array of triplets to emulate comma notation to name each triplet:
//8,340,587,201 to [0,0,8][3,4,0][5,8,7][2,0,1]
//                   Bil    Mil    Thou   
string toEng(const float &n){
    string s = ""; //Amount string
    char* num; //Array of place values
    char** triplet; //Place values grouped into digits
    int whole = n, //Whole integer of amount
        dec = (n - whole) * 100, //Decimal value of amount
        digits = 0, //Number of digits in the amount
        decDigi = 0, //Number of decimal digits in the amount
        size; //Size of triplet array
    
    //Find number of digits
    for (int i = whole; i > 0; i /= 10){
        digits++;
    }
    if (dec != 0) decDigi = 2; //Adjust digits for cents
    size = ceil(digits / TRI); //Find the number of triplets
    //Put number into array of each place value
    num = new char[digits]; //Allocate place value array
    for (int i = 0, place = 1; i < digits; i++){
        num[i] = whole / place % 10; //Set to the place value
        place *= 10;
    }
    //Place numbers into triplets
    triplet = new2D(size, TRI);
    for (int i = size - 1, j = 0; i >= 0; i--){
        for (int k = TRI - 1; k >= 0 && j < digits; k--){
            triplet[i][k] = num[j];
            j++;
        }
    }
    //Convert dollars
    s += convert(triplet, size);
    s +=  "Dollars";
    
    //Convert cents
    //Put decimal into place value array
    num = new char[2];
    num[1] = dec % 10;
    num[0] = dec / 10 % 10;
    //Add cents to string
    s += " and ";
    for (int i = 0; i < 2; i++){
        (num[i] != 0) ? s += num[i]+CHARNUM : s += '0';
    }
    s += "/100";
    
    //De-allocate pointer arrays
    delete [] num;
    for (int i = 0; i < size; i++){
        delete [] triplet[i];
    }
    delete [] triplet;
    
    return s;
}

string convert(char** triplet, const char &size){
    string s;
    for (int i = 0, t = size - 1; i < size; i++){
            if (triplet[i][0] != 0) s += toEng(triplet[i][0]) + " Hundred ";
            if (triplet[i][1] == '1'){ //Output teens
                s += teenEng(triplet[i][2]) + ' ';
            } else {
                if (triplet[i][1] != 0) s += tenToEng(triplet[i][1]) + ' ';
                if (triplet[i][2] != 0) s += toEng(triplet[i][2]) + ' ';
            }
        if (i != size - 1) s +=  placeS(t) + ' ';
        t--;
    }
    return s;
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

char** new2D(const char s1, const char s2){
    char** a = new char*[s1];
    for (int i = 0; i < s1; i++){
        a[i] = new char[s2];
    }
    //Initialize array
    for (int i = 0; i < s1; i++){
        for (int j = 0; j < s2; j++){
            a[i][j] = 0;
        }
    }
    return a;
}