/* 
 * File:   Numbers.h
 * Author: Theopolis Armstrong
 * Created on May 12th, 2019, 8:39 PM
 * Purpose: Numbers class declaration
 */

#ifndef NUMBERS_H
#define NUMBERS_H

#include <iostream>
using namespace std;

class Numbers{
private:
    int number;
    static const string lessThan20[];
    static const string greaterThan20[]; //Tens place output words
    static const string hundred;
    static const string thousand;
public:
    Numbers(unsigned int n) : number(n) {};
    void print();
};

#endif /* NUMBERS_H */

