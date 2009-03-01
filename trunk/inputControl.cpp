#include "inputControl.h"
#include "allegro.h"
#include "gameState.h"

void handleInput()
{
	if(key[theState->game_keys["down"]])
	{
		theState->player.moveDown(1);
	}
	if(key[theState->game_keys["up"]])
	{
		theState->player.moveUp(1);
	}
	if(key[theState->game_keys["left"]])
	{
		theState->player.moveLeft(1);
	}
	if(key[theState->game_keys["right"]])
	{
		theState->player.moveRight(1);
	}
};