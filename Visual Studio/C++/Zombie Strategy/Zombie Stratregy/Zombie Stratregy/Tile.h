#pragma once
#include "PreCompile.h"
class Tile
{
public:
	int elevation;
	int terrainDifficulty;
	int width;
	int height;
	int red;
	int green;
	int blue;
	SDL_Rect tile;
	SDL_Rect* tileFloorRect;
	SDL_Rect* tileWallRect;
	SDL_Rect* tileDoorRect;
	SDL_Rect* tileContainerRect;

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
	void draw(SDL_Renderer* gRenderer, double zoom);
};

