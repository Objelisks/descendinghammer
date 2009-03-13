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
		theState()->player.moveDown(5);
	}
	if(key[KEY_UP])
	{
		theState()->player.moveUp(5);
	}
	if(key[KEY_LEFT])
	{
		theState()->player.moveLeft(5);
	}
	if(key[KEY_RIGHT])
	{
		theState()->player.moveRight(5);
	}
	if(key[KEY_X])
	{
		theState()->player.fire();
	}
	if(key[KEY_1])
	{
		Enemy newEnemy = Enemy(&Behaviors::Stay,&Behaviors::Straight);
		theState()->spawnEnemy(newEnemy);
	}
	if(key[KEY_2])
	{
		Enemy newEnemy = Enemy(&Behaviors::Wave,&Behaviors::Straight);
		theState()->spawnEnemy(newEnemy);
	}
	if(key[KEY_3])
	{
		Enemy newEnemy = Enemy(&Behaviors::Zag,&Behaviors::Straight);
		theState()->spawnEnemy(newEnemy);
	}
};