//Using SDL and standard IO
#pragma once
//#include <SDL.h>
//#include <SDL_image.h>
#include <stdio.h>
#include <cmath>
//#include "SDL_TTF.h"
//#include "Defines.h"
#include <stack>
#include <memory>
#include <cassert>
#include "MainMenu.h"
#include "Options.h"


//Starts up SDL and creates Window
bool init();

//Screen dimension constants
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 800;



enum gamestates { GameMenu, GamePlay };
enum textquality { solid, shaded, blended };

//Frees media and shuts down SDL
void close();

//The rendering Window
SDL_Window* gWindow = NULL;

//The Surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

SDL_Surface* message = NULL;

SDL_Texture* mTexture;
TTF_Font* loadfont(char* file, int ptsize)
{
	TTF_Font* tmpfont;
	tmpfont = TTF_OpenFont(file, ptsize);
	if (tmpfont == NULL) {
		printf("Unable to load font: %s %s \n", file, TTF_GetError());
		// Handle the error here.
	}
	return tmpfont;
}

//SDL_Surface *drawtext(TTF_Font* fonttodraw, char fgR, char fgG, char fgB, char fgA,
//	char bgR, char bgG, char bgB, char bgA, char text[], textquality quality)
//{
//	SDL_Color tmpfontcolor = { fgR, fgG, fgB, fgA };
//	SDL_Color tmpfontbgcolor = { bgR, bgG, bgB, bgA };
//	SDL_Surface* resulting_text;
//
//	if (quality == solid) {
//		resulting_text = TTF_RenderText_Solid(fonttodraw, text, tmpfontcolor);
//	}
//	else if (quality == shaded) {
//		resulting_text = TTF_RenderText_Shaded(fonttodraw, text, tmpfontcolor, tmpfontbgcolor);
//	}
//	else if (quality == blended) {
//		resulting_text = TTF_RenderText_Blended(fonttodraw, text, tmpfontcolor);
//	}
//
//	return resulting_text;
//}

int main(int argc, char* args[])
{
	gamestates game = GameMenu;

	std::stack<std::unique_ptr<Menu>> menus;

	std::string buttonPressed;

	Menu* m = new MainMenu("mainMenu");
	
	menus.push(std::unique_ptr<Menu>(m));
	//The window we'll be rendering to
	//SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;


	TTF_Init();
	TTF_Font* font = loadfont("C:/windows/fonts/cour.ttf", 72);
	

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
		
		assert(menus.top().get() == m);

		while (!quit)
		{
			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				buttonPressed = "";
				//User requests quit
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				else
				{
					switch (game)
					{
					case GamePlay:
						break;
					case GameMenu:
						//buttonPressed = 
						buttonPressed = menus.top().get()->checkEvents(&e);
						if (menus.top().get()->getName() == "mainMenu")
						{
							if (buttonPressed == "StartGame")
							{

							}
							else if (buttonPressed == "Options")
							{
								m = new Options("Options");
								menus.push(std::unique_ptr<Menu>(m));
							}
							else if (buttonPressed == "Exit")
							{
								quit = true;
							}
							break;
						}
						else if (menus.top().get()->getName() == "Options")
						{
							if (buttonPressed == "Back")
							{
								menus.pop();
							}
						}
						/*if buttonPressed*/

						break;
					}
				}
			}
			//Clear screen
			SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
			SDL_RenderClear(gRenderer);

			switch (game)
			{
			case GamePlay:
				break;
			case GameMenu:
				menus.top().get()->draw(gRenderer);
				break;
			}

			//message = TTF_RenderText_Solid(font, "Test", tmpfontcolor);
			//mTexture = SDL_CreateTextureFromSurface(gRenderer, message);
			//SDL_RenderCopyEx(gRenderer, mTexture, NULL, &renderQuad, NULL, NULL, SDL_FLIP_NONE);
			//Update screen
			SDL_RenderPresent(gRenderer);

		}

		//Destroy window
		SDL_DestroyWindow(gWindow);

		menus.pop();
		//Quit SDL subsystems
		SDL_Quit();

		return 0;
	}
	return 0;
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
		gWindow = SDL_CreateWindow("Connect Four Attempt",  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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
				SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);

				//Initialize PNG loading
				//int imgFlags = IMG_INIT_PNG;
				//if (!(IMG_Init(imgFlags) & imgFlags))
				//{
				//	printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				//	success = false;
				//}
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