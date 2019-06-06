/* 
 * File:   Prob1Random.cpp
 * Author: Armstrong, Theopolis
 * Created on June 5th, 2019, 9:07 AM
 * Purpose: 
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "Prob1Random.h"

Prob1Random::Prob1Random(const char n,const char *rndseq) : nset(n), numRand(0){
    //Allocate sequence set
    set = new char[n];
    for (int i = 0; i < n; i++)
        set[i] = rndseq[i];
    //Allocate frequency set
    freq = new int[n];
    for (int i = 0; i < n; i++)
        freq[i] = 0;
    //Seed random number
    srand(time(0));
}
Prob1Random::~Prob1Random(void){
    delete [] set;
    delete [] freq;
}
char Prob1Random::randFromSet(void){
    char index = rand() % nset;
    freq[index]++;
    numRand++;
    return set[index];
}