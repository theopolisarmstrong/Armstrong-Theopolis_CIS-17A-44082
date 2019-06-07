/* 
 * File: Prob2Sort.h
 * Author: Theopolis Armstrong
 * Created on June 5th, 2019, 7:25 PM
 * Purpose: Prob2Sort template class
 */

#ifndef PROB2SORT_H
#define PROB2SORT_H
#include <cstring>
class Prob2Sort
{
private:
    int *index;                                 //Index that is utilized in the sort
public:
    Prob2Sort(){index=nullptr;};                   //Constructor
    ~Prob2Sort(){delete []index;};              //Destructor
    T * sortArray(const T*,int);           //Sorts a single column array
    T * sortArray(const T*,int,int);   //Sorts a 2 dimensional array represented as a 1 dim array
};
T * Prob2Sort<T>::sortArray(const T* array,int rows,int cols){
    T* sorted = new T[rows];
    for (int i = 0; i < rows; i++)
        a[i] = new T[cols];
    //Copy array into 2D array
    
    //Sort
    for (int i = 0; i < rows; i++){
        int minIndex;
        T *swap, *min;
        for (int i = 0; i < rows - 1; i++){
            minIndex = i;
            min = a[i];
            for (int j = i + 1; j < rows; j++){
                if (a[j] < min){
                    min = a[j];
                    minIndex = j;
                }
            }
            //Swap row pointers
            swap = a[i];
            a[i] = a[minIndex];
            a[minIndex] = swap;
        }
    }
    //Reinsert new line characters
    for (int i = 0; i < rows; i++)
        a[i][cols-1] = '\n';
    //Copy into 1d array
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++)
            sorted[i*cols+j] = a[i][j];
    }
    //Deallocate 2d sorting array
    for(int i = 0; i < rows; i++)
        delete [] a[i];
    delete [] a;
    return sorted;
}
#endif /* PROB2SORT_H */

