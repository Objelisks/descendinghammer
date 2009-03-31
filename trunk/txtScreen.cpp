#include "txtScreen.h"
#include "allegro.h"
#include "gameState.h"
#include "string"
#include "vector"

TextScreen::TextScreen()
{
	available = false;
};

TextScreen::TextScreen(BITMAP* parentScreen, int x, int y)
{
	m_subScreen = create_sub_bitmap(parentScreen,x,y,171,63);
	text = std::vector<std::string>();
	lines = 0;
	maxLines = 100/font->height;
	color = makecol(255,255,255);
	available = true;
};

void TextScreen::draw()
{
	clear_bitmap(m_subScreen);
	rect(m_subScreen,0,0,m_subScreen->w-1,m_subScreen->h-1,makecol(255,255,255));
	int pos = 100-font->height;
	for(std::vector<std::string>::iterator iter=text.begin();iter != text.end();iter++)
	{
		textout_ex(m_subScreen,font,iter->substr(0,24).c_str(),5,pos,color,-1);
		pos-=font->height;
	}
};

void TextScreen::addText(std::string str)
{
	text.insert(text.end(),str);
	if(text.size() > maxLines)
	{
		text.erase(text.begin());
	}
};