#include "gamestate.h"
#include "player.h"
#include "mainScreen.h"
#include "screen.h"
#include "allegro.h"

GameState::GameState()
{
	GameState::enemies = std::vector<Enemy>();
	GameState::bullets = std::vector<Bullet>();
	GameState::player = Player();
	GameState::currentScreen = MainScreen();
	GameState::game_keys = std::map<std::string,int>();
	game_keys.insert(std::make_pair<std::string,int>("up",key[KEY_UP]));
	game_keys.insert(std::make_pair<std::string,int>("down",key[KEY_DOWN]));
	game_keys.insert(std::make_pair<std::string,int>("left",key[KEY_LEFT]));
	game_keys.insert(std::make_pair<std::string,int>("right",key[KEY_RIGHT]));
};