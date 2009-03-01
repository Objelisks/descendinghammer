//enemy location
//enemy spawn
//enemy movement
//bullets
//collision?
#ifndef _gamestate_inc
#define _gamestate_inc

#include "enemy.h"
#include "bullet.h"
#include "player.h"
#include "screen.h"
#include "vector"
#include "string"
#include "map"

class GameState {
public:
	GameState();
	std::vector<Enemy> enemies;
	std::vector<Bullet> bullets;
	Screen* currentScreen;
	Player player;
	std::map<std::string,int> game_keys;
};

static GameState theState;


#endif