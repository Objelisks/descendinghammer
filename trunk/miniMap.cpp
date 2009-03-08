#include "miniMap.h"
#include "allegro.h"
#include "gameState.h"

MiniMap::MiniMap(BITMAP* parentScreen)
{
	MiniMap(parentScreen,300,200);
};

MiniMap::MiniMap(BITMAP* parentScreen,int w, int h)
{
	width = w;
	height = h;
	m_subScreen = create_sub_bitmap(parentScreen,175,300,width ? width : 200,height ? height : 200);
	colors[0] = makecol(0,32,16);
	colors[1] = makecol(0,48,8);
	colors[2] = makecol(0,48,16);
	colors[3] = makecol(0,128,32);
	colors[4] = makecol(0,128,64);
	colors[5] = makecol(0,128,96);
	colors[6] = makecol(0,255,128);
	xScale = (float)width/(float)SCREEN_W;
	yScale = (float)height/(float)SCREEN_H;
};

void MiniMap::draw()
{
	clear_bitmap(m_subScreen);
	rect(m_subScreen,0,0,width-1,height-1,colors[3+rand()%2]);
	//scanlines
	int col = colors[rand()%3];
	for(int i=1; i<height-2; i+=2)
	{
		hline(m_subScreen,1,i,width-2,col);
	}
	circle(m_subScreen,theState()->player.pos.x*xScale,theState()->player.pos.y*yScale,5,colors[3]);
};