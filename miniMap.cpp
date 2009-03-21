#include "miniMap.h"
#include "allegro.h"
#include "gameState.h"
#include "vector"

MiniMap::MiniMap(BITMAP* parentScreen)
{
	MiniMap(parentScreen,300,200);
};

MiniMap::MiniMap(BITMAP* parentScreen,int w, int h)
{
	width = w;
	height = h;
	m_subScreen = create_sub_bitmap(parentScreen,175,300,width ? width : 200,height ? height : 200);

	//scanline colors
	colors[0] = makecol(0,32,16);
	colors[1] = makecol(0,48,8);
	colors[2] = makecol(0,48,16);

	colors[3] = makecol(0,128,16);

	//bullet colors
	colors[4] = makecol(250,201,58);
	colors[5] = makecol(255,174,46);
	colors[6] = makecol(245,119,18);
	colors[7] = makecol(255,82,21);
	colors[8] = makecol(250,19,0);
	xScale = (float)width/(float)1000;
	yScale = (float)height/(float)1000;
};

void MiniMap::draw()
{
	clear_bitmap(m_subScreen);

	//scanlines
	int col = colors[rand()%3];
	for(int i=1; i<height-2; i+=2)
	{
		hline(m_subScreen,1,i,width-2,col);
	}

	//Draw awesome dude
	circle(m_subScreen,theState()->player.pos.x*xScale,theState()->player.pos.y*yScale,5,colors[3]);
	
	//Draw bullets and stuf
	for(std::list<Bullet>::iterator iter = theState()->bulletManager->bullets.begin(); iter!= theState()->bulletManager->bullets.end(); iter++)
	{
		for(int i=0; i<iter->trail; i++)
		{
			putpixel(m_subScreen,iter->pos.x*xScale+iter->xMove*i/iter->speed,iter->pos.y*yScale+iter->yMove*i/iter->speed,colors[std::max<int>(8-(i*rand()%5),4)]);
		}
	}

	//Draw bad dudes
	for(std::list<Enemy>::iterator iter = theState()->enemyManager->enemies.begin(); iter!= theState()->enemyManager->enemies.end(); iter++)
	{
		circle(m_subScreen,iter->pos.x*xScale,iter->pos.y*yScale,3,colors[8]);
	}

	rect(m_subScreen,0,0,width-1,height-1,colors[2+rand()%2]);
};