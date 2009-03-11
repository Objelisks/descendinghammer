#include "bullet.h"
#include "coordinate.h"

Bullet::Bullet() {
	Bullet::pos = Coordinate(0,0,0);
	dead = false;
};

Bullet::Bullet(Coordinate co, int dmg, int t)
{
	pos = co;
	damage = dmg;
	trail = t;
	dead = false;
};

void Bullet::update()
{
	if(pos.y < 5*trail)
	{
		dead = true;
	}
	pos.setY(pos.y - 1);
};