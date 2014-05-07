#include "Button.cpp"
#include <SDL.h>
#pragma once

class Menu
{
public:
	// Common to all menus:
	// (for example)
	virtual void draw(SDL_Renderer* gRenderer) {};
	virtual void checkEvents(SDL_Event e) {};
	//virtual void onMouseMove(int x, int y) = 0;
	//virtual void onMouseButton(int button, bool is_down) = 0;
	// ... etc.
};
