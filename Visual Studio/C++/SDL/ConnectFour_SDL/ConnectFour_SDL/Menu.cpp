#include <SDL.h>
#pragma once

class Menu 
{
	virtual void draw() = 0;
	virtual void checkEvents(SDL_Event e) = 0;
};
