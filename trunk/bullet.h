#ifndef _bullet_inc
#define _bullet_inc
#include "coordinate.h"

class Bullet{
public:
	Bullet();
	Bullet(Coordinate co, int dmg, int t, double dir, int speed);
	Coordinate pos;
	int damage;
	int trail;
	double direction;
	bool dead;
	void update();
private:
	double xMove;
	double yMove;
};

#endif