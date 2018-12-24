#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>
#include <list>
#include <ctime>

using namespace std;

typedef struct time {
    int output_data;
    double runtime;
} Time;

Time elapsedTime(Person (*func)());

#endif