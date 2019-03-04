/* 
 * Author: Theopolis Armstrong
 * Created on January 27, 2019
 * Purpose: Outputs histogram of given integer
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void hist(char digit);  //outputs asterisks for histogram 

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    const unsigned char CHARINT = 48; //subtract from char to convert char ASCII to integer numbers
    char n1, n10, n100, n1000; //ones, tens, hundreds, and thousands place value
    
    //Initialize or input i.e. set variable values
    cout << "Create a histogram chart.\n";
    cout << "Input 4 digits as characters.\n";
    cin >> n1 >> n10 >> n100 >> n1000;
    
    //convert char ASCII values to integer values
    n1 -= CHARINT;
    n10 -= CHARINT;
    n100 -= CHARINT;
    n1000 -= CHARINT;
    
    //Display the outputs
    hist(n1000);
    cout << endl;
    hist(n100);
    cout << endl;
    hist(n10);
    cout << endl;
    hist(n1);
    cout << endl;
    
    //Exit stage right or left!
    return 0;
}

void hist(char digit){
    if (digit < 0 || digit > 9){    //output '?' when digit is not a number 0-9
        const unsigned char CHARINT= 48; //subtract from char to convert char ASCII to integer numbers
        digit += CHARINT;   //convert digit back to char
        cout << digit << ' ';
        cout << '?';
    } else {
        cout << static_cast<unsigned short>(digit) << ' ';
        for (unsigned char i = 0; i < digit; i++)   //output asterisks
            cout << '*';
    }
}