//health
//position
//bullets
#ifndef _enemy_inc
#define _enemy_inc
#include "coordinate.h"

class Enemy {
public:
	Enemy();
	Enemy(void (*m)(Coordinate*, int));
	Coordinate pos;
	int health;
	int size;
	int life;
	bool dead;
	void (*move)(Coordinate *c, int t);
	void update();
};

#endif