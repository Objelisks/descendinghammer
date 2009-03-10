#include "bullet.h"
#include "coordinate.h"

Bullet::Bullet() {
	Bullet::pos = Coordinate(0,0,0);
};

Bullet::Bullet(Coordinate co, int dmg, int t)
{
	pos = co;
	damage = dmg;
	trail = t;
};

void Bullet::update()
{
	pos.setY(pos.y - 1);
};