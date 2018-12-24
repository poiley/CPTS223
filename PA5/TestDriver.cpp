#include "header.h"

int main() {
    int processors = 60;
    Scheduler s = Scheduler(processors);

    ifstream f("input.txt");
    string l;
    while (f.is_open() && getline (f, l)) {
        char *pch, *cstr = new char[l.length() + 1];

        strcpy(cstr, l.c_str());

        Job j;
        j.job_descr = strtok(cstr, " ");
        j.n_procs = stoi(strtok(NULL, " "));
        j.n_ticks = stoi(strtok(NULL, " "));

        s.InsertJob(j);
    }

   while(!s.isDone())
        s.DecrementTimer();

    f.close();
    return 0;
}