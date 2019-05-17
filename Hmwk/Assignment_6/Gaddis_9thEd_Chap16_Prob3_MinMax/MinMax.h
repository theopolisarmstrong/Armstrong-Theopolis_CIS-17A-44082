/* 
 * File:   MinMax.h
 * Author: Theopolis Armstrong
 * Created on May 17th, 2019, 12:44 AM
 * Purpose: minimum & maximum function templates
 */

#ifndef MINMAX_H
#define MINMAX_H

template <class T>
T minimum(T t1, T t2){
    T val = t1;
    if (t2 < t1)
        val = t2;
    return val;
}

template <class T>
T maximum(T t1, T t2){
    T val = t1;
    if (t2 > t1)
        val = t2;
    return val;
}

#endif /* MINMAX_H */

