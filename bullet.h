#ifndef _bullet_inc
#define _bullet_inc
#include "coordinate.h"
#include "allegro.h"

class Bullet {
public:
	Bullet();
	Bullet(Coordinate co, int dmg, int t, double speed, void (*m)(Coordinate* ,int, double));
	Coordinate pos;
	int damage;
	int trail;
	double speed;
	int life;
	void (*move)(Coordinate* ,int, double);
	BITMAP* image;
	bool dead;
	void update();
};

#endif