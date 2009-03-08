#include "enemy.h"
#include "coordinate.h"
#include "allegro.h"

Enemy::Enemy()
{
	pos = Coordinate(rand()%SCREEN_W,0,0);
	health = 100;
};

void Enemy::update()
{
	pos.y = pos.y - 1;
};