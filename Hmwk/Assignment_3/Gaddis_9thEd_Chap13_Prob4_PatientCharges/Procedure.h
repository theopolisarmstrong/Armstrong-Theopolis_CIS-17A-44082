/* 
 * File: Procedure.h
 * Author: Theopolis Armstrong
 * Created on April 29th, 2019, 10:08 PM
 * Purpose: Procedure class declaration
 */

#ifndef PROCEDURE_H
#define PROCEDURE_H
#include <iostream>
#include "Date.h"

using namespace std;

class Procedure{
private:
    string name = "";
    Date *date;
    string doctor = "";
    float charge = 0.0;
public:
    Procedure(string, Date*, string, float);
    string getName() const { return name; }
    Date* getDate() const { return date; }
    string getDoctor() const { return doctor; }
    float getCharge() const { return charge; }
    void setName(string n){ name = n; }
    void setDate(Date *d){ date = d; }
    void setDoctor(string d){ doctor = d; }
    void setCharge(float c){ charge = c; }
};

#endif /* PROCEDURE_H */

