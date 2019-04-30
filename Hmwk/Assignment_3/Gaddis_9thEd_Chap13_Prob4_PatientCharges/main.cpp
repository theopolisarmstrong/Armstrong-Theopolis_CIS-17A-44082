/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 29th, 2019, 10:03 PM
 * Purpose: Calculate procedure charges for a patient
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstring> //C-string Functions
using namespace std;

//User Libraries
#include "Patient.h";
#include "Procedure.h";

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void outName(const Name&);
void outAddr(const Addr&);
void outCont(const Contact&);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    Name *name = new Name;
    Addr *address = new Addr;
    Contact *emergency = new Contact;
    
    //Initialize or input i.e. set variable values
    name->first = "Rudy";
    name->middle = "Marion";
    name->last = "Huxtable";
    address->address = "42 Galaxy Drive";
    address->city = "Palmdale";
    strcpy(address->state, "CA");
    address->zip = "94676-2349";
    emergency->name.first = "Theodore";
    emergency->name.middle = "Marion";
    emergency->name.last = "Huxtable";
    emergency->number = "714-234-1894";
    
    Patient patient(name, address, emergency, "714-234-6983");
    
    //Map inputs -> outputs
    name = patient.getName();
    address = patient.getAddr();
    emergency = patient.getContact();
    
    //Display the outputs
    cout << "Name: " << name->first << ' ' << name->middle << name->last << endl;
//    cout << "Address: " << address->address << endl << address->city << ' ' << address->state << ' ' << address->zip << endl;
//    cout << "Number: " << patient.getNum();
//    cout << "Emergency Contact: \n\t" << emergency->name.first << ' ' << emergency->name.middle << ' ' << emergency->name.last << endl << '\t' << emergency->number << endl;

    //Exit stage right or left!
    delete name;
    delete address;
    delete emergency;
    return 0;
}