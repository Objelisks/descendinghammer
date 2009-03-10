#include "gamestate.h"
#include "player.h"
#include "bullet.h"
#include "vector"
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
	for(std::vector<Bullet>::iterator iter = theState()->bullets.begin(); iter!= theState()->bullets.end(); iter++)
	{
		iter->update();
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