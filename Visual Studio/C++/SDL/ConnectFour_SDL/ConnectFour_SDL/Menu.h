#include "Button.h"
#include <SDL.h>
#pragma once

class Menu
{
public:
	// Common to all menus:
	// (for example)
	virtual void draw() = 0;
	virtual void checkEvents(SDL_Event e) = 0;
	//virtual void onMouseMove(int x, int y) = 0;
	//virtual void onMouseButton(int button, bool is_down) = 0;
	// ... etc.
};
