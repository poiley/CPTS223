#include "Board.h"

//Constructor
Board::Board(int m) { this->m = m; }

//Destructor
Board::~Board() {}

bool Board::Insert(int id, int x, int y) {
    // Make sure N would not equal M upon additional insertion
    if (this->n > this->m)
        return false;

    // Make sure player with same ID doesn't already exist, and that the list isn't too small 
    if (this->boardData.count(id) != 0)
        return false;
    
    // Make sure player with same position doesn't already exist
    if (this->FindAtCoord(x, y) != -1)
        return false;

    // Insert, adjust n, return true
    this->boardData.insert(pair<int, Player>(id, Player(id, x, y)));
    this->n++;
    return true;
}

bool Board::Remove(int id) {
    // Search for player in boardData with matching ID
    map<int, Player>::iterator i = this->boardData.begin();
    for (i; i != this->boardData.end(); i++) 
        if (i->first == id) 
            break;

    // If key ID is in boardData keys, remove and adjust n
    if (i != this->boardData.end()) {
        this->boardData.erase(i);
        this->n--;
        return true;
    }

    return false;
}

bool Board::Find(int id) {
    // Iterate through boardData for key ID in boardData keys. If key found, return true.
    for (map<int, Player>::iterator i = this->boardData.begin(); i != this->boardData.end(); i++)
        if (i->first == id)
            return true;

    return false;
}

int Board::FindAtCoord(int x, int y) {
    // Iterate through boardData for values X and Y in board values. If found, return user key ID.
    for (map<int, Player>::iterator i = this->boardData.begin(); i != this->boardData.end(); i++)
        if (x == i->second.getX() && y == i->second.getY())
            return i->first;

    // If there isn't a player at (X, Y), return -1
    return -1;
}

bool Board::MoveTo(int id, int x, int y) {
    // If user with ID isn't on board
    if(!this->Find(id))
        return false;
 
    // Iterate through boardData for player with right ID, check if movement is valid, then move
    for (map<int, Player>::iterator i = this->boardData.begin(); i != this->boardData.end(); i++) {
        // Check for correct player ID
        if (i->first != id)
            continue;
    
        // Check if movement is valid (same row, column or diagonal)
        if (i->second.getX() == x || i->second.getY() == y || (abs(y - i->second.getY()) == abs(x - i->second.getX()))) {
            int atCoord = this->FindAtCoord(x, y);
            if (atCoord != -1)
                this->Remove(atCoord);

            i->second.setXY(x, y);
            return true;
        }
    }

    return false;
}

void Board::PrintByID() {
    //Iterate through boardData and print each ID and Coord in <ID> (<X>, <Y>) format
    for (map<int, Player>::iterator i = this->boardData.begin(); i != this->boardData.end(); i++)
        cout << "ID: " << i->first << "\t(" << i->second.getX() << ", " << i->second.getY() << ")\n";
}