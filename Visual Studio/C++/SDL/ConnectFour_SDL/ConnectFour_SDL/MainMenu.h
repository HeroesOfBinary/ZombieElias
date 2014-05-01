#pragma once
#include "Menu.h"
#include <SDL.h>

class MainMenu : public Menu {
	virtual void draw(){};  /* ... */

		//SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 8, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 6 };
		//SDL_SetRenderDrawColor(gRenderer, 255, 0x00, 0x00, 0xFF);
		//SDL_RenderFillRect(gRenderer, &fillRect);


		//fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 3, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 6 };
		//SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
		//SDL_RenderFillRect(gRenderer, &fillRect);
	
	virtual void checkEvents(SDL_Event e) {};
};