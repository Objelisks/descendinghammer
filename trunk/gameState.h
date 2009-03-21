//enemy location
//enemy spawn
//enemy movement
//bullets
//collision?
#ifndef _gameState_inc
#define _gameState_inc

#include "allegro.h"
#include "enemy.h"
#include "bullet.h"
#include "player.h"
#include "screen.h"
#include "world.h"
#include "enemyManager.h"
#include "bulletManager.h"
#include "list"
#include "string"
#include "map"

class GameState {
public:
	static GameState* Instance();
	void Initialize();
	void Destroy();
	EnemyManager* enemyManager;
	BulletManager* bulletManager;
	Screen* currentScreen;
	Player player;
	World world;
	void updateWorld();
	void spawnEnemy(Enemy e);
	void spawnBullet(Bullet b);
protected:
	GameState();
	GameState(const GameState&);
	GameState& operator= (const GameState&);
private:
	static GameState* instance;
};

GameState* theState();

#endif