#include "mainScreen.h"
#include "allegro.h"
#include "gameState.h"
#include "subScreen.h"
#include "boost/ptr_container/ptr_list.hpp"

#include "frontWindow.h"
#include "miniMap.h"

MainScreen::MainScreen()
{
	MainScreen::m_screen = create_bitmap(SCREEN_W,SCREEN_H);
	subScreens = boost::ptr_list<SubScreen>();
	subScreens.insert(subScreens.begin(), new FrontWindow(m_screen));
	subScreens.insert(subScreens.begin(), new MiniMap(m_screen));
};

void MainScreen::drawSubScreens()
{
	for(boost::ptr_list<SubScreen>::iterator iter=subScreens.begin();iter!=subScreens.end();iter++)
	{
		iter->draw();
	}
};


void MainScreen::draw(){
	drawSubScreens();
	blit(m_screen,screen,0,0,0,0,m_screen->w,m_screen->h);
};