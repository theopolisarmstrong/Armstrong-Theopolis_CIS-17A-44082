/* 
 * File:   Prob1Random.h
 * Author: Armstrong, Theopolis
 * Created on June 5th, 2019, 9:07 AM
 * Purpose: 
 */

#ifndef RANDSEQ_H
#define RANDSEQ_H
#include <cstdlib>
#include <ctime>

template <class T>
class Prob1Random{
private:
    T *set;      //The set of numbers to draw random numbers from
    char  nset;     //The number of variables in the sequence
    int  *freq;     //Frequency of all the random numbers returned
    int   numRand;  //The total number of times the random number function is called
public:
    Prob1Random(const char,const char *);     //Constructor
    ~Prob1Random(void);                       //Destructor
    T randFromSet(void);                   //Returns a random number from the set
    int *getFreq(void) const { return freq; }                 //Returns the frequency histogram 
    char *getSet(void) const { return set; }                 //Returns the set used
    int getNumRand(void) const { return numRand; }               //Gets the number of times randFromSet has
                                              //been called
};
template <class T>
Prob1Random<T>::Prob1Random(const char n,const char *rndseq) : nset(n), numRand(0){
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
template <class T>
Prob1Random<T>::~Prob1Random(void){
    delete [] set;
    delete [] freq;
}
template <class T>
T Prob1Random<T>::randFromSet(void){
    char index = rand() % nset;
    freq[index]++;
    numRand++;
    return set[index];
}
#endif /* RANDSEQ_H */

