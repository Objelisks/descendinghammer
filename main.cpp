#include "allegro.h"
#include "gameState.h"
#include "inputControl.h"
#include "ctime"
#include "common.h"

bool GAME_ENDED = false;

void mainKeyCheck()
{
	if(key[KEY_ESC])
	{
		GAME_ENDED = true;
	}
};

void gameKeyCheck()
{
	handleInput();
};

void loop()
{
	mainKeyCheck();
	gameKeyCheck();
	theState()->currentScreen->draw();
	
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
};

int main(void)
{
        allegro_init();
		int erra = install_keyboard();
		if(erra != 0)
		{
			allegro_message("ohshi");
		}
		install_mouse();
		set_color_depth(16);
		set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,0,0);
		show_mouse(screen);

		//INITIALIZE ULTRA STATE


		int frames = 0;
		clock_t begin = clock();
		while(!GAME_ENDED)
		{
			loop();
			frames++;
			textout_ex(screen,font,"fps:",5,20,makecol(255,255,255),0);
			textout_ex(screen,font,toString(frames/((clock()-begin+1)/CLOCKS_PER_SEC+1)).c_str(),40,20,makecol(255,255,255),0);
		}

        return 0;
};
END_OF_MAIN()
