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
	bulletManager = new BulletManager();
	enemyManager = new EnemyManager();
	player = Player();
	world = World(1000,1000,1000);
};

void GameState::Destroy()
{
	delete currentScreen;
	delete bulletManager;
	delete enemyManager;
};

void GameState::updateWorld()
{
	//theState()->enemyManager->moveAll();
	for(std::list<Enemy>::iterator iter = theState()->enemyManager->enemies.begin(); iter!= theState()->enemyManager->enemies.end();)
	{
		if(iter->dead)
		{
			iter = theState()->enemyManager->enemies.erase(iter);
		}
		else
		{
			iter->update();
			iter++;
		}
	}


	theState()->bulletManager->moveAll();
	theState()->bulletManager->collideWithShips();

	if(player.cooldown > 0)
	{
		player.cooldown--;
	}
};

void GameState::spawnEnemy(Enemy e)
{
	theState()->enemyManager->spawnEnemy(e);
};

void GameState::spawnBullet(Bullet b)
{
	theState()->bulletManager->spawnBullet(b);
};

GameState* theState()
{
	return GameState::Instance();
};