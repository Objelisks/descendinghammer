//health
//position
//bullets
#ifndef _enemy_inc
#define _enemy_inc
#include "coordinate.h"

struct Enemy{
public:
	Enemy();
	Enemy(double (*xM)(int), double (*yM)(int));
	Coordinate pos;
	int health;
	int life;
	double (*xMove)(int t);
	double (*yMove)(int t);
	void update();
};

#endif