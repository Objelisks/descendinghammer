//enemy location
//enemy spawn
//enemy movement
//bullets
//collision?
#ifndef _gamestate_inc
#define _gamestate_inc

#include "allegro.h"
#include "enemy.h"
#include "bullet.h"
#include "player.h"
#include "screen.h"
#include "vector"
#include "string"
#include "map"

class GameState {
public:
	static GameState* Instance();
	void Initialize();
	std::vector<Enemy> enemies;
	std::vector<Bullet> bullets;
	Screen* currentScreen;
	Player player;
	//std::map<std::string,int> game_keys;
	void updateWorld();
	void spawnEnemy();
	void spawnBullet(Coordinate co, int dmg, int trail);
protected:
	GameState();
	GameState(const GameState&);
	GameState& operator= (const GameState&);
private:
	static GameState* instance;
};

GameState* theState();

#endif