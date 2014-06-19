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
LTexture gSpriteSheetTexture;

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
	int xPosition;
	int yPosition;
	int ySpeed;
	int xSpeed;
	int maxSpeed;
	int counter;
	counter = 0;
	maxSpeed = 10;
	int frames = 60;

	ySpeed = 0;
	xSpeed = 0;

	//Event handler
	SDL_Event e;

	//SDL_Rect right;
	//right.x = 5;
	//right.y = 3;
	//right.w = 60;
	//right.h = 62;

	//SDL_Rect left;
	//left.x = 63;
	//left.y = 3;
	//left.w = 60;
	//left.h = 62;

	//SDL_Rect up;
	//up.x = 139;
	//up.y = 3;
	//up.w = 62;
	//up.h = 56;

	//SDL_Rect down;
	//down.x = 204;
	//down.y = 3;
	//down.w = 62;
	//down.h = 56;
	//
	//gSpriteClips.push_back(left);
	//gSpriteClips.push_back(up);
	//gSpriteClips.push_back(right);
	//gSpriteClips.push_back(down);	


	SDL_Rect* currentClip;
	SDL_Rect Plane;
	int spritePosX;
	int spritePosY;
	spritePosX = 0;
	spritePosY = 0;
	int i, y;
	y = 0;
	i = 0;
	while (y < 4)
	{
		while (i < 8)
		{

			Plane.x = spritePosX + (i * 70);
			Plane.y = spritePosY + (y * 70);
			Plane.w = 70;
			Plane.h = 70;
			gSpriteClips.push_back(Plane);
			i = i + 1;
		}
		y = y + 1;
		i = 0;
	}
	




	//SDL_Rect destination;
	//destination.x = 100;
	//destination.y = 100;
	//destination.w = 65;
	//destination.h = 44;

	xPosition = (SCREEN_WIDTH - 70) / 2;
	yPosition = (SCREEN_HEIGHT - 70) / 2;
	//Initialize SDL
	if (!init())
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{

		while (!quit)
		{
			gSpriteSheetTexture.loadFromFile("Fighter.bmp", gRenderer);

			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				else
				{
					switch (e.key.keysym.sym) 
					{
						case SDLK_LEFT:
							if (currentThing == 0)
							{
								currentThing = 31;
							}
							else
							{
								currentThing = currentThing - 1;
							}
							//currentThing = 0;
							break;
						case SDLK_UP:
							currentThing = 1;
							break;
						case SDLK_RIGHT:
							if (currentThing == 31)
							{
								currentThing = 0;
							}
							else
							{
								currentThing = currentThing + 1;
							}
							break;
						case SDLK_DOWN:
							if (currentThing == 0)
							{
								if (xSpeed - 5 > -maxSpeed)
								{
									xSpeed = xSpeed - 5;
								}
								else 
								{
									xSpeed = -maxSpeed;
								}

							/*	if (abs(ySpeed) < 10)
								{
									ySpeed = ySpeed - 1;
								}*/
							}
							else if (currentThing == 1)
							{
								if (xSpeed - 5 > -maxSpeed)
								{
									xSpeed = xSpeed - 5;
								}
								else
								{
									xSpeed = -maxSpeed;
								}

								if (ySpeed - 1 > -maxSpeed)
								{
									ySpeed = ySpeed - 1;
								}
								else
								{
									ySpeed = -maxSpeed;
								}
							}
							else if (currentThing == 2)
							{
								if (xSpeed - 4 > -maxSpeed)
								{
									xSpeed = xSpeed - 4;
								}
								else
								{
									xSpeed = -maxSpeed;
								}

								if (ySpeed - 2 > -maxSpeed)
								{
									ySpeed = ySpeed - 2;
								}
								else
								{
									ySpeed = -maxSpeed;
								}
							}
							else if (currentThing == 3)
							{
								if (xSpeed - 3 > -maxSpeed)
								{
									xSpeed = xSpeed - 3;
								}
								else
								{
									xSpeed = -maxSpeed;
								}

								if (ySpeed - 3 > -maxSpeed)
								{
									ySpeed = ySpeed - 3;
								}
								else
								{
									ySpeed = -maxSpeed;
								}
							}
							else if (currentThing == 4)
							{
								if (xSpeed - 2 > -maxSpeed)
								{
									xSpeed = xSpeed - 2;
								}
								else
								{
									xSpeed = -maxSpeed;
								}

								if (ySpeed - 4 > -maxSpeed)
								{
									ySpeed = ySpeed - 4;								}
								else
								{
									ySpeed = -maxSpeed;
								}
							}
							else if (currentThing == 5)
							{
								if (xSpeed - 2 > -maxSpeed)
								{
									xSpeed = xSpeed - 2;
								}
								else
								{
									xSpeed = -maxSpeed;
								}

								if (ySpeed - 4 > -maxSpeed)
								{
									ySpeed = ySpeed - 4;
								}
								else
								{
									ySpeed = -maxSpeed;
								}
							}
							else if (currentThing == 6)
							{
								if (xSpeed - 1 > -maxSpeed)
								{
									xSpeed = xSpeed - 1;
								}
								else
								{
									xSpeed = -maxSpeed;
								}

								if (ySpeed - 5 > -maxSpeed)
								{
									ySpeed = ySpeed - 5;
								}
								else
								{
									ySpeed = -maxSpeed;
								}
							}
							else if (currentThing == 7)
							{
								if (xSpeed - 1 > -maxSpeed)
								{
									xSpeed = xSpeed - 1;
								}
								else
								{
									xSpeed = -maxSpeed;
								}

								if (ySpeed - 5 > -maxSpeed)
								{
									ySpeed = ySpeed - 5;
								}
								else
								{
									ySpeed = -maxSpeed;
								}
							}
							else if (currentThing == 8)
							{
								if (ySpeed - 5 > -maxSpeed)
								{
									ySpeed = ySpeed - 5;
								}
								else
								{
									ySpeed = -maxSpeed;
								}
							}
							else if (currentThing == 9)
							{
								if (xSpeed + 1 > maxSpeed)
								{
									xSpeed = xSpeed + 1;
								}
								else
								{
									xSpeed = maxSpeed;
								}

								if (ySpeed - 5 > -maxSpeed)
								{
									ySpeed = ySpeed - 5;
								}
								else
								{
									ySpeed = -maxSpeed;
								}
							}
							else if (currentThing == 10)
							{
								if (xSpeed + 2 > maxSpeed)
								{
									xSpeed = xSpeed + 2;
								}
								else
								{
									xSpeed = maxSpeed;
								}

								if (ySpeed - 4 > -maxSpeed)
								{
									ySpeed = ySpeed - 4;
								}
								else
								{
									ySpeed = -maxSpeed;
								}
							}
							else if (currentThing == 11)
							{
								if (xSpeed + 2 > maxSpeed)
								{
									xSpeed = xSpeed + 2;
								}
								else
								{
									xSpeed = maxSpeed;
								}

								if (ySpeed - 3 > -maxSpeed)
								{
									ySpeed = ySpeed - 3;
								}
								else
								{
									ySpeed = -maxSpeed;
								}
							}
							else if (currentThing == 12)
							{
								if (xSpeed + 3 > maxSpeed)
								{
									xSpeed = xSpeed + 3;
								}
								else
								{
									xSpeed = maxSpeed;
								}

								if (ySpeed - 3 > -maxSpeed)
								{
									ySpeed = ySpeed - 3;
								}
								else
								{
									ySpeed = -maxSpeed;
								}
							}
							else if (currentThing == 13)
							{
								if (xSpeed + 4 > maxSpeed)
								{
									xSpeed = xSpeed + 4;
								}
								else
								{
									xSpeed = maxSpeed;
								}

								if (ySpeed - 2 > -maxSpeed)
								{
									ySpeed = ySpeed - 2;
								}
								else
								{
									ySpeed = -maxSpeed;
								}
							}
							else if (currentThing == 14)
							{
								if (xSpeed + 5 > maxSpeed)
								{
									xSpeed = xSpeed + 5;
								}
								else
								{
									xSpeed = maxSpeed;
								}

								if (ySpeed - 1 > -maxSpeed)
								{
									ySpeed = ySpeed - 1;
								}
								else
								{
									ySpeed = -maxSpeed;
								}
							}
							else if (currentThing == 15)
							{
								if (xSpeed + 5 > maxSpeed)
								{
									xSpeed = xSpeed + 5;
								}
								else
								{
									xSpeed = maxSpeed;
								}
								if (ySpeed - 1 > -maxSpeed)
								{
									ySpeed = ySpeed - 1;
								}
								else
								{
									ySpeed = -maxSpeed;
								}
							}
							else if (currentThing == 16)
							{
								if (xSpeed + 5 > maxSpeed)
								{
									xSpeed = xSpeed + 5;
								}
								else
								{
									xSpeed = maxSpeed;
								}

							}
							else if (currentThing == 17)
							{
								if (xSpeed + 5 > maxSpeed)
								{
									xSpeed = xSpeed + 5;
								}
								else
								{
									xSpeed = maxSpeed;
								}
								if (ySpeed + 1 > maxSpeed)
								{
									ySpeed = ySpeed + 1;
								}
								else
								{
									ySpeed = maxSpeed;
								}
							}
							else if (currentThing == 18)
							{
								if (xSpeed + 4 < maxSpeed)
								{
									xSpeed = xSpeed + 4;
								}
								else
								{
									xSpeed = maxSpeed;
								}
								if (ySpeed + 1 > maxSpeed)
								{
									ySpeed = ySpeed + 1;
								}
								else
								{
									ySpeed = maxSpeed;
								}
							}
							else if (currentThing == 19)
							{
								if (xSpeed + 3 > maxSpeed)
								{
									xSpeed = xSpeed + 3;
								}
								else
								{
									xSpeed = maxSpeed;
								}
								if (ySpeed + 3 > maxSpeed)								{
									ySpeed = ySpeed + 3;
								}
								else
								{
									ySpeed = maxSpeed;
								}
							}
							else if (currentThing == 20)
							{
								if (xSpeed + 3 > maxSpeed)
								{
									xSpeed = xSpeed + 3;
								}
								else
								{
									xSpeed = maxSpeed;
								}
								if (ySpeed + 3 > maxSpeed)								{
									ySpeed = ySpeed + 3;
								}
								else
								{
									ySpeed = maxSpeed;
								}
							}
							else if (currentThing == 21)
							{
								if (xSpeed + 2 > maxSpeed)
								{
									xSpeed = xSpeed + 2;
								}
								else
								{
									xSpeed = maxSpeed;
								}


								if (ySpeed + 3> maxSpeed)								{
									ySpeed = ySpeed + 3;
								}
								else
								{
									ySpeed = maxSpeed;
								}
							}
							else if (currentThing == 22)
							{
								if (xSpeed + 1 > -maxSpeed)
								{
									xSpeed = xSpeed + 1;
								}
								else
								{
									xSpeed = -maxSpeed;
								}
								if (ySpeed + 4 > maxSpeed)								{
									ySpeed = ySpeed + 4;
								}
								else
								{
									ySpeed = maxSpeed;
								}
							}
							else if (currentThing == 23)
							{
								if (xSpeed + 1 > -maxSpeed)
								{
									xSpeed = xSpeed + 1;
								}
								else
								{
									xSpeed = maxSpeed;
								}
								if (ySpeed + 4 > maxSpeed)								{
									ySpeed = ySpeed + 4;
								}
								else
								{
									ySpeed = maxSpeed;
								}
							}
							else if (currentThing == 24)
							{
								
								if (ySpeed + 5 > maxSpeed)								{
									ySpeed = ySpeed + 5;
								}
								else
								{
									ySpeed = maxSpeed;
								}
							}
							else if (currentThing == 25)
							{
								if (xSpeed - 1 > -maxSpeed)
								{
									xSpeed = xSpeed - 1;
								}
								else
								{
									xSpeed = -maxSpeed;
								}
								if (ySpeed + 4 > maxSpeed)								{
									ySpeed = ySpeed + 4;
								}
								else
								{
									ySpeed = maxSpeed;
								}
							}
							else if (currentThing == 26)
							{
								if (xSpeed - 2 > -maxSpeed)
								{
									xSpeed = xSpeed - 2;
								}
								else
								{
									xSpeed = maxSpeed;
								}
								if (ySpeed + 4 > maxSpeed)								{
									ySpeed = ySpeed + 4;
								}
								else
								{
									ySpeed = maxSpeed;
								}
							}
							else if (currentThing == 27)
							{
								if (xSpeed - 2 > -maxSpeed)
								{
									xSpeed = xSpeed - 2;
								}
								else
								{
									xSpeed = maxSpeed;
								}
								if (ySpeed + 3 > maxSpeed)								{
									ySpeed = ySpeed + 3;
								}
								else
								{
									ySpeed = maxSpeed;
								}
							}
							else if (currentThing == 28)
							{
								if (xSpeed - 3 > -maxSpeed)
								{
									xSpeed = xSpeed - 3;
								}
								else
								{
									xSpeed = maxSpeed;
								}
								if (ySpeed + 3 > maxSpeed)								{
									ySpeed = ySpeed + 3;
								}
								else
								{
									ySpeed = maxSpeed;
								}
							}
							else if (currentThing == 29)
							{
								if (xSpeed - 3 > -maxSpeed)
								{
									xSpeed = xSpeed - 3;
								}
								else
								{
									xSpeed = maxSpeed;
								}
								if (ySpeed + 2 > maxSpeed)								{
									ySpeed = ySpeed + 2;
								}
								else
								{
									ySpeed = maxSpeed;
								}
							}
							else if (currentThing == 30)
							{
								if (xSpeed - 4 > -maxSpeed)
								{
									xSpeed = xSpeed - 4;
								}
								else
								{
									xSpeed = maxSpeed;
								}
								if (ySpeed + 1 > maxSpeed)								{
									ySpeed = ySpeed + 1;
								}
								else
								{
									ySpeed = maxSpeed;
								}
							}
							else if (currentThing == 31)
							{
								if (xSpeed - 4 > -maxSpeed)
								{
									xSpeed = xSpeed - 4;
								}
								else
								{
									xSpeed = maxSpeed;
								}
								if (ySpeed + 4 > maxSpeed)								{
									ySpeed = ySpeed + 4;
								}
								else
								{
									ySpeed = maxSpeed;
								}
							}
							break;
					}
				}

			}

			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(gRenderer);
			xPosition = xPosition + xSpeed;
			yPosition = yPosition + ySpeed;
			currentClip = &gSpriteClips[currentThing];
			
			if (xPosition > SCREEN_WIDTH)
			{
				xPosition = 0;
			}
			else if (xPosition + 70 > SCREEN_WIDTH)
			{
				gSpriteSheetTexture.render(0 - (xPosition - SCREEN_WIDTH + 70), yPosition, currentClip, gRenderer);
			}
			else if (xPosition < 0)
			{ 
				if (xPosition + 70 < 0)
				{
					xPosition = xPosition + SCREEN_WIDTH;
				}
				else
				{
					gSpriteSheetTexture.render((xPosition + SCREEN_WIDTH), yPosition, currentClip, gRenderer);
				}
			}

			if (yPosition > SCREEN_HEIGHT)
			{
				yPosition = 0;
			}
			else if (yPosition + 70 > SCREEN_HEIGHT)
			{
				gSpriteSheetTexture.render(xPosition, 0 - yPosition - SCREEN_HEIGHT + 70 , currentClip, gRenderer);
			}
			else if (yPosition < 0)
			{
				if (yPosition + 70 < 0)
				{
					yPosition = yPosition + SCREEN_HEIGHT;
				}
				else
				{
					gSpriteSheetTexture.render(xPosition, yPosition + SCREEN_HEIGHT, currentClip, gRenderer);
				}
			}

			gSpriteSheetTexture.render(xPosition, yPosition, currentClip, gRenderer);
			

			SDL_RenderPresent(gRenderer);

		}
	}
	close();

	return 0;



}
