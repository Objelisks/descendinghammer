#ifndef _player_inc
#define _player_inc
#include "ship.h"

class Player : public Ship {
public:
	Player();
	void moveLeft(int amt);
	void moveUp(int amt);
	void moveRight(int amt);
	void moveDown(int amt);
	void fire();
};

#endif