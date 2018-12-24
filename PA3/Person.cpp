#include "Person.h"

//Constructor
Person::Person(int position) {
    this->position = position;
}

//Destructor
Person::~Person() {}

//Prints current position of person
void Person::print() {
    cout << this->position << endl;
}

//Returns the current position of person
int Person::getPosition() {
    return this->position;
}