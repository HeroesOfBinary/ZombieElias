#include "Tile.h"


Tile::Tile(int elevationIn, int terrainDifficultyIn, int heightIn, int widthIn, int xPositionIn, int yPositionIn)
{
	elevation = elevationIn;
	terrainDifficulty = terrainDifficultyIn;
	height = heightIn;
	width = widthIn;

	red = rand() % 254;
	green =  rand() % 254;
	blue = rand() % 254;

	tile = { xPositionIn, yPositionIn, widthIn, heightIn };
}

void Tile::draw(SDL_Renderer* gRenderer, double zoom)
{
	SDL_Rect rectToDraw = tile; 

	
	SDL_SetRenderDrawColor(gRenderer, red, green, blue, 255);

	//SDL_RenderDrawRect(gRenderer, &rectToDraw);
		
	SDL_RenderFillRect(gRenderer, &rectToDraw);
}

Tile::~Tile()
{
}
 