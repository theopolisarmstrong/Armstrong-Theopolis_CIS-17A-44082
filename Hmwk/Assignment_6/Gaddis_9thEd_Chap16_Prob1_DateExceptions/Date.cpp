/* 
 * File:   Date.cpp
 * Author: Theopolis Armstrong
 * Created on April 29th, 2019, 9:28 PM
 * Purpose: Date class definition
 */
#include "Date.h"

void Date::setMonth(int m){
    if (m >= MONTH_MIN && m <= MONTH_MAX)
        month = m;
    else throw InvalidMonth(m);
}

void Date::setDay(int d){
    if (d >= DAY_MIN && d <= DAY_MAX)
        day = d;
    else throw InvalidDay(d);
}

string Date::monStr(int month) const {
    switch(month){
        case 1:
            return "January";
            break;
        case 2:
            return "February";
            break;
        case 3:
            return "March";
            break;
        case 4:
            return "April";
            break;
        case 5:
            return "May";
            break;
        case 6:
            return "June";
            break;
        case 7:
            return "July";
            break;
        case 8:
            return "August";
            break;
        case 9:
            return "September";
            break;
        case 10:
            return "October";
            break;
        case 11:
            return "November";
            break;
        case 12:
            return "December";
            break;
        default:
            return "";
            break;
    }
}
