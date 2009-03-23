#ifndef _player_inc
#define _player_inc

#include "coordinate.h"

class Player{
public:
	Player();
	Coordinate pos;
	void moveForward(int amt);
	void moveBackward(int amt);
	void moveLeft(int amt);
	void moveUp(int amt);
	void moveRight(int amt);
	void moveDown(int amt);
	void fire();
	int cooldown;
};

#endif