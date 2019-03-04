/* 
 * Author: Theopolis Armstrong
 * Created on January 28, 2019
 * Purpose: Calculate Gross Paycheck
 */

//System LibrariesGaddis
#include <iomanip> //Input/Output Steam Manipulation Library
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
float paycheck (float payRate, unsigned short hours, float mult = 1.0f);  //calculate paycheck using hours multiplier

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    const char HR_LVL_1 = 20;   //first level of pay
    const char HR_LVL_2 = 40;   //second level of pay
    
    float payRate;
    unsigned short hrsWrkd;
    float pay = 0.0f;  //calculated gross paycheck
    
    //Initialize or input i.e. set variable values
    cout<<"Paycheck Calculation."<<endl;
    cout<<"Input payRate in $'s/hour and hours worked"<<endl;
    cin>>payRate>>hrsWrkd;
    
    //Calculate Paycheck
    if (hrsWrkd <= 20)
        pay = paycheck(payRate, hrsWrkd);
    else if (hrsWrkd > 20 && hrsWrkd < 40){
        int extra = hrsWrkd - 20;
        pay = paycheck(payRate, 20);   //calculate first 20 hours
        pay += paycheck(payRate, extra, 1.5);    //calculate remaining hours
    } else if (hrsWrkd >= 40){
        char overtime = hrsWrkd - 40;
        pay = paycheck(payRate, 20);   //calculate first 20 hours
        pay += paycheck(payRate, 20, 1.5);   //calculate next 20 hours (1.5x)
        pay += paycheck(payRate, overtime, 2);   //calculate overtime hours (2x)
    } else
        cout << "Invalid number of hours worked.";
    
    //Output the check
    cout << setprecision(2) << fixed;
    cout << '$' << pay << endl;

    //Exit stage right or left!
    return 0;
}

float paycheck(float payRate, unsigned short hours, float mult){
    return (hours * mult) * payRate;
}