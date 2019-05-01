/*
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 30th, 2019, 7:11 PM
 * Purpose: Calculate birth and death rates
 */

#include "Population.h"

Population::Population(int pop, int bir, int dea){
    population = pop;
    births = bir;
    deaths = dea;
}

void Population::setPop(int pop){
    if(pop >= 1) population = pop;
    else cout << "Population mutator error\n";
}

void Population::setBir(int bir){
    if(bir >= 0) births = bir;
    else cout << "Births mutator error\n";
}

void Population::setDea(int dea){
    if(dea >= 0) deaths = dea;
    else cout << "Deaths mutator error\n";
}
