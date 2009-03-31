#include "mainScreen.h"
#include "allegro.h"
#include "gameState.h"
#include "subScreen.h"
#include "common.h"
#include "resources.h"
#include "boost/ptr_container/ptr_list.hpp"

#include "frontWindow.h"
#include "miniMap.h"
#include "txtScreen.h"
#include "indicator.h"

MainScreen::MainScreen()
{
	m_screen = create_bitmap(SCREEN_W,SCREEN_H);
	subScreens = boost::ptr_list<SubScreen>();
	init = false;
};

void MainScreen::drawSubScreens()
{
	for(boost::ptr_list<SubScreen>::iterator iter=subScreens.begin();iter!=subScreens.end();iter++)
	{
		iter->draw();
	}
};


void MainScreen::draw(){

	if(!init)
	{
		TextScreen* txt = new TextScreen(m_screen, 444, 392);
		subScreens.insert(subScreens.begin(), txt);
		theState()->txtScreen = txt;
		subScreens.insert(subScreens.begin(), new FrontWindow(m_screen,SCREEN_W,200));
		subScreens.insert(subScreens.begin(), new MiniMap(m_screen, 250, 150));
		subScreens.insert(subScreens.begin(), new Indicator(m_screen, IND_METER, &theState()->player.intSpeed, 450, 280));
		subScreens.insert(subScreens.begin(), new Indicator(m_screen, IND_LIGHT, &theState()->player.cooldown, 550, 320));
		subScreens.insert(subScreens.begin(), new Indicator(m_screen, IND_LIGHT, &theState()->player.inversethrustvectoringfuelcoiltoggled, 600, 320));
		BITMAP* img = theState()->resources.images["hud.bmp"];
		hud = get_rle_sprite(img);
		theState()->resources.destroyBmp("hud.bmp");
		init = true;
	}

	draw_rle_sprite(m_screen,hud,0,0);
	drawSubScreens();
	rectfill(m_screen,0,0,300,40,makecol(0,0,0));
	textout_ex(m_screen,font,toString(frameRate).c_str(),5,5,makecol(255,255,255),0);
	textout_ex(m_screen,font,toString(theState()->bulletManager->bullets.size()).c_str(),25,5,makecol(255,255,255),0);
	textout_ex(m_screen,font,toString(theState()->enemyManager->enemies.size()).c_str(),50,5,makecol(255,255,255),0);
	textout_ex(m_screen,font,toString(theState()->humans).c_str(),90,5,makecol(255,255,255),0);
	textout_ex(m_screen,font,toString(theState()->humansToKill).c_str(),190,5,makecol(255,255,255),0);
	textout_ex(m_screen,font,((toString(theState()->player.pos.x).append(", "+toString(theState()->player.pos.y))).append(", "+toString(theState()->player.pos.z))).c_str(),5,25,makecol(255,255,255),0);
	blit(m_screen,screen,0,0,0,0,m_screen->w,m_screen->h);
};