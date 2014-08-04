#include "Tile.h"


Tile::Tile(int elevationIn, int terrainDifficultyIn, int heightIn, int widthIn, int xPositionIn, int yPositionIn)
{
	//tileFloorRect = 
	elevation = elevationIn;
	terrainDifficulty = terrainDifficultyIn;
	height = heightIn;
	width = widthIn;
	//xPosition = xPositionIn;
	//yPosition = yPositionIn;

	red = rand() % 254;
	green =  rand() % 254;
	blue = rand() % 254;

	tile = { xPositionIn, yPositionIn, widthIn, heightIn };
	//tileFloor = 
}

void Tile::draw(SDL_Renderer* gRenderer, double zoom)
{

	SDL_Rect rectToDraw = tile; //{ xPosition, yPosition, width, height };
	//Set Color of Rect with SDL_SetRenderDrawColor if needed
	//SDL_SetRenderDrawColor(gRenderer, 100, 0, 0, 255);
	SDL_SetRenderDrawColor(gRenderer, red , green, blue, 255);
	
	
	SDL_RenderDrawRect(gRenderer, &rectToDraw);
}

Tile::~Tile()
{
}
