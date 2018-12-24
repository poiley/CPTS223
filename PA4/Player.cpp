#include "Player.h"

//Constructor
Player::Player(int id, int x, int y) { 
	this->x = x;
	this->y = y;
	this->ID = id; 
}

//Destructor
Player::~Player() {}

//Get the player id
int Player::getID() const { return this->ID; }

//Get the player x position
int Player::getX() const { return this->x; }

//Get the player y position
int Player::getY() const { return this->y; }

//Set the players new ID
void Player::setID(int newID) { this->ID = newID; }

//Set players position with both x and y available
void Player::setXY(int newX, int newY) {
	this->x = newX;
	this->y = newY;
}

