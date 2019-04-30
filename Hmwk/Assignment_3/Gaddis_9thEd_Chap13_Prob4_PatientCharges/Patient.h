/* 
 * File: Patient.h
 * Author: Theopolis Armstrong
 * Created on April 29th, 2019, 10:08 PM
 * Purpose: Patient class declaration
 */

#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
using namespace std;

struct Name{
    string first = "";
    string middle = "";
    string last = "";
};
struct Addr{
    string address = "";
    string city = "";
    char state[2] = "";
    string zip = 0;
};
struct Contact{
    Name name;
    string number = "";
};

class Patient{
private:
    Name* name;
    Addr* address; //Patient's address
    Contact* emergency; //Emergency contact information
    string number = ""; //Patient's contact number
public:
    Patient(Name*, Addr*, Contact*, string);
    Name* getName(){ return name; }
    Addr* getAddr(){ return address; }
    Contact* getContact(){ return emergency; }
    string getNum(){ return number; }
};

#endif /* PATIENT_H */

