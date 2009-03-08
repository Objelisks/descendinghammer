#include "gamestate.h"
#include "player.h"
#include "mainScreen.h"
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
	//game_keys = std::map<std::string,int>();
	game_keys["up"] = KEY_UP;
	game_keys["down"] = KEY_DOWN;
	game_keys["left"] = KEY_LEFT;
	game_keys["right"] = KEY_RIGHT;
	enemies = std::vector<Enemy>();
	bullets = std::vector<Bullet>();
	player = Player();
};

void GameState::spawnEnemy()
{
	//enemies.insert(new Enemy());
};

GameState* theState()
{
	return GameState::Instance();
};