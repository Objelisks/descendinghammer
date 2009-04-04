#include "indicator.h"
#include "allegro.h"
#include "gameState.h"
#include "cmath"
#include "common.h"

void Indicator::draw()
{
	switch(type)
	{
	case IND_METER:
		draw_rle_sprite(m_subScreen,image,0,0);
		line(m_subScreen,image->w/2,image->h/2,(image->w/3)*cos(((float)*value)*2*PI/180-4)+image->w/2,(image->h/3)*sin(((float)*value)*2*PI/180-4)+image->h/2,makecol(0,0,0));
		break;
	case IND_LIGHT:
		if(*value)
		{
			set_multiply_blender(255,0,0,255);
			draw_lit_rle_sprite(m_subScreen,image,0,0,255);
			set_multiply_blender(255,255,255,255);
		}
		else
		{
			draw_rle_sprite(m_subScreen,image,0,0);
		}
		break;
	}
};

Indicator::Indicator(BITMAP* parentScreen, BITMAP* img, IndicatorType _type, int* _value,int x,int y)
{
	type = _type;
	value = _value;
	switch(type)
	{
	case IND_METER:
		image = get_rle_sprite(img);
		break;
	case IND_LIGHT:
		image = get_rle_sprite(img);
		break;
	}
	if(image)
	{
		m_subScreen = create_sub_bitmap(parentScreen,x,y,image->w,image->h);
	}
};