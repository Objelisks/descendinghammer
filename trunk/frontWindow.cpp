#include "frontWindow.h"
#include "gameState.h"
#include "allegro.h"
#include "world.h"


FrontWindow::FrontWindow(BITMAP* parentScreen)
{
	FrontWindow(parentScreen,SCREEN_W,200);
};

FrontWindow::FrontWindow(BITMAP* parentScreen, int w, int h)
{
	width = w;
	height = h;
	m_subScreen = create_sub_bitmap(parentScreen,0,50,width ? width : SCREEN_W,height ? height : 200);

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

	fovX = width/2;
	fovY = 1000;
	fovZ = height/2;
};

void FrontWindow::draw()
{
	clear_bitmap(m_subScreen);

	rect(m_subScreen,0,0,m_subScreen->w-1,m_subScreen->h-1,makecol(255,255,255));

	//Draw bullets and stuf
	for(std::list<Bullet>::iterator iter = theState()->bulletManager->bullets.begin(); iter!= theState()->bulletManager->bullets.end(); iter++)
	{
		for(int i=0; i<iter->trail; i++)
		{
			putpixel(m_subScreen,iter->pos.x+iter->xMove*i/iter->speed,iter->pos.y+iter->yMove*i/iter->speed,colors[std::max<int>(8-(i*rand()%5),4)]);
		}
	}

	//Draw bad dudes
	for(std::list<Enemy>::iterator iter = theState()->enemyManager->enemies.begin(); iter!= theState()->enemyManager->enemies.end(); iter++)
	{
		if(iter->pos.y>theState()->player.pos.y-fovY && iter->pos.y<theState()->player.pos.y)
		{
		if(iter->pos.x>theState()->player.pos.x-fovX && iter->pos.x<theState()->player.pos.x+fovX)
		{
		if(iter->pos.z>theState()->player.pos.z-fovZ && iter->pos.z<theState()->player.pos.z+fovZ)
		{
			circle(m_subScreen,(iter->pos.x-theState()->player.pos.x)*(SCREEN_W/fovX),(iter->pos.z-theState()->player.pos.z)*(200/fovZ),MIN(MAX((int)(fovY/(theState()->player.pos.y-iter->pos.y)),1),50),colors[8]);
		}
		}
		}
	}
};

