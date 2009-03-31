#include "bullet.h"
#include "coordinate.h"
#include "cmath"
#include "common.h"
#include "gameState.h"

Bullet::Bullet() {
	pos = Coordinate(0,0,0);
	damage = 1;
	trail = 1;
	speed = 1;
	image = theState()->resources.images["bullet.bmp"];
	dead = false;
};

Bullet::Bullet(Coordinate co, int dmg, int t, double s, void (*m)(Coordinate* ,int, double))
{
	pos = co;
	damage = dmg;
	trail = t;
	speed = s;
	move = m;
	image = theState()->resources.images["bullet.bmp"];
	life = 1;
	dead = false;
};

void Bullet::update()
{
	(*move)(&pos, life, speed);
	life++;
	if(pos.y < -5)
	{
		dead = true;
	}
};