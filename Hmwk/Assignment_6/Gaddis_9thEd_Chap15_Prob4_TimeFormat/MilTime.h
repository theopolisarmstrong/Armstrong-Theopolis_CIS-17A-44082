/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on May 16th, 2019, 8:55 AM
 * Purpose: MilTime class declaration
 */

#ifndef MILTIME_H
#define MILTIME_H
#include <iostream>
#include "Time.h"
using namespace std;

class MilTime : public Time {
protected:
    int milHours = 0;
    int milSeconds = 0;
    void convert(int, int);
    bool valid(int, int);
public:
    MilTime(int, int);
    void setTime(int, int);
    int getHour() const { return milHours; }
    int getStandHr() const { return hour; }
};

#endif /* MILTIME_H */

