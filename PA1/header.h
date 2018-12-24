/*
Benjamin Poile - 11565739
CS 223 - PA 1
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <forward_list>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::forward_list;
using std::iterator;

typedef struct time {
    int output_data;
    double runtime;
    forward_list<int> list;
} Time;

string getFileName();
forward_list<int> readFileBuildList(string filename);
void printList(forward_list<int> list);
int findMinimum(forward_list<int> list);
int findMaximum(forward_list<int> list);
int findMedian(forward_list<int> list);
int getLength(forward_list<int> list);

Time elapsedTime(forward_list<int> list, int (*f)(forward_list<int>));
Time elapsedTime(string filename, forward_list<int> (*func)(string));

void printFinal(Time l, Time min, Time max, Time med);