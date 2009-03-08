#include "miniMap.h"
#include "allegro.h"
#include "gameState.h"

MiniMap::MiniMap(BITMAP* parentScreen)
{
	MiniMap::m_subScreen = create_sub_bitmap(parentScreen,100,200,200,200);
};

void MiniMap::draw()
{
	circle(m_subScreen,theState.player.pos.x,theState.player.pos.y,5,makecol(0,128,32));
};