#include "SDL.h"
#include <stdio.h>
#include <string>

//Loads Infividual Image As Texture
SDL_Texture* loadTexture(std::string path);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The Window Renderer
SDL_Renderer* gRenderer = NULL;

//Current Displayed Texture
SDL_Texture* gTexture = NULL;

const int SCREEN_WIDTH = 640;

const int SCREEN_HEIGHT = 480;
int main(int argc, char* args[])
{
	//Create Window
	gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (gWindow == NULL)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
}

