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
	for(std::list<Enemy>::iterator iter = theState()->enemies.begin(); iter!= theState()->enemies.end();)
	{
		iter->update();
		iter++;
	}
	for(std::list<Bullet>::iterator iter = theState()->bullets.begin(); iter!= theState()->bullets.end();)
	{
		if(iter->dead)
		{
			iter = bullets.erase(iter);
		}
		else
		{
			iter->update();
			iter++;
		}
	}
	if(player.cooldown > 0)
	{
		player.cooldown--;
	}
};

void GameState::spawnEnemy(Enemy e)
{
	enemies.insert(enemies.begin(),e);
};

void GameState::spawnBullet(Bullet b)
{
	bullets.insert(bullets.begin(),b);
};

GameState* theState()
{
	return GameState::Instance();
};