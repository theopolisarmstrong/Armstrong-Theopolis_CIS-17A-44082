/* 
 * File:   Employee.cpp
 * Author: Theopolis Armstrong
 * Created on June 5th, 2019, 5:45 PM
 * Purpose: Employee class definition
 */
#include <iostream>
#include <cstring>
using namespace std;
#include "Employee.h"

Employee::Employee(char name[],char job[],float rate) : HourlyRate(0.0), HoursWorked(0), GrossPay(0.0), NetPay(0.0) {
    setHourlyRate(rate);
    strlcpy(MyName,name,20);
    strlcpy(JobTitle,job,20);
}
float Employee::CalculatePay(float x,int y){
    return getNetPay(getGrossPay(setHourlyRate(x), setHoursWorked(y)));
}
float Employee::getGrossPay(float rate, int hours){
    int overtime = 0, doubleOvertime = 0;
    if (hours <= 40){
        GrossPay = hours * rate;
    } else if (hours > 40 && hours <= 50){
        overtime = hours - 40;
        hours = 40;
        GrossPay = hours * rate + (overtime * rate * 1.5);
    } else if (hours > 50){
        doubleOvertime = hours - 50;
        overtime = 10;
        hours = 40;
        GrossPay = hours * rate + (1.5 * overtime * rate) + (2 * doubleOvertime * rate);
    }
    return GrossPay;
}
float Employee::getNetPay(float pay){
    NetPay = pay - Tax(pay);
    return NetPay;
}
void Employee::toString(){
    cout << "Name = " << MyName;
    cout << " Job Title = " << JobTitle << endl;
    cout << " Hourly Rate = " << HourlyRate << " Hours Worked = " << HoursWorked << " Gross Pay = " << GrossPay << " Net Pay = " << NetPay << endl;
}
int    Employee::setHoursWorked(int hours){ if(hours > 0 && hours < 84){ HoursWorked = hours; return HoursWorked; } }
float  Employee::setHourlyRate(float rate){ if(rate > 0 && rate < 200){ HourlyRate = rate; return HourlyRate;} }

double Employee::Tax(float pay){
    float secTier = 0, thirdTier = 0;
    if (pay <= 500){
        return pay * 0.1;
    } else if (pay > 500 && pay <= 1000){
        secTier = pay - 500;
        pay = 500;
        return pay * 0.1 + (secTier * 0.2);
    } else if (pay > 1000){
        thirdTier = pay - 1000;
        secTier = 500;
        pay = 500;
        return pay * 0.1 + (secTier * 0.2) + (thirdTier * 0.3);
    }
}
