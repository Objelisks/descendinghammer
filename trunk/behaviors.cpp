#include "behaviors.h"
#include "gameState.h"
#include "cmath"
#include "common.h"

void Behaviors::Wave(Coordinate *c, int t, double speed)
{
	c->x = c->x + cos(rad((double)t))*speed;
	c->y = c->y + speed;
};

void Behaviors::Zag(Coordinate *c, int t, double speed)
{
	c->x = c->x + (t%30<15 ? 1 : -1)*speed;
	c->y = c->y + speed;
};

void Behaviors::Stay(Coordinate *c, int t, double speed)
{
	
};

void Behaviors::Straight(Coordinate *c, int t, double speed)
{
	c->y = c->y + speed;
};

void Behaviors::Homing(Coordinate *c, int t, double speed)
{
	c->x = c->x + (theState()->player.pos.x-c->x>0 ? 1 : -1)*speed;
	c->y = c->y + speed;
};