#include "frontWindow.h"
#include "gameState.h"
#include "allegro.h"


FrontWindow::FrontWindow(BITMAP* parentScreen)
{
	m_subScreen = create_sub_bitmap(parentScreen,0,50,SCREEN_W,200);
};

void FrontWindow::draw()
{
	rect(m_subScreen,0,0,m_subScreen->w-1,m_subScreen->h-1,makecol(255,255,255));
};