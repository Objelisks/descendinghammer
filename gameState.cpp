#include "gamestate.h"
#include "player.h"
#include "bullet.h"
#include "list"
#include "mainScreen.h"
#include "coordinate.h"
#include "screen.h"
#include "allegro.h"
#include "common.h"
#include "boost/random/linear_congruential.hpp"

#include "txtScreen.h"

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
};

void GameState::Initialize()
{
	currentScreen = new MainScreen();
	bulletManager = new BulletManager();
	enemyManager = new EnemyManager();
	world = World(200,800,200);
	score = 0;
	humans = 4294967294; //initial attack wiped out most of them
	humansToKill = 0;
};

void GameState::Destroy()
{
	delete currentScreen;
	delete bulletManager;
	delete enemyManager;
	delete txtScreen;
	resources.destroy();
};

void GameState::updateWorld()
{
	//enemyManager->moveAll();
	for(std::list<Enemy>::iterator iter = enemyManager->enemies.begin(); iter!= enemyManager->enemies.end();)
	{
		if(iter->dead)
		{
			iter = enemyManager->enemies.erase(iter);
		}
		else
		{
			iter->update();
			iter++;
		}
	}

	bulletManager->moveAll();

	player.update();

	if(humansToKill > 0)
	{

		int kill = (((unsigned int)rand())*32)%(humansToKill+1);
		humans-=kill;
		humansToKill-=kill;
	}

	textTimer++;
	if(textTimer > 20)
	{
		txtScreen->addText("Score: " + toString(score));
		textTimer = 0;
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

int GameState::collideEnemyWithBullets(Enemy e)
{
	int dmg = 0;
	for(std::list<Bullet>::iterator iter = theState()->bulletManager->bullets.begin(); iter!= theState()->bulletManager->bullets.end();)
	{
		if(collide(iter->pos,e.pos,e.size))
		{
			dmg = dmg + iter->damage;
			iter = theState()->bulletManager->bullets.erase(iter);
			score++;
		}
		else
		{
			iter++;
		}
	}
	return dmg;
};

bool GameState::collide(Coordinate pos1, Coordinate pos2, int size)
{
	if(pos1.x < pos2.x+size && pos1.x > pos2.x-size)
	if(pos1.y < pos2.y+size && pos1.y > pos2.y-size)
	if(pos1.z < pos2.z+size && pos1.z > pos2.z-size)
		return true;
	return false;
};

GameState* theState()
{
	return GameState::Instance();
};