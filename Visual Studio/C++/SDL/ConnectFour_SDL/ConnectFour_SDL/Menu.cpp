#include "Menu.h"
#include <SDL.h>
#pragma once

class Menu
{
	Menu(){};

	virtual void draw(SDL_Renderer* gRenderer)
	{
	};
	virtual void checkEvents(SDL_Event e)
	{

	};
};
