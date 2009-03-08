//health
//position
//bullets
#ifndef _enemy_inc
#define _enemy_inc
#include "coordinate.h"

struct Enemy{
public:
	Enemy();
	Coordinate pos;
	int health;
	void update();
};

#endif