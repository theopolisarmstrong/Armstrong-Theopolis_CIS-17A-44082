/*
 * File:   PayRoll.h
 * Author: Theopolis Armstrong
 * Created on May 5th, 2019, 12:20 AM
 * Purpose: PayRoll class declaration
 */
#ifndef PayRoll_h
#define PayRoll_h

#include <iostream>
using namespace std;

class PayRoll{
private:
    float rate; //Hourly pay rate
    int hours; //Total weekly hours
public:
//    PayRoll() : rate(0.0), hours(0) {}
    PayRoll(float r = 0, int h = 0) {rate = r; hours = h;}
    void setRate(float r) {rate = r;}
    void setHours(float h) {hours = h;}
    float getRate() {return rate;}
    int getHours() {return hours;}
    float getPay() {return rate * hours;}
};

#endif /* PayRoll_h */
