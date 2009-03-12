#include "bullet.h"
#include "coordinate.h"
#include "cmath"
#include "common.h"

Bullet::Bullet() {
	Bullet::pos = Coordinate(0,0,0);
	dead = false;
};

Bullet::Bullet(Coordinate co, int dmg, int t, double dir, int speed)
{
	pos = co;
	damage = dmg;
	trail = t;
	direction = dir;
	xMove = cos(rad(direction))*speed;
	yMove = sin(rad(direction))*speed;
	dead = false;
};

void Bullet::update()
{
	
	if(pos.y < 5*trail)
	{
		dead = true;
	}
	pos.y = pos.y - yMove;
	pos.x = pos.x - xMove;
};