/*
Benjamin Poile - 11565739
CS 223 - PA 1
*/

#include "header.h"

int main(void) {
    Time l = elapsedTime(getFileName(), *readFileBuildList);

    Time minimum = elapsedTime(l.list, *findMinimum);
    Time maximum = elapsedTime(l.list, *findMaximum);
    Time median  = elapsedTime(l.list, *findMedian);

    printFinal(l, minimum, maximum, median);
    return 0;
}

string getFileName() {
    string filename;
    
    cout << "Input file name? ";
    
    getline(cin, filename);
    
    return filename.c_str();
}

forward_list<int> readFileBuildList(string filename) {
    int temp;
    forward_list<int> list;
    ifstream infile(filename);

    cout << "Reading file '" << filename << "' ..." << endl;

    while (infile >> temp) {
        list.push_front(temp);
        list.sort();
    }

    return list;
}

void printList(forward_list<int> list) {
    for (int& x: list) cout << ' ' << x;
}

int findMinimum(forward_list<int> list) {
    return list.front();
}

int findMaximum(forward_list<int> list) {
    int max = list.front();
    for (int& x : list)
        if (x > max)
            max = x;
    
    return max;
}

int findMedian(forward_list<int> list) {
    for (int i = 0; i < getLength(list) / 2; i++)
        list.pop_front();
    
    return list.front();
}

int getLength(forward_list<int> list) {
    int length = 0;
    for (int& x : list)
        length++;
    return length;
}

/*
Function measures elapsed time of function parameter run.
External code referenced on measuring elapsed time.
StackOverflow URL: https://stackoverflow.com/questions/2808398/easily-measure-elapsed-time
*/
Time elapsedTime(forward_list<int> list, int (*func)(forward_list<int>))
{
    Time t;
   
    clock_t begin = clock();

    t.output_data = func(list);
    
    clock_t end = clock();

    t.runtime = double(end - begin) / CLOCKS_PER_SEC;

    return t;
}

/*
Function measures elapsed time of function parameter run.
External code referenced on measuring elapsed time.
StackOverflow URL: https://stackoverflow.com/questions/2808398/easily-measure-elapsed-time
*/
Time elapsedTime(string filename, forward_list<int> (*func)(string)) {
    Time t;

    clock_t begin = clock();

    t.list = func(filename);

    clock_t end = clock();

    t.runtime = double(end - begin) / CLOCKS_PER_SEC;

    return t;
}

void printFinal(Time l, Time min, Time max, Time med) {
    cout << "Minimum Value:\t" << min.output_data << endl
         << "Maximum Value:\t" << max.output_data << endl
         << "Median Value: \t" << med.output_data << endl
         << "Insert Time: \t" << l.runtime << endl
         << "Minimum Time:\t"  << min.runtime << endl
         << "Maximum Time:\t"  << max.runtime << endl
         << "Median Time: \t"  << med.runtime << endl;
}