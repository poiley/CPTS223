#include "ListMyJosephus.h"

//Base constructor, forwards to the standard constructor with empty data
ListMyJosephus::ListMyJosephus() : ListMyJosephus(0, 0) { }

//Standard constructor, takes in two integers and sets them to N and
//M respectively.
ListMyJosephus::ListMyJosephus(int N, int M) {
    this->N = this->size = N;
    this->M = M % this->size;

    this->init(N, M);
}

//Destructor
ListMyJosephus::~ListMyJosephus() { this->circ.clear(); }

//Init function, initializes all data for game
void ListMyJosephus::init(int N, int M) {
    if(this->N == -1 or this->M == -1) {
        this->N = this->size = N;
        this->M = M % this->size;
    }
    
    for (int i = N; i > 0; i--) 
        this->circ.push_front(Person(i));
}

//Clear function, empties alist and wipes all size information
void ListMyJosephus::clear() {
    this->N = this->M = this->size = -1;
    this->circ.clear();
}

//Returns the current amount of players left
int ListMyJosephus::currentSize() {
    return this->size;
}

//Returns True if there are no players left
bool ListMyJosephus::isEmpty() {
    if(this->size == 0)
        return true;
    return false;
}

//Returns True if there is only one player left, meaning there is
//a winner.
bool ListMyJosephus::isWinner() {
    if(this->size == 1)
        return true;
    return false;
}

//Main game logic, removes the person at the current position + M
Person ListMyJosephus::eliminateNext() {
    if (this->isEmpty())
        return NULL;
        
    list<Person>::iterator itr = this->circ.begin();

    int numElim = (this->N - this->size) + 1; 
    
    advance(itr, ((( numElim * this->M ) - 1) - numElim) % this->N);

    this->circ.erase(itr);
    this->size--;
    return *itr;    
}

//Prints all curretnly playing players
void ListMyJosephus::printAll() {
    for (list<Person>::iterator itr = this->circ.begin(); itr != this->circ.end(); itr++)
        itr->print();
}

//Runs game until there is a winner
Person ListMyJosephus::runGame() {
    cout << "HELLL WORLD";
    while(this->size > 1) {
        int elim = this->eliminateNext().getPosition();
        cout << "Person " << elim << " was eliminated." << endl << "People Left: ";
        this->printAll();
    }

    return this->circ.front();
}