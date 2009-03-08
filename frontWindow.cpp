#include "frontWindow.h"
#include "gameState.h"


FrontWindow::FrontWindow(BITMAP* parentScreen)
{
	FrontWindow::m_subScreen = create_sub_bitmap(parentScreen,100,200,200,200);
};

void FrontWindow::draw()
{
	
};