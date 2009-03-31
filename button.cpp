#include "button.h"
#include "allegro.h"
#include "gameState.h"

void Button::draw()
{

};

Button::Button(BITMAP* parentScreen, ButtonType _type)
{
	m_subScreen = parentScreen;
	type = _type;
};