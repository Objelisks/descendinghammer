//health
//position
//bullets
#ifndef _enemy_inc
#define _enemy_inc
#include "coordinate.h"
#include "allegro.h"

class Enemy {
public:
	Enemy();
	Enemy(void (*m)(Coordinate*, int, double));
	Coordinate pos;
	int health;
	int size;
	int life;
	double speed;
	bool dead;
	BITMAP* image;
	void (*move)(Coordinate *c, int t, double);
	void update();
};

#endif