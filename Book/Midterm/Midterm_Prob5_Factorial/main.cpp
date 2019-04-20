/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 11th, 2019, 12:36 PM
 * Purpose: Test factorials
 * 
 * Largest possible factorial for 1 byte: 6! = 208
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> //Input/Output Manipulation
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const unsigned char CHARNUM = 48;

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
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
    
    
    //Exit stage right or left!
    return 0;
}