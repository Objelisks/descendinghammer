#include "player.h"

Player::Player()
{

};

void Player::moveUp(int amt)
{
	pos.y = pos.y + 10;
};

void Player::moveDown(int amt)
{
	pos.y = pos.y - 10;
};

void Player::moveLeft(int amt)
{
	pos.x = pos.x - 10;
};

void Player::moveRight(int amt)
{
	pos.x = pos.x + 10;
};