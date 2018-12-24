/*
Benjamin Poile - 11565739
CS 223 - PA 2
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <forward_list>
#include <ctime>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::forward_list;
using std::iterator;
using std::vector;

typedef struct time {
    int output_data;
    double runtime;
} Time;

int maxSubSum1(const vector<int> &a);
int maxSubSum2(const vector<int> &a);
int maxSubSum3(const vector<int> &a);
int max3(int a, int b, int c);
int maxSumRec(const vector<int> &a, int left, int right);
int maxSubSum4(const vector<int> &a);

Time elapsedTime(const vector <int> list, int (*f)(const vector<int> &a));
void outputData(Time t, int l, string file_name, string function_name);