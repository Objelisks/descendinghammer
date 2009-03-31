#ifndef _button_inc
#define _button_inc

#include "allegro.h"
#include "subScreen.h"

enum ButtonType {BTN_LIGHT,BTN_SWITCH,BTN_KNOB,BTN_BIGRED};

class Button : public SubScreen
{
public:
	Button(BITMAP* parentScreen, ButtonType _type);
	int value;
	ButtonType type;
	void draw();
};

#endif