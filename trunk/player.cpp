#include "player.h"
#include "coordinate.h"
#include "allegro.h"
#include "gameState.h"
#include "common.h"

Player::Player() : Ship()
{
	pos = Coordinate(20,20,20);
	cooldown = 0;
};

void Player::moveUp(int amt)
{
	if(pos.y > 0){
		pos.setY(pos.y - 1);
	}
};

void Player::moveDown(int amt)
{
	if(pos.y < SCREEN_H){
		pos.setY(pos.y + 1);
	}
};

void Player::moveLeft(int amt)
{
	if(pos.x > 0){
		pos.setX(pos.x - 1);
	}
};

void Player::moveRight(int amt)
{
	if(pos.x < SCREEN_W){
		pos.setX(pos.x + 1);
	}
};

void Player::fire()
{
	if(cooldown == 0)
	{
		Coordinate firePos = pos;
		firePos.x += -5+rand()%10;
		firePos.y -= 10;
		theState()->spawnBullet(firePos,1,5);
		cooldown = 8 + rand()%4;
	}
};