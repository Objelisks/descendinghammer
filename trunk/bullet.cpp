#include "bullet.h"
#include "coordinate.h"
#include "cmath"
#include "common.h"

Bullet::Bullet() {
	pos = Coordinate(0,0,0);
	damage = 1;
	trail = 1;
	speed = 1;
	dead = false;
};

Bullet::Bullet(Coordinate co, int dmg, int t, int s, void (*m)(Coordinate* ,int))
{
	pos = co;
	damage = dmg;
	trail = t;
	speed = s;
	move = m;
	life = 1;
	dead = false;
};

void Bullet::update()
{
	(*move)(&pos, life);
	life++;
	if(pos.y < -5)
	{
		dead = true;
	}
};