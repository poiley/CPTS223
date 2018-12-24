#ifndef HEADER_H
#define HEADER_H

#include "QuadraticProbing.h"
#include "LinearProbing.h"
#include "SeparateChaining.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

typedef struct data {
    int f = 0;
    double f_time = 0;
} Data;

vector<string> readFile(ifstream infile);

Data insertIntoHT(vector<string> DataArray, Chaining::HashTable<string> HT);
Data insertIntoHT(vector<string> DataArray, Linear::HashTable<string> HT);
Data insertIntoHT(vector<string> DataArray, Quadratic::HashTable<string> HT);

Data searchHT(vector<string> QueryArray, Chaining::HashTable<string> HT);
Data searchHT(vector<string> QueryArray, Linear::HashTable<string> HT);
Data searchHT(vector<string> QueryArray, Quadratic::HashTable<string> HT);

void reportSearchData(Data d);
void reportInsertionData(Data d);

Data insertIntoHT_simple(vector<string> DataArray, Quadratic::HashTable<string> HT);
Data insertIntoHT_prefix(vector<string> DataArray, Quadratic::HashTable<string> HT);
Data insertIntoHT_full(vector<string> DataArray, Quadratic::HashTable<string> HT);

Data searchHT_simple(vector<string> QueryArray, Quadratic::HashTable<string> HT);
Data searchHT_prefix(vector<string> QueryArray, Quadratic::HashTable<string> HT);
Data searchHT_full(vector<string> QueryArray, Quadratic::HashTable<string> HT);

#endif