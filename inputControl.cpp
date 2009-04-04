#include "inputControl.h"
#include "allegro.h"
#include "gameState.h"
#include "coordinate.h"
#include "player.h"
#include "common.h"
#include "screen.h"
#include "behaviors.h"

bool keyDownMENU;

void menuInput()
{
	if(keyDownMENU && !key[KEY_UP] && !key[KEY_DOWN] && !key[KEY_ENTER])
	{
		keyDownMENU = false;
	}
	if(!keyDownMENU && key[KEY_UP])
	{
		theState()->menuChooser--;
		keyDownMENU = true;
	}
	if(!keyDownMENU && key[KEY_DOWN])
	{
		theState()->menuChooser++;
		keyDownMENU = true;
	}
	if(!keyDownMENU && key[KEY_ENTER])
	{
		theState()->currentScreen->execute();
		keyDownMENU = true;
	}
};

bool keyDownLSHIFT;
bool keyDownZ;

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
	if(!keyDownZ && key[KEY_Z])
	{
		theState()->player.switchWeapon();
		keyDownZ = true;
	}
	if(!key[KEY_Z])
	{
		keyDownZ = false;
	}
	
	if(key[KEY_1])
	{
		theState()->ending = true;
	}
	/*
	if(key[KEY_2])
	{
		Enemy newEnemy = Enemy(&Behaviors::Wave);
		theState()->addEnemy(newEnemy);
	}
	if(key[KEY_3])
	{
		Enemy newEnemy = Enemy(&Behaviors::Zag);
		theState()->addEnemy(newEnemy);
	}
	if(key[KEY_4])
	{
		Enemy newEnemy = Enemy(&Behaviors::Homing);
		theState()->addEnemy(newEnemy);
	}
	*/
};