#include "allegro.h"
#include "gameState.h"
#include "inputControl.h"
#include "ctime"
#include "string"
#include "sstream"

bool GAME_ENDED = false;

std::string toString(int i)
{
std::string s;
std::stringstream out;
out << i;
s = out.str();
return s;
};

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
	theState.currentScreen.draw();
	
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
		install_keyboard();
		install_mouse();
		set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,0,0);
		set_color_depth(16);
		//Learn palettes
		show_mouse(screen);

		//INITIALIZE ULTRA STATE
		theState = GameState();

		int frames = 0;
		clock_t begin = clock();
		while(!GAME_ENDED)
		{
			loop();
			frames++;
			textout_ex(screen,font,toString(frames/((clock()-begin+1)/CLOCKS_PER_SEC+1)).c_str(),20,20,1,0);
			textout_ex(screen,font,toString(frames).c_str(),20,50,1,0);
		}

        return 0;
};
END_OF_MAIN()
