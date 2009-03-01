#ifndef _player_inc
#define _player_inc
#include "ship.h"

class Player : public Ship {
public:
	Player();
	void Player::moveLeft(int amt);
	void Player::moveUp(int amt);
	void Player::moveRight(int amt);
	void Player::moveDown(int amt);
};

#endif