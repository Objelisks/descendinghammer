#include "allegro.h"
#include "gameState.h"
#include "inputControl.h"
#include "ctime"
#include "common.h"

//timing code
volatile int frameCounter;

void getFrameRate()
{
	frameRate = frameCounter;
	frameCounter = 0;
};
END_OF_FUNCTION(getFrameRate);

volatile int speed_counter = 0;
void incSpeedCounter()
{
	if(speed_counter < 60)
	{
	speed_counter++;
	}
};
END_OF_FUNCTION(incSpeedCounter)



void mainKeyCheck()
{
	if(key[KEY_ESC])
	{
		theState()->GAME_ENDED = true;
	}
};

void gameKeyCheck()
{
	if(theState()->currentScreen->name == "Menu")
	{
		menuInput();
	}
	else if (theState()->currentScreen->name == "MainScreen")
	{
		handleInput();
	}
};

void logic()
{
	mainKeyCheck();
	gameKeyCheck();
	if(theState()->currentScreen->name == "MainScreen")
	{
		theState()->updateWorld();
		theState()->difficate();
	}

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

void draw()
{
	theState()->currentScreen->draw();
};

int main(void)
{
        allegro_init();
		install_keyboard();
		install_mouse();
		install_timer();
		set_color_depth(16);
		set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,0,0);
		show_mouse(screen);

		//timing code
		LOCK_VARIABLE(speed_counter);
		LOCK_FUNCTION(incSpeedCounter);
		LOCK_FUNCTION(getFrameRate);
		install_int_ex(incSpeedCounter, BPS_TO_TIMER(60));
		install_int_ex(getFrameRate, BPS_TO_TIMER(1));

		theState()->Initialize();

		bool needRedraw = false;
		while(!theState()->GAME_ENDED)
		{
			while(speed_counter > 0) 
			{
				logic();

				speed_counter--;
				needRedraw = true;
			}
			if(needRedraw)
			{
				draw();

				frameCounter++;
				needRedraw = false;
			}
		}

		theState()->Destroy();
        return 0;
};
END_OF_MAIN()
