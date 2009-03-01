#include "mainScreen.h"
#include "allegro.h"
#include "gameState.h"

void clearScreen()
{
	clear_bitmap(screen);
};

void drawShip()
{
	rectfill(screen,theState.player.pos.x-10,theState.player.pos.y-10,theState.player.pos.x+10,theState.player.pos.y+10,1);
};



MainScreen::MainScreen()
{

};

void MainScreen::draw(){
	clearScreen();
	drawShip();
};