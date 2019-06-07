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
                if(ascending){
                    if (a[j] > min){
                        min = a[j];
                        minIndex = j;
                    }
                } else {
                    if (a[j] < min){
                        min = a[j];
                        minIndex = j;
                    }
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
    T* sorted = new T[rows*cols];
    T** a = new T*[rows];
    for (int i = 0; i < rows; i++)
        a[i] = new T[cols];
    //Copy array into 2D array
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols-1; j++){
            a[i][j] = array[i*cols+j+i];
        }
    }
    //Sort
    for (int i = 0; i < rows; i++){
        int minIndex;
        T *swap, *min;
        for (int i = 0; i < rows - 1; i++){
            minIndex = i;
            min = a[i];
            for (int j = i + 1; j < rows; j++){
                if(ascending){
                    if (a[j][sortColumn] > min[sortColumn]){
                        min = a[j];
                        minIndex = j;
                    }
                } else {
                    if (a[j][sortColumn] < min[sortColumn]){
                        min = a[j];
                        minIndex = j;
                    }
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

