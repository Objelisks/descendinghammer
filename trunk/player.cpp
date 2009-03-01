#include "player.h"
#include "allegro.h"

Player::Player()
{
	pos.x = 0;
	pos.y = 0;
};

void Player::moveUp(int amt)
{
	if(pos.y < SCREEN_H){
		pos.y = pos.y + 1;
	}
};

void Player::moveDown(int amt)
{
	if(pos.y > 0){
		pos.y = pos.y - 1;
	}
};

void Player::moveLeft(int amt)
{
	if(pos.x > 0){
		pos.x = pos.x - 1;
	}
};

void Player::moveRight(int amt)
{
	if(pos.x < SCREEN_W){
		pos.x = pos.x + 10;
	}
};