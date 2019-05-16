/* 
 * File:   ProductionWorker.h
 * Author: Theopolis Armstrong
 * Created on May 16th, 2019, 7:38 AM
 * Purpose: ProductionWorker class declaration
 */

#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H
#include "Employee.h"

class ProductionWorker : public Employee{
protected:
    int shift = 1;
    float payRate = 0.0;
public:
    ProductionWorker(string name, int num, int m, int d, int y, int s, float pr) : shift(s), payRate(pr), Employee(name, num, m, d, y)  {}
    void setShift(int s) { shift = s; }
    void setPayRate(float pr) { payRate = pr; }
    float getPayRate() const { return payRate; }
    string getShift() const;
};

#endif /* PRODUCTIONWORKER_H */

