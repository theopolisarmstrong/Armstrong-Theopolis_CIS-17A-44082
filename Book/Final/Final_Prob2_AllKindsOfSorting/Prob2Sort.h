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
    for(int i = 0; i < size; i++){
        cout << a[i] << ' ';
    } cout << endl;
    return a;
}
template <class T>
T * Prob2Sort<T>::sortArray(const T* array,int rows,int cols,int sortColumn,bool ascending){
    sortColumn--;
    T* column = new T[rows];
    T* a = new T[rows*cols];
    //Copy array
    T* row = new T[rows];
    //Sort
    int minIndex;
    T swap, min;
    for (int i = sortColumn; i < rows - 1; i++){
        minIndex = i;
        min = a[i];
        for (int j = i*cols+sortColumn+i; j < rows; j++){
            if (a[j] < min){
                min = a[j];
                minIndex = j;
            }
        }
        //Swap rows
        swap = a[i];
        a[i] = a[minIndex];
        a[minIndex] = swap;
    }
    for(int i = 0; i < rows; i++){
        cout << a[i] << ' ';
    } cout << endl;
//    for (int i = 0; i < rows*cols; i++) a[i] = array[i];
    //Sort column array
//    for(int i = 0; i < rows; i++){
//        column[i] = array[i*cols+sortColumn-1+i];
//    }
//    T* sortedColumn = sortArray(column, cols, ascending);
//    for(int i = 0; i < rows; i++){
//        cout << sortedColumn[i] << ' ';
//    } cout << endl;
//    cout << "\nColumn: ";
//    for (int i = 0; i < cols; i++)
//        cout << column[i];
//    cout << endl;
    
    return a;
}
#endif /* PROB2SORT_H */

