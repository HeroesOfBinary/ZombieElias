#include "SDL.h" 
#include <stdio.h>
#include <string>
//The window we'll be rendering to
SDL_Window* gWindow = NULL;


//Loads inficidual image
SDL_Surface* loadSurface(std::string path);

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

//The images that correspond to a keypress
SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

//Current displayed Image
SDL_Surface* gCurrentSurface = NULL;

SDL_Surface* loadSurface(std::string path)
{
	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
	}
}

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window 
bool init();
//Loads media  
bool loadMedia(); 
//Frees media and shuts down SDL  
void close();

int main( int argc, char* args[] ) 
{ 
	
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load Media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Apply the image
			SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

			//Update the surface
			SDL_UpdateWindowSurface(gWindow);


			//Main loop flag 
			bool quit = false; 
			//Event handler 
			SDL_Event e;
			
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//user Requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}
				//Apply the image 
				SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
				//Update the surface 
				SDL_UpdateWindowSurface( gWindow );
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}

//Key press surfaces constants 
enum KeyPressSurfaces { 
	KEY_PRESS_SURFACE_DEFAULT, 
	KEY_PRESS_SURFACE_UP, 
	KEY_PRESS_SURFACE_DOWN, 
	KEY_PRESS_SURFACE_LEFT, 
	KEY_PRESS_SURFACE_RIGHT, 
	KEY_PRESS_SURFACE_TOTAL };

bool init()
{
	//initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load Default Surface

	return success;
}

void close()
{
	//eallocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	//Destroy Window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subSystems
	SDL_Quit();
}

