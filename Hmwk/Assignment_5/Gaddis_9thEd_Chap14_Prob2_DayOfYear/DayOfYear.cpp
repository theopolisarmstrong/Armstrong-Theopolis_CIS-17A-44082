/* 
 * File:   DayOfYear.cpp
 * Author: Theopolis Armstrong
 * Created on May 13th, 2019, 8:19 PM
 * Purpose: DayOfYear class definition
 */

#include "DayOfYear.h"

const string DayOfYear::months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
const int DayOfYear::monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

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

