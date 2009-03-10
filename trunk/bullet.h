#ifndef _bullet_inc
#define _bullet_inc
#include "coordinate.h"

class Bullet{
public:
	Bullet();
	Bullet(Coordinate co, int dmg, int t);
	Coordinate pos;
	int damage;
	int trail;
	void update();
};

#endif