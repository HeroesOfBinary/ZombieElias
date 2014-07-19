#pragma once
#include "Precompile.h"

//#include "Tile.h"

class Map
{
public:
	int mapHeight;
	int mapWidth;
	std::vector<std::vector<Tile>> gridTile;
	std::vector<Textures> floorTile;
	std::vector<Textures> wallTile;
	Textures floorTiles;
	Textures wallTiles;
	std::vector <SDL_Rect> floorTilePositions;
	std::vector <SDL_Rect> wallTilePositions;


	Map(int tileWidth, int tileHeight, int mapWidth, int mapHeight);
	Map(std::string mapName);
	~Map();
	void addRoom(int xPosition, int yPosition, int roomWidth, int roomHeight, int xDoorPosition, int yDoorPosition);
	void loadMap(std::string mapName);
	void draw(SDL_Renderer* gRenderer);
};

