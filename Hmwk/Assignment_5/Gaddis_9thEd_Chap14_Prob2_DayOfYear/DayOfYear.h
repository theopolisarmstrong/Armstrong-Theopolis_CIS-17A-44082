/* 
 * File:   DayOfYear.h
 * Author: Theopolis Armstrong
 * Created on May 13th, 2019, 8:16 PM
 * Purpose: DayOfYear class declaration
 */

#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

#include <iostream>
using namespace std;

class DayOfYear{
private:
    unsigned int day;
    static const string months[];
public:
    DayOfYear(unsigned int d) : day(d) {};
    void print();
};

#endif /* DAYOFYEAR_H */

