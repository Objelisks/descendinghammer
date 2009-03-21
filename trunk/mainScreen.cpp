#include "mainScreen.h"
#include "allegro.h"
#include "gameState.h"
#include "subScreen.h"
#include "common.h"
#include "boost/ptr_container/ptr_list.hpp"

#include "frontWindow.h"
#include "miniMap.h"

MainScreen::MainScreen()
{
	m_screen = create_bitmap(SCREEN_W,SCREEN_H);
	BITMAP* img = load_bitmap("hud.bmp",0);
	hud = get_rle_sprite(img);
	destroy_bitmap(img);
	subScreens = boost::ptr_list<SubScreen>();
	subScreens.insert(subScreens.begin(), new FrontWindow(m_screen,SCREEN_W,200));
	subScreens.insert(subScreens.begin(), new MiniMap(m_screen, 250, 150));
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
	textout_ex(m_screen,font,toString(frameRate).c_str(),5,5,makecol(255,255,255),0);
	textout_ex(m_screen,font,((toString(theState()->player.pos.x).append(", "+toString(theState()->player.pos.y))).append(", "+toString(theState()->player.pos.z))).c_str(),5,25,makecol(255,255,255),0);
	draw_rle_sprite(m_screen,hud,0,0);
	blit(m_screen,screen,0,0,0,0,m_screen->w,m_screen->h);
};