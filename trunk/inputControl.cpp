#include "inputControl.h"
#include "allegro.h"
#include "gameState.h"
#include "coordinate.h"
#include "player.h"
#include "common.h"


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
};