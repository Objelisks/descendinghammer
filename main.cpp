#include "allegro.h"
#include "gameState.h"
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
	theState->currentScreen.draw();
	
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

		//INITIALIZE ULTRA STATE
		theState = &GameState();

		while(!GAME_ENDED)
		{
			loop();
			
		}

        return 0;
}
END_OF_MAIN()
