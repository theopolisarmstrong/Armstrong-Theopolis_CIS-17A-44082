/*
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 30th, 2019, 5:37 PM
 * Purpose: Use circle class and calculation member functions
 */

#ifndef Circle_h
#define Circle_h

#include <iostream>
using namespace std;

class Circle{
private:
    float radius = 0.0;
    float pi = 3.14159;
public:
    Circle(){ radius = 0.0; }
    Circle(float r){ radius = r; }
    void setRadius(float r){ radius = r; }
    float getRadius() const { return radius; }
    float getArea() const { return pi * radius * radius; }
    float getDiameter() const { return radius * 2; }
    float getCircumference() const { return 2 * pi * radius; }
};

#endif /* Circle_h= */
