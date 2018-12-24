#include "Player.h"

#include <iostream>
#include <map>
#include <iterator>

using namespace std;

class Board {
	public: 
		// Constructor:
		Board(int m);

		// Destructor
		~Board();

		bool Insert(int id, int x, int y); // Insert Player with ID at (x, y)
		bool Remove(int id); // Remove Player with given ID
		bool Find(int id); // Find if user with given ID exists on board
		bool MoveTo(int id, int x, int y); // Move Player with ID to (x, y)
		void PrintByID(); // Print all Players and their coordinates
	private: 
		int m;
		int n = 0;
		map<int, Player> boardData;
		int FindAtCoord(int x, int y); // Private function for seeing if Player exists at (x, y) and returning their ID
};
