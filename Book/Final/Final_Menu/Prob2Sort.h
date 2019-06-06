/* 
 * File:   Prob2Sort.h
 * Author: Armstrong, Theopolis
 * Created on June 5th, 2019, 9:45 AM
 * Purpose: Menu for Spring 2019 Final problems
 */

#ifndef PROB2SORT_H
#define PROB2SORT_H

template<class T>
class Prob2Sort{
private:
    int *index;                                 //Index that is utilized in the sort
public:
    Prob2Sort(){index=nullptr;};                //Constructor
    ~Prob2Sort(){delete []index;};              //Destructor
    T * sortArray(const T*,int,bool);           //Sorts a single column array
    T * sortArray(const T*,int,int,int,bool);   //Sorts a 2 dimensional array represented as a 1 dim array
        
}; 

//template <class T>
//T * Prob2Sort::sortArray(const T *orig, int length, bool ascending){
//    //Copy array
//    int minIndex, min;
//    T swap;
//    for (int i = 0; i < length-1; i++){
//        minIndex = i;
//        min = a[i];
//        for (int j = i + 1; j < length; j++){
//            if (ascending){
//                if (a[j] > min){
//                    min = a[j];
//                    minIndex = j;
//                }
//            } else {
//                if (a[j] < min){
//                    min = a[j];
//                    minIndex = j;
//                }
//            }
//        }
//        swap = a[i];
//        a[i] = a[minIndex];
//        a[minIndex] = swap;
//    }
//}

template <class T>
T * Prob2Sort<T>::sortArray(const T* a, int length, int width, int column, bool ascending){
    cout << "Starting 2D sort\n";
    //Copy array
    T *sorted = new T[length*width];
    for (int i = 0; i < length; i++){
        for (int j = 0; j < width; j++)
            sorted[i*width+j] = a[i*width+j];
    }
//    for (int i = 0; i < width; i++){
//        int swap;
//        for (int i = size - 1; i > 0; i--){
//            for (int j = 0; j < i; j++){
//                if (a[j] > a[j + 1]){
//                    swap = a[j + 1];
//                    a[j + 1] = a[j];
//                    a[j] = swap;
//                }
//            }
//        }
//    }
    return sorted;
}

#endif /* PROB2SORT_H */