#include "menu.h"
#include "allegro.h"
#include "string"
#include "gameState.h"
#include "mainScreen.h"
#include "map"

void Playhard()
{
	theState()->difficulty = 5000;
	theState()->currentScreen = new MainScreen();
};

void Playharder()
{
	theState()->difficulty = 48000;
	theState()->currentScreen = new MainScreen();
};

void Playhardest()
{
	theState()->difficulty = 1000000000;
	theState()->currentScreen = new MainScreen();
};

void Quitter()
{
	theState()->GAME_ENDED = true;
};

Menu::Menu(int* menuChooser)
{
	name = "Menu";
	m_screen = create_bitmap(SCREEN_W,SCREEN_H);
	currentChoice = menuChooser;
	menu = std::map<std::string,void(*)()>();
	menu.insert(menu.end(), std::pair<std::string,void(*)()>(std::string("Hard"), &Playhard));
	menu.insert(menu.end(), std::pair<std::string,void(*)()>(std::string("Harder"), &Playharder));
	menu.insert(menu.end(), std::pair<std::string,void(*)()>(std::string("Hardest"), &Playhardest));
	menu.insert(menu.end(), std::pair<std::string,void(*)()>(std::string("Quit or something I guess"), &Quitter));
};

void Menu::draw()
{
	clear_bitmap(m_screen);

	if(*currentChoice < 0)
	{
		*currentChoice = (int)menu.size()-1;
	}
	if(*currentChoice > (int)menu.size()-1)
	{
		*currentChoice = 0;
	}

	for(int i=0; i<font->height+4; i++)
	{
		line(m_screen, 23, 50+50*(*currentChoice)-2+i, rand()%25+175, 50+50*(*currentChoice)-2+i, makecol(100,100,10));
	}

	int pos = 1;
	for(std::map<std::string,void(*)()>::iterator iter=menu.begin(); iter != menu.end(); iter++)
	{
		textout_ex(m_screen, font, iter->first.c_str(), 25, 50*pos, makecol(255,255,255), -1);
		pos++;
	}

	for(int i=0; i<30; i++)
	{
		textout_ex(m_screen, font, "Descending Hammer", 359+rand()%2, 50+(i*font->height+2), makecol(255-i*8,255-i*8,255-i*8), -1);
	}

	blit(m_screen,screen,0,0,0,0,m_screen->w,m_screen->h);
};

void Menu::execute()
{
	switch(*currentChoice)
	{
	case 0:
		menu["Hard"]();
		break;
	case 1:
		menu["Harder"]();
		break;
	case 2:
		menu["Hardest"]();
		break;
	case 3:
		menu["Quit or something I guess"]();
		break;
	}
	theState()->txtScreen = TextScreen(theState()->currentScreen->m_screen, 444, 392);
};