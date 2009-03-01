#include "mainScreen.h"
#include "allegro.h"
#include "gameState.h"


void clearScreen()
{
	clear_to_color(screen,0);
};

void drawShip()
{
	putpixel(screen,theState->player.pos.x,theState->player.pos.y,1);
};



MainScreen::MainScreen()
{

};

void MainScreen::draw(){
clearScreen();
drawShip();
};