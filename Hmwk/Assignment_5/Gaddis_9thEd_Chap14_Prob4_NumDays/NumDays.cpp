/* 
 * File:   NumDays.cpp
 * Author: Theopolis Armstrong
 * Created on May 14th, 2019, 9:11 AM
 * Purpose: NumDays class definition
 */

#include "NumDays.h"

const float NumDays::DAYHOURS = 8;

void NumDays::convert(){
    days = hours / DAYHOURS;
}

//Overloaded operator functions
NumDays NumDays::operator+(const NumDays &right){
    NumDays temp(hours + right.hours);
    return temp;
}
NumDays NumDays::operator-(const NumDays &right){
    NumDays temp(hours - right.hours);
    return temp;
}
NumDays NumDays::operator++(){
    hours++;
    convert();
    return *this;
}
NumDays NumDays::operator++(int){
    NumDays temp(hours);
    hours++;
    convert();
    return temp;
}
NumDays NumDays::operator--(){
    hours--;
    convert();
    return *this;
}
NumDays NumDays::operator--(int){
    NumDays temp(hours);
    hours--;
    convert();
    return temp;
}