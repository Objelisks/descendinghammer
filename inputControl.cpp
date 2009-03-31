#include "inputControl.h"
#include "allegro.h"
#include "gameState.h"
#include "coordinate.h"
#include "player.h"
#include "common.h"
#include "behaviors.h"

bool keyDownLSHIFT;

void handleInput()
{
	if(keyboard_needs_poll())
	{
		poll_keyboard();
	}

	if(key[KEY_DOWN])
	{
		if(theState()->player.inversethrustvectoringfuelcoiltoggled)
		{
			theState()->player.moveBackward();
		}
		else
		{
			theState()->player.moveDown();
		}
	}
	if(key[KEY_UP])
	{
		if(theState()->player.inversethrustvectoringfuelcoiltoggled)
		{
			theState()->player.moveForward();
		}
		else
		{
			theState()->player.moveUp();
		}
	}
	if(!keyDownLSHIFT && key[KEY_LSHIFT])
	{
		theState()->player.toggleThrustVectors();
		keyDownLSHIFT = true;
	}
	if(!key[KEY_LSHIFT])
	{
		keyDownLSHIFT = false;
	}
	if(key[KEY_LEFT])
	{
		theState()->player.moveLeft();
	}
	if(key[KEY_RIGHT])
	{
		theState()->player.moveRight();
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