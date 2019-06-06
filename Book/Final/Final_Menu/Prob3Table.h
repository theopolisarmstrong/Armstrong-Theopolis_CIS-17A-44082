/* 
 * File:   Prob3Table.h
 * Author: Theopolis Armstrong
 * Created on June 5th, 2019, 12:03 PM
 * Purpose: Problem 3 Class definition
 */

#ifndef PROB3TABLE_H
#define PROB3TABLE_H
#include <fstream>
template<class T>
class Prob3Table
{
protected:
    int rows;                                 //Number of rows in the table
    int cols;                                 //Number of cols in the table
    T *rowSum;                                //RowSum array
    T *colSum;                                //ColSum array
    T *table;                                 //Table array
    T grandTotal;                             //Grand total
    void calcTable(void);                     //Calculate all the sums
public:
    Prob3Table(char *,int,int);               //Constructor then Destructor
    ~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
    const T *getTable(void){return table;};
    const T *getRowSum(void){return rowSum;};
    const T *getColSum(void){return colSum;};
    T getGrandTotal(void){return grandTotal;};
};

template <class T>
Prob3Table<T>::Prob3Table(char *file,int r, int c) : rows(r), cols(c), grandTotal(0) {
    rowSum = new T[rows];
    for (int i = 0; i < rows; i++)
        rowSum[i] = 0;
    colSum = new T[cols];
    for (int i = 0; i < cols; i++)
        colSum[i] = 0;
    fstream infile(file, fstream::in);
    T* read = new T[rows*cols];
    table = read;
    while(infile >> *read){ read++; }
    calcTable();
}

template <class T>
void Prob3Table<T>::calcTable(void){
    //Sum rows
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++)
            rowSum[i] += table[i*cols+j];
    }
    //Sum Columns
    for (int j = 0; j < cols; j++){
        for (int i = 0; i < rows; i++)
            colSum[j] += table[i*cols+j];
    }
    //Calculate grand total
//    for (int i = 0; i < rows; i++)
//        grandTotal += rowSum[i];
    for (int i = 0; i < cols; i++)
        grandTotal += colSum[i];
}
#endif /* PROB3TABLE_H */

