#pragma once
#include "Door.h"
#include "Wall.h"
#include "Container.h"

class Tile
{
public:
	int elevation;
	int terrainDifficulty;
	int width;
	int height;
	int xPosition;
	int yPosition;
	Door tileDoor;
	//Container tileContainer;
	//Wall tileWall;
	//LTexture tileFloor;
	SDL_Rect tileFloorRect;
	SDL_Rect tileWallRect;
	SDL_Rect tileDoorRect;

	Tile(int elevationIn, int terrainDifficultyIn, int heightIn, int widthIn, int xPositionIn, int yPositionIn);
	~Tile();
	//void addDoor(Door tileDoorIn);
	//void addContainer(Container tileContainerIn);
	//void addWall(Wall tileWallIn);

	//void addDoor();
	//void addContainer(std::string containerName);
	//void addWall(std::string wallName);

	void renderFloor(SDL_Renderer* gRenderer);
	void renderTopTiles(SDL_Renderer* gRenderer);
	void draw(SDL_Renderer* gRenderer);

};