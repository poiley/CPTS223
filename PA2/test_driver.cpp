/*
Benjamin Poile - 11565739
CS 223 - PA 2
*/

#include "header.h"

int main(int argc, char *argv[]) {
    if(argc <= 1) {
        cout << "Failed! Please choose an input file!" << endl;
        return 0;
    }

    // load an arbitrary input array from a text file
    string filename = argv[1];
    ifstream myfile("./inputs/" + filename);
    vector<int> data;

    if (myfile.is_open()) {
        string line;
        while (getline(myfile, line))
            data.push_back(stoi(line));
        myfile.close();
    } else {
        cout << "Failed! Please choose another input file!";
        return 0;
    }

    filename = filename.substr(6, filename.length());
    int l = stoi(filename.substr(0, filename.find("_")));

    // run each algorithm on the input array
    Time t_1 = elapsedTime(data, &maxSubSum1);
    Time t_2 = elapsedTime(data, &maxSubSum2);
    Time t_3 = elapsedTime(data, &maxSubSum3);
    Time t_4 = elapsedTime(data, &maxSubSum4);

    // report their respective running times in millisecond
    outputData(t_1, l, filename, "maxSubSum1");
    outputData(t_2, l, filename, "maxSubSum2");
    outputData(t_3, l, filename, "maxSubSum3");
    outputData(t_4, l, filename, "maxSubSum4");

    return 0;
}

Time elapsedTime(const vector<int> list, int (*f)(const vector<int> &a)){
    Time t;

    clock_t begin = clock();

    t.output_data = f(list);

    t.runtime = double(clock() - begin) / CLOCKS_PER_SEC;

    return t;
}

void outputData(Time t, int l, string file_name, string function_name) {
    cout << "Results for " << file_name  << " - " << function_name << endl
         << "\t Output:\t" << t.output_data << endl
         << "\t Runtime:\t" << t.runtime << " seconds" << endl
         << "\t Entries:\t" << l << endl;
}