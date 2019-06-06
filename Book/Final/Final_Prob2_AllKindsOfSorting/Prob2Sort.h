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
    return a;
}
template <class T>
T * Prob2Sort<T>::sortArray(const T* array,int rows,int cols,int sortColumn,bool ascending){
    T* column = new T[rows];
    T* a = new T[rows*cols];
    //Copy array
    for (int i = 0; i < rows*cols; i++) a[i] = array[i];
    //Sort column array
    for(int i = 0; i < rows; i++){
        column[i] = array[i*cols+sortColumn-1];
    }
    cout << "\nColumn: ";
    for (int i = 0; i < cols; i++)
        cout << column[i];
    cout << endl;
    cout << "Column sort: " << sortColumn << endl;
    cout << "Columns: " << cols << endl;
    for(int i = 0; i < rows; i++){
        cout << i*cols+sortColumn-1 << ' ';
    }cout << endl;
    for(int i = 0; i < rows; i++){
        cout << i << ' ';
    }cout << endl;
    for(int i = 0; i < rows; i++){
        cout << i << '*' << cols << '+' << sortColumn << "-1 ";
    }cout << endl;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++)
            cout << i*cols+j << ' ';
        cout << endl;
    }
    
    return a;
}
#endif /* PROB2SORT_H */

