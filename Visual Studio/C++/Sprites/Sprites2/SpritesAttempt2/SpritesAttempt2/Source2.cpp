#include "LTexture.h"
#include <vector>

//Screen dimension constants
const int SCREEN_WIDTH = 1366;
const int SCREEN_HEIGHT = 768;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

std::vector<SDL_Rect> gSpriteClips;
//LTexture gSpriteSheetTexture;

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
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

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

void close()
{
	//Free loaded images
	//gSpriteSheetTexture.free();

	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	//IMG_Quit();
	SDL_Quit();
}


int main(int argc, char* args[])
{
	int currentThing;
	currentThing = 0;
	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	SDL_Rect right;
	right.x = 6;
	right.y = 6;
	right.w = 56;
	right.h = 58;


	SDL_Rect left;
	left.x = 7;
	left.y = 145;
	left.w = 56;
	left.h = 58;

	SDL_Rect up;
	left.x = 3;
	left.y = 73;
	left.w = 68;
	left.h = 60;

	SDL_Rect down;
	left.x = 5;
	left.y = 216;
	left.w = 60;
	left.h = 61;

	gSpriteClips.push_back(left);
	gSpriteClips.push_back(up);
	gSpriteClips.push_back(right);
	gSpriteClips.push_back(down);

	SDL_Rect destination;
	destination.x = 100;
	destination.y = 100;
	destination.w = 65;
	destination.h = 44;


	//Initialize SDL
	if (!init())
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{

		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				else
				{
					switch (e.key.keysym.sym) {
					case SDLK_LEFT:
						currentThing = 0;
						break;
					case SDLK_UP:
						currentThing = 1;
						break;
					case SDLK_RIGHT:
						currentThing = 2;
						break;
					case SDLK_DOWN:
						currentThing = 3;
						break;
					}
				}

			}

			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(gRenderer);


			SDL_Rect* currentClip = &gSpriteClips[currentThing];
			//gSpriteSheetTexture.render((SCREEN_WIDTH - currentClip->w) / 2, (SCREEN_HEIGHT - currentClip->h) / 2, currentClip, gRenderer);

			SDL_RenderPresent(gRenderer);



		}
	}
	close();

	return 0;



}
