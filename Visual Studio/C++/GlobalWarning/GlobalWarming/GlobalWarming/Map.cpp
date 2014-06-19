#pragma once
#include "Map.h"


Map::Map(int tileWidthIn, int tileHeightIn, int mapWidthIn, int mapHeightIn)
{
	int tileCountW,tileCountH;
	std::vector<Tile> row;

	tileCountW = mapWidthIn / tileWidthIn;
	tileCountH = mapHeightIn / tileHeightIn;
	for (int j = 0; j <= tileCountH; j++)
	{
		for (int i = 0; i <= tileCountW; i++)
		{
			row.push_back(Tile(j * tileWidthIn, i * tileHeightIn, tileHeightIn, tileWidthIn, tileWidthIn  * i, tileHeightIn * j));
		}
		gridTile.push_back(row);
	}
}
Map::Map(std::string mapName)
{
	loadMap(mapName);
}

Map::~Map()
{
}


void Map::addRoom(int xPositionIn, int yPositionIn, int roomWidth, int roomHeight)
{
	if (xPositionIn + roomWidth > mapWidth || yPositionIn + roomHeight > mapHeight)
	{

	}
	else
	{
		for (int j = yPositionIn; j <= roomHeight + 1; j++)
		{
			for (int i = xPositionIn; i <= roomHeight + 1; i++)
			{
				if (j == yPositionIn || i == xPositionIn || j == roomHeight + 1 || i == roomWidth + 1 )
				{
					gridTile[j][i].addWall("Black");
				}
			}
		}
	}
}


void Map::draw(SDL_Renderer* gRenderer)
{
	for (int j = 0; j < gridTile.size(); j++)
	{
		for (int i = 0; i < gridTile[j].size(); i++)
		{
			gridTile[j][i].draw(gRenderer);
		}
	}
}

void Map::loadMap(std::string mapName)
{
	gridTile.clear;
	std::vector<Tile> row;
	int tileCountW, tileCountH, mapHeight, tileHeight, mapWidth, tileWidth;

	if (mapName == "Main Apartment - Level 3")
	{
		mapWidth = 1024;
		mapHeight = 768;
		tileHeight = 32;
		tileWidth = 32;
	}
	else
	{

	}

	tileCountW = mapWidth / mapWidth;
	tileCountH = mapHeight / tileHeight;
	for (int j = 0; j <= tileCountH; j++)
	{
		for (int i = 0; i <= tileCountW; i++)
		{
			row.push_back(Tile(j * mapWidth, i * tileHeight, tileHeight, mapWidth, mapWidth  * i, tileHeight * j));
		}
		gridTile.push_back(row);
	}
	
	if (mapName == "Main Apartment - Level 3")
	{
		addRoom(0, 0, 5, 5);

	}

}