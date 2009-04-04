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
#include "weaponMeter.h"

MainScreen::MainScreen()
{
	name = "MainScreen";
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
		subScreens.insert(subScreens.end(), &theState()->txtScreen);
		subScreens.insert(subScreens.end(), new FrontWindow(m_screen,SCREEN_W,200));
		subScreens.insert(subScreens.end(), new MiniMap(m_screen, 250, 150));
		subScreens.insert(subScreens.end(), new Indicator(m_screen, theState()->resources.images["SPACECOMPASS"], IND_METER, &theState()->player.direction, 520, 300));
		subScreens.insert(subScreens.end(), new Indicator(m_screen, theState()->resources.images["meter"], IND_METER, &theState()->player.intSpeed, 430, 300));
		subScreens.insert(subScreens.end(), new Indicator(m_screen, theState()->resources.images["light"], IND_LIGHT, &theState()->player.inversethrustvectoringfuelcoiltoggled, 600, 320));
		subScreens.insert(subScreens.end(), new WeaponMeter(m_screen, 10, 300));
		hud = get_rle_sprite(theState()->resources.images["hud"]);
		theState()->resources.destroyBmp("hud");
		spoiler = Effect(theState()->resources.effects["Spoilers"],Coordinate(0,0,0),15,true);;
		init = true;
	}

	if(!theState()->ending)
	{
		draw_rle_sprite(m_screen,hud,0,0);
		drawSubScreens();
		rectfill(m_screen,0,0,300,40,makecol(0,0,0));
		textout_ex(m_screen,font,toString(frameRate).c_str(),5,5,makecol(255,255,255),0);
		textout_ex(m_screen,font,toString(theState()->bulletManager.bullets.size()).c_str(),25,5,makecol(255,255,255),0);
		textout_ex(m_screen,font,toString(theState()->enemyManager.enemies.size()).c_str(),50,5,makecol(255,255,255),0);
		textout_ex(m_screen,font,toString(theState()->humans).c_str(),90,5,makecol(255,255,255),0);
		textout_ex(m_screen,font,toString(theState()->humansToKill).c_str(),190,5,makecol(255,255,255),0);
		textout_ex(m_screen,font,((toString(theState()->player.pos.x).append(", "+toString(theState()->player.pos.y))).append(", "+toString(theState()->player.pos.z))).c_str(),5,25,makecol(255,255,255),0);
	}
	else
	{
		clear_bitmap(m_screen);
		textout_ex(m_screen,font,"Earth is destroyed",SCREEN_W/5,2*SCREEN_H/3,makecol(255,255,255),-1);
		textout_ex(m_screen,font,"You lose",SCREEN_W/5,2*SCREEN_H/3+20,makecol(255,255,255),-1);
		
		textout_ex(m_screen,font,("Score: " + toString(theState()->score)).c_str(),SCREEN_W/5,2*SCREEN_H/3+50,makecol(255,255,255),-1);

		int fgsfds = rand()%80;
		textout_ex(m_screen,font,"Press ESC to quit.",SCREEN_W/5,2*SCREEN_H/3+100,makecol(150-fgsfds,150-fgsfds,150-fgsfds),-1);

		draw_sprite(m_screen,spoiler.draw(),SCREEN_W/3,SCREEN_H/8);
	}
	blit(m_screen,screen,0,0,0,0,m_screen->w,m_screen->h);
};