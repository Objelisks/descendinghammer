#include "frontWindow.h"
#include "gameState.h"
#include "common.h"
#include "allegro.h"
#include "world.h"
#include "math.h"
#include "queue"
#include "list"
#include "effect.h"

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
	fovY = 800;
	fovZ = height/2;

	drawOrder = std::priority_queue<DrawableWrapper,std::vector<DrawableWrapper>,DrawableComp>();
};

void FrontWindow::draw()
{
	//clear_bitmap(m_subScreen);

	//Draw booms yo
	for(std::list<Effect>::iterator iter = theState()->effectManager.effects.begin(); iter!= theState()->effectManager.effects.end(); iter++)
	{
		if(iter->pos.y>theState()->player.pos.y-fovY && iter->pos.y<theState()->player.pos.y)
		{
			double s = (iter->pos.y-theState()->player.pos.y+fovY)/fovY;
			int x = (((iter->pos.x-theState()->player.pos.x)*20000/pow((theState()->player.pos.y-iter->pos.y),2))+fovX/2)*(SCREEN_W/fovX);
			int y = (((iter->pos.z-theState()->player.pos.z)*20000/pow((theState()->player.pos.y-iter->pos.y),2))+fovZ/2)*(200/fovZ);
			
			drawOrder.push(DrawableWrapper(x,y,iter->pos.y,s,iter->draw(),-1));
		}
	}

	//Draw bullets and stuf
	for(std::list<Bullet>::iterator iter = theState()->bulletManager.bullets.begin(); iter!= theState()->bulletManager.bullets.end(); iter++)
	{
		if(iter->pos.y>theState()->player.pos.y-fovY && iter->pos.y<theState()->player.pos.y)
		{
			double s = (iter->pos.y-theState()->player.pos.y+fovY)/fovY;
			int x = (((iter->pos.x-theState()->player.pos.x)*20000/pow((theState()->player.pos.y-iter->pos.y),2))+fovX/2)*(SCREEN_W/fovX);
			int y = (((iter->pos.z-theState()->player.pos.z)*20000/pow((theState()->player.pos.y-iter->pos.y),2))+fovZ/2)*(200/fovZ);
			
			int c = colors[std::max<int>(8-s*4,4)];
			drawOrder.push(DrawableWrapper(x,y,iter->pos.y,s,iter->image,c));
			
			/*
			int x = (((iter->pos.x-theState()->player.pos.x)*20000/pow((theState()->player.pos.y-iter->pos.y),2))+fovX/2)*(SCREEN_W/fovX);
			int y = (((iter->pos.z-theState()->player.pos.z)*20000/pow((theState()->player.pos.y-iter->pos.y),2))+fovZ/2)*(200/fovZ);
			int s = (fovY)/(theState()->player.pos.y-iter->pos.y);
			//int s = MIN(MAX((int)(fovY/(theState()->player.pos.y-iter->pos.y)),1),8);
			int c = colors[std::max<int>(8-s/4,4)];
			
			drawOrder.push(DrawableWrapper(x,y,iter->pos.y,s,true,c));
			*/
		}
	}

	//Draw bad dudes
	for(std::list<Enemy>::iterator iter = theState()->enemyManager.enemies.begin(); iter!= theState()->enemyManager.enemies.end(); iter++)
	{
		if(iter->pos.y>theState()->player.pos.y-fovY && iter->pos.y<theState()->player.pos.y)
		{

			//double s = MIN(MAX((int)(fovY*5/(theState()->player.pos.y-iter->pos.y)),1),60);
			double s = (iter->pos.y-theState()->player.pos.y+fovY)/(fovY);

			//int x = fovX/2+((fovX/(theState()->player.pos.x-iter->pos.x+fovX))*(fovX/2));
			//int y = fovZ/2+((fovZ/(theState()->player.pos.z-iter->pos.z+fovZ))*(fovZ/2));
			int x = (((iter->pos.x-theState()->player.pos.x)*20000/pow((theState()->player.pos.y-iter->pos.y),2))+fovX/2)*(SCREEN_W/fovX);
			int y = (((iter->pos.z-theState()->player.pos.z)*20000/pow((theState()->player.pos.y-iter->pos.y),2))+fovZ/2)*(200/fovZ);
			drawOrder.push(DrawableWrapper(x,y,iter->pos.y,s,iter->image,-1));
		}
	}

	while(!drawOrder.empty())
	{
		DrawableWrapper toDraw = drawOrder.top();
		if(toDraw.color == -1)
		{
			stretch_sprite(m_subScreen,toDraw.image,toDraw.x,toDraw.y,toDraw.image->w*toDraw.s,toDraw.image->h*toDraw.s);
		}
		else
		{
			BITMAP* temp = create_bitmap(toDraw.image->w*toDraw.s,toDraw.image->h*toDraw.s);
			clear_to_color(temp,bitmap_mask_color(temp));
			stretch_sprite(temp,toDraw.image,0,0,toDraw.image->w*toDraw.s,toDraw.image->h*toDraw.s);
			set_multiply_blender(getr(toDraw.color),getg(toDraw.color),getb(toDraw.color),255);
			draw_lit_sprite(m_subScreen,temp,toDraw.x,toDraw.y,255);
			destroy_bitmap(temp);
		}
		drawOrder.pop();
	}

	hline(m_subScreen,width/2-2,height/2,width/2+2,makecol(255,255,255));
	vline(m_subScreen,width/2,height/2-2,height/2+2,makecol(255,255,255));
	rect(m_subScreen,0,0,m_subScreen->w-1,m_subScreen->h-1,makecol(255,255,255));
};

