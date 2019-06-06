/* 
 * File:   Prob3TableInherited.h
 * Author: Theopolis Armstrong
 * Created on June 5th, 2019, 12:07 PM
 * Purpose: Problem 3 Table Inherited class declaration
 */

#ifndef PROB3TABLEINHERITED_H
#define PROB3TABLEINHERITED_H
#include "Prob3Table.h"
template<class T>
class Prob3TableInherited:public Prob3Table<T>
{
protected:
    T *augTable;                                  //Augmented Table with sums
public:
    Prob3TableInherited(char *, int, int);          //Constructor
    ~Prob3TableInherited(){delete [] augTable;};  //Destructor
    const T *getAugTable(void){return augTable;}; 
};

template <class T>
Prob3TableInherited<T>::Prob3TableInherited(char *file, int r, int c) : Prob3Table<T>(file, r, c) {
    augTable = new T[(r+1)*(c+1)];
    for (int i = 0; i < r+1; i++){
        for (int j = 0; j < c+1; j++)
            augTable[i*c+j] = 0;
    }
    //Copy table
    for(int i = 0, j = 0, row = 1; i < (r+1)*(c+1); i++){
        if (i + 1 == (c + 1) * row) { //Insert sum at end of row
            augTable[i] = Prob3Table<T>::rowSum[row-1];
            row++;
        } else { //Copy table to preceding elements
            augTable[i] = Prob3Table<T>::table[j];
            j++;
        }
    }
    //Set last row
    for (int i = r * (c+1), col = 0; i < (r+1)*(c+1); i++){
        augTable[i] = Prob3Table<T>::colSum[col];
        col++;
    }
    //Set grand total
    augTable[((r+1)*(c+1)) - 1] = Prob3Table<T>::grandTotal;
}

#endif /* PROB3TABLEINHERITED_H */

