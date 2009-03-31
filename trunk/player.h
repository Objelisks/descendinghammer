#ifndef _player_inc
#define _player_inc

#include "coordinate.h"

class Player{
public:
	Player();
	Coordinate pos;
	void update();
	void moveForward();
	void moveBackward();
	void moveLeft();
	void moveUp();
	void moveRight();
	void moveDown();
	void toggleThrustVectors();
	void fire();
	int cooldown;
	double speed;
	int intSpeed;
	int inversethrustvectoringfuelcoiltoggled;
};

#endif