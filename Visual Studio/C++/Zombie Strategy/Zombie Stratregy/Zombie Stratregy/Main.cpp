#pragma once
#include "PreCompile.h"
#include "Map.h"
#include "Timer.h"
#include "LTexture.h"


/*
Resouces

//	http://www.gamedev.net/topic/452938-sdl-multiple-key-press-events/


*/

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

const int SCREEN_WIDTH = 1366;
const int SCREEN_HEIGHT = 768;
bool keysHeld[323] = { false }; //Initialize keystates with null

//The frames per second 
const int SCREEN_FPS = 120;
const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;

//Globally used font
TTF_Font* gFont = NULL;

//Scene textures
LTexture gFPSTextTexture;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("Zombie Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);

				//Initialize PNG loading
			/*	int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}*/

				//Initialize SDL_ttf
				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					success = false;
				}

				////Initialize PNG loading
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

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Open the font
	gFont = TTF_OpenFont("C:/windows/fonts/cour.ttf", 28);
	if (gFont == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}

	return success;
}

int main(int argc, char* args[])
{

	//Keep track of the current frame
	int frame = 0;

	//Setup Close variable
	bool quit = false;

	//Create The Map And Tile Objects
	Map levelMap(32, 32, 2048, 1536, 1024, 768);
	//Map levelMap(32, 32, 64, 64, 1024, 768);

	//Set text color as black
	SDL_Color textColor = { 0, 0, 0, 255 };

	SDL_Event e;

	if (!init())
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		if (!loadMedia())
		{
			quit = true;
		}
		//The frames per second timer
		Timer fpsTimer;

		//The frames per second cap timer
		Timer capTimer;

		//In memory text stream
			std::stringstream timeText;

		//Start counting frames per second
		int countedFrames = 0;
		fpsTimer.start();

		while (!quit)
		{
			//Start cap timer
			capTimer.start();

			if (SDL_PollEvent(&e) != 0)
			{

				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				else if (e.type == SDL_WINDOWEVENT)
				{

					if (e.window.event == SDL_WINDOWEVENT_ENTER)
					{

					}
					else if (e.window.event == SDL_WINDOWEVENT_LEAVE)
					{

					}
				}
				else 
				{
					levelMap.handleEvent(e);
				}
			}


			float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
			if (avgFPS > 2000000)
			{
				avgFPS = 0;
			}


			//Set text to be rendered
			timeText.str("");
			timeText << "Average Frames Per Second (With Cap) " << avgFPS;

			//Load Render text
			if (!gFPSTextTexture.loadFromRenderedText(timeText.str().c_str(), textColor, gFont, gRenderer))
			{
				printf("Unable to render FPS texture!\n");
			}


			//Clear Screen
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(gRenderer);

			//Draw Map
			levelMap.draw(gRenderer);

			//Render textures
			//gFPSTextTexture.render((SCREEN_WIDTH - gFPSTextTexture.getWidth()) / 2, (SCREEN_HEIGHT - gFPSTextTexture.getHeight()) / 2, gRenderer);
			gFPSTextTexture.render(100, 100, gRenderer);
			SDL_RenderPresent(gRenderer);

			++countedFrames;

			//If frame finished early
			int frameTicks = capTimer.getTicks();
			if (frameTicks < SCREEN_TICK_PER_FRAME)
			{
				//Wait remaining time
				SDL_Delay(SCREEN_TICK_PER_FRAME - frameTicks);
			}

		}
	}

	return 0;
}
