/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 17th, 2019, 3:15 AM
 * Purpose: Menu project for Midterm problems
 */

//System Libraries
#include <iostream>
#include <iomanip> //Input/Output Manipluation
#include <math.h> //Math Functions (ceil)
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions
const unsigned char CHARNUM = 48;
const float TRI = 3;
const unsigned char DUB_HRS = 40;
const unsigned char TRIP_HRS = 50;

//Structures
//Problem 1 Structures
struct Checking{
    string name; //Account holder name
    string address; //Account holder address
    unsigned int number; //Account number (5 digits)
    float balance; //Account balance
    float totCheck; //Total monthly check withdrawals
    float totDep; //Total deposits
};
//Problem 2 Structures
struct Emp{
    string name;
    float hours;
    float rate; //Hourly rate
    float payNum; //Numeric amount
    string payStr; //English amount
};
//Problem 3 Structures

//Problem 4 Structures

//Problem 5 Structures

//Problem 6 Structures

//Problem 7 Structures
struct Prime{
    unsigned char prime;
    unsigned char power;
};
struct Primes{
    Prime *prime;
    unsigned char nPrimes;
};

//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();
void prblm7();

//Problem 1 functions
void valid(float &input, string error);
float inLoop(const float);
//Problem 2 functions
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
//Problem 3 Functions

//Problem 4 Functions
void convert(char[], const unsigned char, bool); //Convert C-string between characters and integers
bool valid(const char[], const unsigned char); //Validate C-string
void encrypt(char[], const unsigned char); //Encrypt number array
void decrypt(char[], const unsigned char); //Decrypt number array

//Problem 5 Functions

//Problem 6 Functions
void answers();

//Problem 7 Functions
Primes *factor(int); //Input an integer, return all prime factors
void prntPrm(Primes *); //Output all prime factors

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
            case '1':{cin.ignore();prblm1();break;}
            case '2':{cin.ignore();prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            case '7':{prblm7();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='7');
    
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
    cout<<"Type 3 for Structure Statistics program (Problem 3)"<<endl;
    cout<<"Type 4 for Encryption/Decryption program (Problem 4)"<<endl;
    cout<<"Type 5 for Factorial Overflow (Problem 5)"<<endl;
    cout<<"Type 6 for Float Representation (Problem 6)"<<endl;
    cout<<"Type 7 for Prime Factor (Problem 7)"<<endl<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 1
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm1(){
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
    cout << setw(16) << left << "Account number: " << setfill('0') << setw(5) << right << account->number << endl;
    cout << setprecision(2) << fixed;
    cout << setw(16) << left << "Total balance : $" << account->balance << endl;
    if(odBal) cout << "\nYou will be charged an overdraft fee of $" << ODF
                   << ".\nYour new estimated balance is $" << odBal << ".\n";
    delete account;
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

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 3
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm3(){
    cout<<"Problem 3 is included in a separate project"<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 4
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm4(){
    const unsigned char SIZE = 4;
    
    char in[4] = {0};
    short data = 0;
    short eData = 0;
    
    //Initialize or input i.e. set variable values
    cout << "Enter a decrypted 4-digit integer using digits : ";
    cin >> in;
    while(!valid(in, SIZE)){
        cout << "Error: integer out of range\nEnter a new integer: ";
        cin >> in;
    }
    
    //Map inputs -> outputs
    //Convert C-string to integers
    convert(in, SIZE, 1);
    encrypt(in, SIZE);
    convert(in, SIZE, 0);
    
    //Display the outputs
    cout << "Encrypted Number: " << in << endl;
    
    //Initialize or input i.e. set variable values
    cout << "Enter an encrypted 4-digit integer using digits : ";
    cin >> in;
    while(!valid(in, SIZE)){
        cout << "Error: integer out of range\nEnter a new integer: ";
        cin >> in;
    }
    
    //Map inputs -> outputs
    //Convert C-string to integers
    decrypt(in, SIZE);
    
    //Display the outputs
    cout << "Decrypted Number: " << in << endl;
}

bool valid(const char s[], const unsigned char size){
    for (char i = 0; i < size; i++){
        if (s[i] < '0' || s[i] > '7')
            return false;
    }
    return true;
}

void convert(char s[], const unsigned char size, bool mode){
    //mode true  = character -> integer
    //mode false = integer   -> character
    if (mode)
        for(char i = 0; i < size; i++)
            s[i] -= CHARNUM;
    else
        for(char i = 0; i < size; i++)
            s[i] += CHARNUM;
}

void encrypt(char s[], const unsigned char size){
    char swap;
    //Arithmetic encryption
    for (char i = 0; i < size; i++){
        s[i] = (s[i] + 5) % 8;
    }
    //Swap elements 1 & 3
    swap = s[0];
    s[0] = s[2];
    s[2] = swap;
    //Swap elements 2 & 4
    swap = s[1];
    s[1] = s[3];
    s[3] = swap;
}

void decrypt(char s[], const unsigned char size){
    char swap;
    //Swap elements 1 & 3
    swap = s[0];
    s[0] = s[2];
    s[2] = swap;
    //Swap elements 2 & 4
    swap = s[1];
    s[1] = s[3];
    s[3] = swap;
    //Arithmetic encryption
    for (char i = 0; i < size; i++){
        switch(s[i]){
            case '6':
                s[i] = '1';
                break;
            case '7':
                s[i] = '2';
                break;
            case '0':
                s[i] = '3';
                break;
            case '1':
                s[i] = '4';
                break;
            case '2':
                s[i] = '5';
                break;
            case '3':
                s[i] = '6';
                break;
            case '4':
                s[i] = '7';
                break;
        }
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 5
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm5(){
    //Set the random number seed
    
    //Declare Variables
    unsigned char byte;
    char c;
    short s;
    unsigned short us;
    int i;
    unsigned int ui;
    long l;
    unsigned long ul;
    float f;
    double d;
    long double ld;
    
    //Initialize or input i.e. set variable values
    byte = c = s = us = i = ui = l = ul = f = d = ld = 1;
    
    //Map inputs -> outputs
    //Test 1 byte variable
    cout << "\n1 byte factorial overflow: \n";
    int x = 1;
    for (x = 1; x < 8; x++){
        byte *= x;
        if (x  == 7 || x == 6) cout << '!' << x << " = " << static_cast<int>(byte) << endl;
    }
    //Test char
    cout << "\nchar factorial overflow: \n";
    for (x = 1; x < 7; x++){
        c *= x;
        if (x  == 6 || x == 5) cout << '!' << x << " = " << static_cast<int>(c) << endl;
    }
    //Test short
    cout << "\nshort factorial overflow: \n";
    for (x = 1; x < 9; x++){
        s *= x;
        if (x  == 8 || x == 7) cout << '!' << x << " = " << s << endl;
    }
    //Test unsigned short
    cout << "\nunsigned short factorial overflow: \n";
    for (x = 1; x < 10; x++){
        us *= x;
        if (x  == 9 || x == 8) cout << '!' << x << " = " << us << endl;
    }
    //Test int
    cout << "\nint factorial overflow: \n";
    for (x = 1; x < 18; x++){
        i *= x;
        if (x  == 17 || x == 16) cout << '!' << x << " = " << i << endl;
    }
    //Test unsigned int
    cout << "\nunsigned int factorial overflow: \n";
    for (x = 1; x < 19; x++){
        ui *= x;
        if (x  == 18 || x == 17) cout << '!' << x << " = " << ui << endl;
    }
    //Test long
    cout << "\nlong factorial overflow: \n";
    for (x = 1; x < 22; x++){
        l *= x;
        if (x  == 21 || x == 20) cout << '!' << x << " = " << l << endl;
    }
    //Test unsigned long
    cout << "\nunsigned long factorial overflow: \n";
    for (x = 1; x < 24; x++){
        ul *= x;
        if (x  == 23 || x == 22) cout << '!' << x << " = " << ul << endl;
    }
    //Test float
    cout << "\nfloat factorial precision: \n";
    for (x = 1; x < 36; x++){
        f *= x;
        cout << fixed;
        if (x  == 35 || x == 34) cout << '!' << x << " = " << f << endl;
    }
    //Test double
    cout << "\ndouble factorial precision: \n";
    for (x = 1; x < 40; x++){
        d *= x;
        cout << fixed;
        if (x > 35) cout << '!' << x << " = " << d << endl;
    }
    //Test long double
    cout << "\nlong double factorial precision: \n";
    for (x = 1; x < 40; x++){
        ld *= x;
        cout << fixed;
        if (x > 35) cout << '!' << x << " = " << ld << endl;
    }
    
    
    //Display the outputs
    cout << endl;
    cout << "1 byte max:         !6\n";
    cout << "char max:           !5\n";
    cout << "short max:          !7\n";
    cout << "unsigned short max: !8\n";
    cout << "int max:            !16\n";
    cout << "unsigned int max:   !17\n";
    cout << "long max:           !20\n";
    cout << "unsigned long max:  !22\n";
    cout << "float precision loss by !34\n";
    cout << "double precision loss by !36\n";
    cout << "long double precision loss by !36\n";
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 6
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm6(){
    //Set the random number seed
    
    //Declare Variables
    
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    
    //Display the outputs
    answers();

    //Exit stage right or left!
}

void answers(){
    cout << "Dec\t\tBinary\t\tOctal\t\tHex\t\tFloat Rep.\tNeg. Float Rep.\n"
         << "2.875\t\t10.111\t\t2.7\t\t2.E\t\t5E000002\tA1FFF002\n"
         << "0.1796875\t0.0010111\t0.134\t\t0.2E\t\t5E0000FE\tA1FFF0FE\n"
         << "\n59999901 = 1.4\n"
         << "59999902 = 2.8\n"
         << "A66667FE = -0.175\n";
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 7
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm7(){
    cout << "Incomplete.\n\n";
    //Set the random number seed
    
    //Declare Variables
    Primes *ans;
    int num;
    
    //Initialize or input i.e. set variable values
    cout << "Enter a number between 2 and 10,000: ";
    cin >> num;
    
    //Map inputs -> outputs
    ans = factor(num);
    
    //Display the outputs
    prntPrm(ans);

    //Exit stage right or left!
}

Primes *factor(int n){
    Primes *p = new Primes;
    return p;
}

void prntPrm(Primes *p){
    
}