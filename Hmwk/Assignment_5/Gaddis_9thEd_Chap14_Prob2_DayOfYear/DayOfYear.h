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
    unsigned int day; //Day of the year
    static const string months[]; //Months in the year
    static const int monthDays[]; //Days in each month; parallel to months[]
public:
    DayOfYear(unsigned int d) : day(d) {};
    void print(); //Outputs date in month-day format
};

#endif /* DAYOFYEAR_H */

