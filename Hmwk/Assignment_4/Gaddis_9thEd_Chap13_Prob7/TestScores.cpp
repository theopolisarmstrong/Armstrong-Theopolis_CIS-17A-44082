/*
 * File:   TestScores.cpp
 * Author: Theopolis Armstrong
 * Created on May 5th, 2019, 5:32 PM
 * Purpose: TestScores class definintion
 * ---------------------------------------------------
 * |                  TestScores                     |
 * |-------------------------------------------------|
 * | - scores : int[3]                               |
 * |-------------------------------------------------|
 * | + TestScores() :                                |
 * | + setScore(score : int, index : char) : void    |
 * | + getScore() : int                              |
 * | + getAvg() : int                                |
 * ---------------------------------------------------
 */

#include "TestScores.h"

TestScores::TestScores(){
    for (char i = 0; i < 3; i++)
        scores[i] = 0;
}

int TestScores::getAvg(){
    int avg = 0;
    for (char i = 0; i < 3; i++)
        avg += scores[i];
    avg /= 3;
    return avg;
}
