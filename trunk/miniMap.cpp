#include "miniMap.h"
#include "allegro.h"
#include "gameState.h"

MiniMap::MiniMap(BITMAP* parentScreen)
{
	MiniMap::m_subScreen = create_sub_bitmap(parentScreen,10,10,200,200);
	colors[0] = makecol(0,32,16);
	colors[1] = makecol(0,48,16);
	colors[2] = makecol(0,64,16);
	colors[3] = makecol(0,128,32);
	colors[4] = makecol(0,128,64);
	colors[5] = makecol(0,128,96);
	colors[6] = makecol(0,255,128);
};

void MiniMap::draw()
{
	clear_bitmap(m_subScreen);
	rect(m_subScreen,0,0,199,199,colors[3+rand()%2]);
	//scanlines
	int col = colors[rand()%3];
	for(int i=1; i<198; i+=2)
	{
		hline(m_subScreen,1,i,198,col);
	}
	circle(m_subScreen,theState()->player.pos.x,theState()->player.pos.y,5,colors[3]);
};