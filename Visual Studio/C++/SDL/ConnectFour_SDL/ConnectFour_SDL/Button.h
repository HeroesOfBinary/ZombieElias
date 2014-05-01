#include <SDL.h>
#pragma once

class Button
{
public:
	// Common to all menus:
	// (for example)
	virtual void draw() = 0;
	virtual void checkEvents(SDL_Event e) = 0;
	virtual void setBaseColor(int red, int green, int blue, int opacity);
	virtual void setUpColor(int red, int green, int blue, int opacity);
	virtual void setDownColor(int red, int green, int blue, int opacity);

	// ... etc.
};