#pragma once
#include "Button.h"


class Menu
{
public:
	Menu();
	~Menu();

	virtual void draw(SDL_Renderer* gRenderer);
	virtual void checkEvents(SDL_Event* e);
};
