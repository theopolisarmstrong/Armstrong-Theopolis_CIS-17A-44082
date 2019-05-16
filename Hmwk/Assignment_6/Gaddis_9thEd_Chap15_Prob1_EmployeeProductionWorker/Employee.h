/* 
 * File:   Employee.h
 * Author: Theopolis Armstrong
 * Created on May 16th, 2019, 6:59 AM
 * Purpose: Employee class declaration
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include "Date.h"
using namespace std;

class Employee{
protected:
    string name = "";
    int number = 0;
    Date hireDate;
public:
    Employee();
    Employee(string n, int num, int m, int d, int y) : name(n), number(num), hireDate(m, d, y) {}
    void setName(string n) { name = n; }
    void setNumber(int n) { number = n; }
    void setHireDate(int m, int d, int y) { hireDate.set(m, d, y); }
    string getName() const { return name; }
    int getNumber() const { return number; }
    void outDate() const { hireDate.expand(); }
};

#endif /* EMPLOYEE_H */

