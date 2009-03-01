//health
//position
//bullets
#ifndef _enemy_inc
#define _enemy_inc
#include "coordinate.h"

struct Enemy{
public:
	Coordinate pos;
	int health;
	void update();
};

#endif