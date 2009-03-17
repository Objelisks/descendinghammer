#include "inputControl.h"
#include "allegro.h"
#include "gameState.h"
#include "coordinate.h"
#include "player.h"
#include "common.h"
#include "behaviors.h"


void handleInput()
{
	if(keyboard_needs_poll())
	{
		poll_keyboard();
	}

	if(key[KEY_DOWN])
	{
		theState()->player.moveDown(15);
	}
	if(key[KEY_UP])
	{
		theState()->player.moveUp(15);
	}
	if(key[KEY_LEFT])
	{
		theState()->player.moveLeft(15);
	}
	if(key[KEY_RIGHT])
	{
		theState()->player.moveRight(15);
	}
	if(key[KEY_X])
	{
		theState()->player.fire();
	}
	if(key[KEY_1])
	{
		Enemy newEnemy = Enemy(&Behaviors::Straight);
		theState()->spawnEnemy(newEnemy);
	}
	if(key[KEY_2])
	{
		Enemy newEnemy = Enemy(&Behaviors::Wave);
		theState()->spawnEnemy(newEnemy);
	}
	if(key[KEY_3])
	{
		Enemy newEnemy = Enemy(&Behaviors::Zag);
		theState()->spawnEnemy(newEnemy);
	}
	if(key[KEY_4])
	{
		Enemy newEnemy = Enemy(&Behaviors::Homing);
		theState()->spawnEnemy(newEnemy);
	}
};