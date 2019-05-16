/* 
 * File:   MilTime.cpp
 * Author: Theopolis Armstrong
 * Created on May 16th, 2019, 9:01 AM
 * Purpose: MilTime class definition
 */

#include "MilTime.h"

MilTime::MilTime(int h, int s){
    if (valid(h, s)){
        milHours = h;
        milSeconds = s;
        convert(h, s);
    }
}

bool MilTime::valid(int h, int s){
    bool status = true;
    //Test hours
    if (h < 0 || h > 2359)
        cout << "Error: military hour out of range.\n";
        status = false;
    if (h % 100 < 0 || h % 100 > 59)
        cout << "Error: military minutes out of range.\n";
        status = false;
    if (s < 0 || s > 59)
        cout << "Error: military seconds out of range.\n";
        status = false;
    return status;
}

void MilTime::convert(int h, int s){
    (h / 100 > 12) ? hour = h / 100 - 12 : hour = h;
    min = h % 100;
    sec = s;
}

void MilTime::setTime(int h, int s){
    if (valid(h, s)){
        milHours = h;
        milSeconds = s;
        convert(h, s);
    }
}