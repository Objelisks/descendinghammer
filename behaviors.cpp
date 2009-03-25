#include "behaviors.h"
#include "gameState.h"
#include "cmath"
#include "common.h"

void Behaviors::Wave(Coordinate *c, int t)
{
	c->x = c->x + cos(rad((double)t));
	c->y = c->y + 1;
};

void Behaviors::Zag(Coordinate *c, int t)
{
	c->x = c->x + (t%50<25 ? 1 : -1);
	c->y = c->y + 1;
};

void Behaviors::Stay(Coordinate *c, int t)
{
	
};

void Behaviors::Straight(Coordinate *c, int t)
{
	c->y = c->y + 1;
};

void Behaviors::Homing(Coordinate *c, int t)
{
	c->x = c->x + (theState()->player.pos.x-c->x ? 1 : -1);
	c->y = c->y + 1;
};

void Behaviors::Bullet(Coordinate *c, int t)
{
	c->y = c->y - 1;
};