/* 
 * File:   ProductionWorker.cpp
 * Author: Theopolis Armstrong
 * Created on May 16th, 2019, 8:25 AM
 * Purpose: ProductionWorker class definition
 */

#include "ProductionWorker.h"

string ProductionWorker::getShift() const{
    string out;
    if (shift == 1)
        out = "Day";
    else if (shift == 2)
        out = "Night";
    return out;
}

