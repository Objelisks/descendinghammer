#ifndef _bullet_inc
#define _bullet_inc
#include "coordinate.h"

class Bullet {
public:
	Bullet();
	Bullet(Coordinate co, int dmg, int t, double dir, int speed);
	Coordinate pos;
	int damage;
	int trail;
	int speed;
	double direction;
	double xMove;
	double yMove;
	bool dead;
	void update();
};

#endif