#pragma once
#include "Tile.h"


Tile::Tile(int elevationIn, int terrainDifficultyIn, int heightIn, int widthIn, int xPositionIn, int yPositionIn)
{
	//tileFloorRect = 
	elevation = elevationIn;
	terrainDifficulty = terrainDifficultyIn;
	height = heightIn;
	width = widthIn;
	xPosition = xPositionIn;
	yPosition = yPositionIn;
	//tileFloor = 
}


Tile::~Tile()
{
}

void Tile::renderFloor(SDL_Renderer* gRenderer)
{

}
void Tile::renderTopTiles(SDL_Renderer* gRenderer)
{

}

void Tile::addDoor(Door tileDoorIn)
{

}
void Tile::addContainer(Container tileContainerIn)
{

}
void Tile::addWall(Wall tileWallIn)
{

}

//void Tile::addDoor(std::string doorName, std::string compassDirection)
//{
//
//}
//void Tile::addContainer(std::string containerName)
//{
//
//}
//void Tile::addWall(std::string wallName)
//{
//	if (wallName == "Black")
//	{
//
//	}
//}

void Tile::draw(SDL_Renderer* gRenderer)
{

	SDL_Rect rectToDraw = { xPosition, yPosition, width, height }; 
	//Set Color of Rect with SDL_SetRenderDrawColor if needed
	SDL_SetRenderDrawColor(gRenderer, 25, 125, 0, 220);
	SDL_RenderDrawRect(gRenderer, &rectToDraw);
}

