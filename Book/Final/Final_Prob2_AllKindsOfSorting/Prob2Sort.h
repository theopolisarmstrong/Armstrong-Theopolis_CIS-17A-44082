/* 
 * File: Prob2Sort.h
 * Author: Theopolis Armstrong
 * Created on June 5th, 2019, 7:25 PM
 * Purpose: Prob2Sort template class
 */

#ifndef PROB2SORT_H
#define PROB2SORT_H
#include <cstring>
template<class T>
class Prob2Sort
{
private:
    int *index;                                 //Index that is utilized in the sort
public:
    Prob2Sort(){index=nullptr;};                   //Constructor
    ~Prob2Sort(){delete []index;};              //Destructor
    T * sortArray(const T*,int,bool);           //Sorts a single column array
    T * sortArray(const T*,int,int,int,bool);   //Sorts a 2 dimensional array represented as a 1 dim array
};
template <class T>
T * Prob2Sort<T>::sortArray(const T* array,int size,bool ascending){
    //Copy array
    T* a = new T[size];
    for (int i = 0; i < size; i++)
        a[i] = array[i];
    
    int minIndex;
    T swap, min;
    for (int i = 0; i < size - 1; i++){
        minIndex = i;
        min = a[i];
        for (int j = i + 1; j < size; j++){
            if (a[j] < min){
                min = a[j];
                minIndex = j;
            }
        }
        swap = a[i];
        a[i] = a[minIndex];
        a[minIndex] = swap;
    }
//    for (int i = 0; i < size-1 ; i++){
        
//        for (int j = i+1; j < size; j++){
//            
//        }
//    }
    return a;
}
template <class T>
T * Prob2Sort<T>::sortArray(const T* array,int rows,int cols,int column,bool ascending){
    //Copy array
    T* a = new T[rows*cols];
    for (int i = 0; i < rows*cols; i++) a[i] = array[i];
    //Sort by first row
    for (int i = 1; i < rows; i++){
        int comparison = strcmp(a+(i*rows)-1, a+(i*rows));
        cout << "Comparison: " << comparison << endl;
        T* swap;
        if (comparison < 0){
            *swap = a[i*rows-1];
            a[i*rows-1] = a[i*rows];
            a[i*rows] = a[i*rows-1];
        }
        cout << a[i*rows];
    }
    
    return a;
}
#endif /* PROB2SORT_H */

