#pragma once
#include "Button.h"


class Menu
{
public:
	Menu();
	~Menu();

	virtual void draw(SDL_Renderer* gRenderer) = 0;
	virtual void checkEvents(SDL_Event* e) = 0;
};
