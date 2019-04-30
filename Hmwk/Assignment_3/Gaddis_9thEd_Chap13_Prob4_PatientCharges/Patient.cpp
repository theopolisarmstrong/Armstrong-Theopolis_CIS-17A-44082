/* 
 * File: Patient.cpp
 * Author: Theopolis Armstrong
 * Created on April 30th, 2019, 4:37 PM
 * Purpose: Paitent class definition
 */

#include "Patient.h"

Patient::Patient(Name* n, Addr* a, Contact* c, string num){
    name = n;
    address = a;
    emergency = c;
    number = num;
}
