#pragma once
#include "Tile.h"

class Map
{
public:
	int mapHeight;
	int mapWidth;
	std::vector<std::vector<Tile>> gridTile;
	Map(int tileWidth, int tileHeight, int mapWidth, int mapHeight);
	Map(std::string mapName);
	~Map();
	void addRoom(int xPosition, int yPosition, int roomWidth, int roomHeight);
	void loadMap(std::string mapName);
	void draw(SDL_Renderer* gRenderer);

};

