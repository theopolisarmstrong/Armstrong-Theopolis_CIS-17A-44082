/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 29th, 2019, 10:03 PM
 * Purpose: Calculate procedure charges for a patient
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> //Input/Output Stream Manipulation
#include <cstring> //C-string Functions
using namespace std;

//User Libraries
#include "Patient.h"
#include "Procedure.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void outProc(const Procedure&);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    const int MONTH = 4;
    const int DAY = 30;
    const int YEAR = 2019;
    
    Name *name = new Name;
    Addr *address = new Addr;
    Contact *emergency = new Contact;
    Date* today = new Date; //Current date
    float total = 0.0; //Total charge for all patient's proedures
    
    
    //Initialize or input i.e. set variable values
    //Initialize Patient structures
    name->first = "Rudy";
    name->middle = "Marion";
    name->last = "Huxtable";
    address->address = "42 Galaxy Drive";
    address->city = "Palmdale";
    strcpy(address->state, "CA");
    address->zip = 94676;
    emergency->name.first = "Theodore";
    emergency->name.middle = "Marion";
    emergency->name.last = "Huxtable";
    emergency->number = "714-234-1894";
    
    Patient patient(name, address, emergency, "714-234-6983"); //Initialize patient using dynamically allocated structures
    
    //Initialize date
    today->setMonth(MONTH);
    today->setDay(DAY);
    today->setYear(YEAR);
    
    //Initialize Procedures
    Procedure proc1("Physical Exam", today, "Dr. Irvine", 250.0);
    Procedure proc2("X-ray", today, "Dr. Jamison", 500.0);
    Procedure proc3("Blood test", today, "Dr. Smith", 200.0);
    
    //Map inputs -> outputs
    name = patient.getName();
    address = patient.getAddr();
    emergency = patient.getContact();
    
    total = proc1.getCharge() + proc2.getCharge() + proc3.getCharge();
    
    //Display the outputs
    cout << "Patient: \n\t" << name->first << ' ' << name->middle << ' ' << name->last << endl;
    cout << '\t' << address->address << endl << '\t' << address->city << ' ' << address->state << ' ' << address->zip << endl;
    cout << '\t' << patient.getNum() << endl;
    cout << "Patient's Emergency Contact: \n\t" << emergency->name.first << ' ' << emergency->name.middle << ' ' << emergency->name.last << endl << '\t' << emergency->number << endl << endl;
    outProc(proc1);
    outProc(proc2);
    outProc(proc3);
    cout << setprecision(2) << fixed;
    cout << "\nTotal: $" << total << endl;
    
    //Exit stage right or left!
    delete name;
    delete address;
    delete emergency;
    return 0;
}

void outProc(const Procedure &proc){
    const Date* date = proc.getDate();
    cout << "Procedure: \n\t" << proc.getName() << endl << '\t';
    date->expand();
    cout << "\n\tPerformed by " << proc.getDoctor() << endl;
    cout << setprecision(2) << fixed;
    cout << "\t$" << proc.getCharge() << endl;
}
