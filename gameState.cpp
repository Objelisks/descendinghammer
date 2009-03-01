#include "gamestate.h"
#include "player.h"
#include "mainScreen.h"
#include "screen.h"
#include "allegro.h"

GameState::GameState()
{
	enemies = std::vector<Enemy>();
	bullets = std::vector<Bullet>();
	player = Player();
	currentScreen = MainScreen();
	game_keys = std::map<std::string,int>();
	game_keys["up"] = key[KEY_UP];
	game_keys["down"] = key[KEY_DOWN];
	game_keys["left"] = key[KEY_LEFT];
	game_keys["right"] = key[KEY_RIGHT];
};