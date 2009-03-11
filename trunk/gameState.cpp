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
	/*game_keys["up"] = KEY_UP;
	game_keys["down"] = KEY_DOWN;
	game_keys["left"] = KEY_LEFT;
	game_keys["right"] = KEY_RIGHT;*/
	//enemies = std::vector<Enemy>();
	//bullets = std::vector<Bullet>();
	//player = Player();
};

void GameState::updateWorld()
{
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

void GameState::spawnEnemy()
{
	//enemies.insert(Enemy());
};

void GameState::spawnBullet(Coordinate co, int dmg, int trail)
{
	Bullet newBullet = Bullet(co,dmg,trail);
	bullets.insert(bullets.begin(),newBullet);
};

GameState* theState()
{
	return GameState::Instance();
};