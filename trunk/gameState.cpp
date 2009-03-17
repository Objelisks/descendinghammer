#include "gamestate.h"
#include "player.h"
#include "bullet.h"
#include "list"
#include "mainScreen.h"
#include "coordinate.h"
#include "screen.h"
#include "allegro.h"

GameState* GameState::instance = 0;

GameState* GameState::Instance()
{
	if(instance == 0)
	{
		instance = new GameState;
	}
	return instance;
};

GameState::GameState()
{
	Initialize();
};

void GameState::Initialize()
{
	currentScreen = new MainScreen();
};

void GameState::updateWorld()
{
	enemyManager.moveAll();

	bulletManager.moveAll();
	bulletManager.collideWithShips();

	if(player.cooldown > 0)
	{
		player.cooldown--;
	}
};

void GameState::spawnEnemy(Enemy e)
{
	enemyManager.spawnEnemy(e);
};

void GameState::spawnBullet(Bullet b)
{
	bulletManager.spawnBullet(b);
};

GameState* theState()
{
	return GameState::Instance();
};