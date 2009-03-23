#include "bullet.h"
#include "coordinate.h"
#include "cmath"
#include "common.h"

Bullet::Bullet() {
	pos = Coordinate(0,0,0);
	damage = 1;
	trail = 1;
	direction = 0;
	speed = 1;
	dead = false;
};

Bullet::Bullet(Coordinate co, int dmg, int t, double dir, int s)
{
	pos = co;
	damage = dmg;
	trail = t;
	direction = dir;
	speed = s;
	xMove = cos(rad(direction))*speed;
	yMove = sin(rad(direction))*speed;
	//zMove = sin(rad(direction))*speed;
	dead = false;
};

void Bullet::update()
{
	
	if(pos.y < -5*trail)
	{
		dead = true;
	}
	//pos.z = pos.z - zMove;
	pos.y = pos.y - yMove;
	pos.x = pos.x - xMove;
};