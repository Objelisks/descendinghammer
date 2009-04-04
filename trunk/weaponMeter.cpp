#include "weaponMeter.h"
#include "gameState.h"
#include "vector"
#include "allegro.h"

WeaponVisual::WeaponVisual(std::string n, int* cool, int coolMax, RLE_SPRITE* img)
{
	name = n;
	cooldown = cool;
	cooldownMax = coolMax;
	image = img;
};

WeaponMeter::WeaponMeter(BITMAP *parentScreen, int x, int y)
{
	weapons = std::vector<WeaponVisual>();
	for(boost::ptr_vector<Weapon>::iterator iter=theState()->player.weapons.begin(); iter != theState()->player.weapons.end(); iter++)
	{
		weapons.insert(weapons.end(),WeaponVisual(iter->name,&iter->cooldown, iter->cooldownMax, get_rle_sprite(theState()->resources.images[iter->name.c_str()])));
	}
	m_subScreen = create_sub_bitmap(parentScreen,x,y,150,50*weapons.size());
};

void WeaponMeter::draw()
{
	for(std::vector<WeaponVisual>::iterator iter=weapons.begin(); iter != weapons.end(); iter++)
	{
		int pos = iter-weapons.begin();
		draw_rle_sprite(m_subScreen, iter->image, 15, 5+50*pos);
		textout_ex(m_subScreen, font, iter->name.c_str(), 35, 15+50*pos, makecol(255,255,255), -1);
		rect(m_subScreen, 25, 30+50*pos, 95, 38+50*pos, makecol(150,150,150));
		rectfill(m_subScreen, 26, 31+50*pos, 26+((double)*iter->cooldown/(double)iter->cooldownMax)*69, 37+50*pos, makecol(200,20,0));
		if(theState()->player.currentWeapon == pos)
		{
			rectfill(m_subScreen, 5, 25+50*pos, 9, 33+50*pos, makecol(200, 200, 20));
		}
	}
};