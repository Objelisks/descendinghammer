#include <string>
#include <allegro.h>
#include "inputControl.h"

bool GAME_ENDED = false;

void mainKeyCheck()
{
	if(key[KEY_ESC])
	{
		GAME_ENDED = true;
	}
}

void gameKeyCheck()
{
	handleInput();
}

void loop()
{
	mainKeyCheck();
	gameKeyCheck();
	//textprintf_ex(screen,font,50,50,palette_color[2],-1,"%d, %d",SCREEN_W,SCREEN_H);
	/*if(rand()%300 == 0)
	{
		putpixel(screen,mouse_x+(rand()%30-15),mouse_y+(rand()%30-15),rand()%64);
	}*/
	
	//menus

	//draw base cockpit
	//draw dials/switches
	//calculate minimap
	//draw minimap
	//calculate main screen
	//MAIN SCREEN TURN ON
	//ask for input (what is an interrupt)
	//use input
	//update everything
}

int main(void)
{
        allegro_init();
		install_keyboard();
		install_mouse();
		set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,0,0);
		set_color_depth(16);
		//Learn palettes
		show_mouse(screen);

		while(!GAME_ENDED)
		{
			loop();
			
		}

        return 0;
}
END_OF_MAIN()
