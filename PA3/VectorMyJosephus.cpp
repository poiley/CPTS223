#include "VectorMyJosephus.h"

//Base constructor, forwards to the standard constructor with empty data
VectorMyJosephus::VectorMyJosephus() : VectorMyJosephus(0, 0) { }

//Standard constructor, takes in two integers and sets them to N and 
//M respectively. 
VectorMyJosephus::VectorMyJosephus(int N, int M) {
    this->N = this->size = N;
    this->M = M % this->size;

    this->init(N, M);
}

//Destructor
VectorMyJosephus::~VectorMyJosephus() { this->circ.clear(); }

//Init function, initializes all data for game 
void VectorMyJosephus::init(int N, int M) {
    if(this->N == -1 or this->M == -1) {
        this->N = this->size = N;
        this->M = M % this->size;
    }

    for (int i = N; i > 0; i--)
        this->circ.insert(this->circ.begin(), Person(i));
}

//Clear function, empties alist and wipes all size information
void VectorMyJosephus::clear() {
    this->N = this->M = this->size = -1;
    this->circ.clear();
}

//Returns the current amount of players left
int VectorMyJosephus::currentSize() {
    return this->size;
}

//Returns True if there are no players left
bool VectorMyJosephus::isEmpty() {
    if(this->size == 0)
        return true;
    return false;
}

//Returns True if there is only one player left, meaning there is 
//a winner.
bool VectorMyJosephus::isWinner() {
    if(this->size == 1)
        return true;
    return false;
}

//Main game logic, removes the person at the current position + M 
Person VectorMyJosephus::eliminateNext() {
    vector<Person>::iterator itr = this->circ.begin();

    int numElim = (this->N - this->size) + 1; 
    
    advance(itr, (((numElim * this->M) - 1) - numElim) % this->N);

    this->circ.erase(itr);
    this->size--;
    return *itr;    
}

//Prints all curretnly playing players
void VectorMyJosephus::printAll() {
    for (vector<Person>::iterator itr = this->circ.begin(); itr != this->circ.end(); itr++)
        itr->print();
}

//Runs game until there is a winner
Person VectorMyJosephus::runGame() {
    while(this->size > 1) {
        cout << "Person " << this->eliminateNext().getPosition() << " was eliminated." << endl << "People Left: ";
        this->printAll();
    }

    return this->circ.front();
}