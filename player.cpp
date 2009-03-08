#include "player.h"
#include "coordinate.h"
#include "allegro.h"
#include "common.h"

Player::Player() : Ship()
{
	pos = Coordinate(20,20,20);
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