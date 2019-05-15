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
    char monthIndex(string); //Returns index of month in month[] matching month name string
public:
    DayOfYear(unsigned int d) : day(d) {};
    DayOfYear(string, unsigned int); //Converts month-day format to day of year
    void print(); //Outputs date in month-day format
    unsigned int getDay() { return day; }
    
    //Overloaded operator functions
    DayOfYear operator++();
    DayOfYear operator++(int);
    DayOfYear operator--();
    DayOfYear operator--(int);
};

#endif /* DAYOFYEAR_H */

