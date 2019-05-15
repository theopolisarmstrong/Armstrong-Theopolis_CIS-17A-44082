/* 
 * File:   DayOfYear.cpp
 * Author: Theopolis Armstrong
 * Created on May 13th, 2019, 8:19 PM
 * Purpose: DayOfYear class definition
 */

#include "DayOfYear.h"

const string DayOfYear::months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
const int DayOfYear::monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

DayOfYear::DayOfYear (string month, unsigned int mDay) : day(0){
    char mIndex = monthIndex(month); //Initialized as index of matching month name
    //Check for out of range day
    if (mDay < 0 || mDay > monthDays[mIndex]){
        cout << "Error: day out of range\n";
        exit(0);
    }
    //Add months' days and input day
    if (mIndex != -1){ //Check for month name match success
        //Add the sum of all previous months
        for (char i = 0; i < mIndex; i++){
            day += monthDays[i];
        }
        day += mDay; //Add the days of the current month
    } else { //Output error and exit if no month was found
        cout << "Error: unknown month\n";
        exit(0);
    }
}

char DayOfYear::monthIndex(string month){
    for (char i = 0; i < 12; i++){
        if (month == months[i])
            return i;
    }
    return -1;
}

void DayOfYear::print(){
    int month = 0, i = 0;
    
    if(day > 0 && day < 366){ //Static array bounds check / input validation
        //Find month
        for (; i < day; i+=monthDays[month-1]){
            month++;
        }
        month--;
        i-=monthDays[month];
        //Output date in month-day format
        cout << months[month] << ", " << day-i << endl;
    }
}

DayOfYear DayOfYear::operator++(){
    ++day;
    if (day > 365) day = 1;
    return *this;
}

DayOfYear DayOfYear::operator++(int){
    DayOfYear temp(day);
    ++day;
    if (day > 365) day = 1;
    return temp;
}
DayOfYear DayOfYear::operator--(){
    --day;
    if (day < 1) day = 365;
    return *this;
}

DayOfYear DayOfYear::operator--(int){
    DayOfYear temp(day);
    --day;
    if (day < 1) day = 365;
    return temp;
}