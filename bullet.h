#ifndef _bullet_inc
#define _bullet_inc
#include "coordinate.h"

class Bullet {
public:
	Bullet();
	Bullet(Coordinate co, int dmg, int t, int speed, void (*m)(Coordinate* ,int));
	Coordinate pos;
	int damage;
	int trail;
	int speed;
	int life;
	void (*move)(Coordinate* ,int);
	bool dead;
	void update();
};

#endif