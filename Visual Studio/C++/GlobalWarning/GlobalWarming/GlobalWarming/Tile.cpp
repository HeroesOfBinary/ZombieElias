#pragma once
#include "Tile.h"


Tile::Tile(int elevationIn, int terrainDifficultyIn, int heightIn, int widthIn, int xPositionIn, int yPositionIn)
{
	elevation = elevationIn;
	terrainDifficulty = terrainDifficultyIn;
	height = heightIn;
	width = widthIn;
	xPosition = xPositionIn;
	yPosition = yPositionIn;
}


Tile::~Tile()
{
}

void renderFloor(SDL_Renderer* gRenderer);
void renderTopTiles(SDL_Renderer* gRenderer);

void Tile::addDoor(Door tileDoorIn)
{

}
void Tile::addContainer(Container tileContainerIn)
{

}
void Tile::addWall(Wall tileWallIn)
{

}

void Tile::addDoor(std::string doorName)
{

}
void Tile::addContainer(std::string containerName)
{

}
void Tile::addWall(std::string wallName)
{
	if (wallName == "Black")
	{

	}
}

void Tile::draw(SDL_Renderer* gRenderer)
{

	SDL_Rect rectToDraw = { xPosition, yPosition, width, height }; 
	SDL_BlitSurface()
	//Set Color of Rect with SDL_SetRenderDrawColor if needed
	SDL_SetRenderDrawColor(gRenderer, 25, 125, 0, 220);
	SDL_RenderDrawRect(gRenderer, &rectToDraw);
}s

