/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on May 14th, 2019, 9:10 AM
 * Purpose: NumDays class declaration
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H

#include <iostream>
using namespace std;

class NumDays{
private:
    static const float DAYHOURS; //Work hours in a day
    int hours; //Work hours
    float days; //Days worked
    void convert();
public:
    NumDays() : hours(0) {};
    NumDays(int h) : hours(h) { convert(); };
    void setHours(int h){ hours = h; }
    void setDays(int d){ days = d; }
    int getHours(){ return hours; }
    float getDays(){ return days; }
    
    //Overloaded operator functions
    NumDays operator+(const NumDays&);
    NumDays operator-(const NumDays&);
    NumDays operator++();
    NumDays operator++(int);
    NumDays operator--();
    NumDays operator--(int);
};

#endif /* NUMDAYS_H */

