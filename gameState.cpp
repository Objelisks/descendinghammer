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

int GameState::collideEnemyWithBullets(Enemy e)
{
	int dmg = 0;
	for(std::list<Bullet>::iterator iter = theState()->bulletManager->bullets.begin(); iter!= theState()->bulletManager->bullets.end();)
	{
		if(collide(iter->pos,e.pos,e.size))
		{
			dmg = dmg + iter->damage;
			iter = theState()->bulletManager->bullets.erase(iter);

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