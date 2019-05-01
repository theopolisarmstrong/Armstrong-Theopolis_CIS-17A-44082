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
struct Addr{ //Address
    string address = "";
    string city = "";
    char state[2] = "";
    int zip = 0;
};
struct Contact{ //Contact information
    Name name;
    string number = "";
};

class Patient{
private:
    Name *name;
    Addr *address; //Patient's address
    Contact *emergency; //Emergency contact information
    string number = ""; //Patient's contact number
public:
    Patient(Name*, Addr*, Contact*, string);
    ~Patient();
    Name* getName() const { return name; }
    Addr* getAddr() const { return address; }
    Contact* getContact() const { return emergency; }
    string getNum() const { return number; }
    void setName(Name *n){ name = n; }
    void setAddr(Addr *a){ address = a; }
    void setContact(Contact *e){ emergency = e; }
    
};

#endif /* PATIENT_H */

