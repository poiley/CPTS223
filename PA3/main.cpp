#include "header.h"
#include "ListMyJosephus.h"
#include "VectorMyJosephus.h"

int main(int argc, char* argv[]) {
    int N = stoi(argv[argc - 2]), M = stoi(argv[argc - 1]); //Configure players9
    clock_t s = clock(); //starts timer for overall function
    
    //Creates List/Vector objects
    ListMyJosephus lp = ListMyJosephus(N,M);
    VectorMyJosephus vp = VectorMyJosephus(N,M);

    //Runs and times the full running of the game logic
    Time l = elapsedTime(*lp.runGame);
    Time v = elapsedTime(*vp.runGame);

    //Reports data and quits.
    cout << "Person " << l.output_data << " has won the list game." << endl;
    cout << "Person " << v.output_data << " has won the vector game." << endl << endl;

    cout << "List runtime: " << l.runtime << endl;
    cout << "Vector runtime: " << v.runtime << endl;
    cout << "Overall runtime: " << double(clock() - s) / CLOCKS_PER_SEC << endl;
}

//Timing function. Takes functino in as a parameter and
//executes after establishing a start and finish time of the function
Time elapsedTime(Person (*func)()) {
    Time t;

    clock_t begin = clock();

    t.output_data = ((Person) func()).getPosition();
    t.runtime = double(clock() - begin) / CLOCKS_PER_SEC;

    return t;
}