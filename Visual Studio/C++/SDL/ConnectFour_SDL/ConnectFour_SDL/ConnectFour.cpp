/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>

//Starts up SDL and creates Window
bool init();

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

enum gamestates { GameMenu, GamePlay };

//Frees media and shuts down SDL
void close();

//The rendering Window
SDL_Window* gWindow = NULL;

//The Surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;


int main(int argc, char* args[])
{
	gamestates game = GameMenu;


	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;



	

	//Initialize SDL
	if (!init())
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;
		
		while (!quit)
		{

			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				//User requests quit
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}

				switch (game)
				{
				case GamePlay:
					break;
				case GameMenu:
					break;
				}

				//MessageBox(NULL, "Hello World!", "Test", MB_OK);
				//Get window surface
				screenSurface = SDL_GetWindowSurface(window);
				//MessageBox(NULL, "Hello asd!", "Test", MB_OK);
				//Fill the surface white
				//SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
				//MessageBox(NULL, "Hello etetet!", "Test", MB_OK);
				//Update the surface
				SDL_UpdateWindowSurface(window);
				//MessageBox(NULL, "Hello buttds!", "Test", MB_OK);
				//Wait two seconds
				//SDL_Delay(2000);
			}
		}

		//Destroy window
		SDL_DestroyWindow(window);

		//Quit SDL subsystems
		SDL_Quit();

		return 0;
	}
}




bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}


		//Create Window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//get Window Surface
			//gScreenSurface = SDL_GetWindowSurface(gWindow);
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}

		}
	}

	return success;
}
	


//
//
//void close()
//{
//	//Deallocate surfaces
//	for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i)
//	{
//		SDL_FreeSurface(gKeyPressSurfaces[i]);
//		gKeyPressSurfaces[i] = NULL;
//	}
//
//	//Destroy window
//	SDL_DestroyWindow(gWindow);
//	gWindow = NULL;
//
//	//Quit SDL subsystems
//	SDL_Quit();
//}