/*
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 30th, 2019, 7:11 PM
 * Purpose: Calculate birth and death rates
 */

#ifndef Population_h
#define Population_h

#include <iostream>
using namespace std;

class Population{
private:
    int population;
    int births;
    int deaths;
public:
    Population() : population(0), births(0), deaths(0){}
    Population(int, int, int);
    void setPop(int);
    void setBir(int);
    void setDea(int);
    int getPop() const { return population; }
    int getBir() const { return births; }
    int getDea() const { return deaths; }
    
    float birRate() const { return static_cast<float>(births) / population; }
    float deaRate() const { return static_cast<float>(deaths) / population; }
};

#endif /* Population_h */
