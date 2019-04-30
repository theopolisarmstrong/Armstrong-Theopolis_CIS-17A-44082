/* 
 * File:   Date.h
 * Author: Theopolis Armstrong
 * Created on April 29th, 2019, 9:13 PM
 * Purpose: Date class declaration
 */

#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date{
private:
    const int DAY_MIN = 1;
    const int DAY_MAX = 31;
    const int MONTH_MIN = 1;
    const int MONTH_MAX = 12;
    int month = 0;
    int day = 0;
    int year = 0;
public:
    void setMonth(int);
    void setDay(int);
    void setYear(int y){ year = y; }
    int getMonth(){ return month; }
    int getDay(){ return day; }
    int getYear(){ return year; }
    string monStr(int); //Returns name of month
    void numeric(){ cout << month << '/' << day << '/' << year; } //Outputs 12/31/2019 format
    void expand(){ cout << monStr(month) << ' ' << day << ", " << year; } //Outputs December 31, 2019 format
    void mla(){ cout << day << ' ' << monStr(month) << ' ' << year; } //Outputs 31 December 2019 format
};

#endif /* DATE_H */

