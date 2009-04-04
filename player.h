#ifndef _player_inc
#define _player_inc

#include "coordinate.h"
#include "weapon.h"
#include "vector"
#include "boost/ptr_container/ptr_vector.hpp"

class Player{
public:
	Player();
	Coordinate pos;
	int currentWeapon;
	boost::ptr_vector<Weapon> weapons;
	void update();
	void moveForward();
	void moveBackward();
	void moveLeft();
	void moveUp();
	void moveRight();
	void moveDown();
	void toggleThrustVectors();
	void fire();
	void switchWeapon();
	double speed;
	int intSpeed;
	int direction;
	int inversethrustvectoringfuelcoiltoggled;
};

#endif