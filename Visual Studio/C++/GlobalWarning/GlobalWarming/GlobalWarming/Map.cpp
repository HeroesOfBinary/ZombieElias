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


//void Map::addRoom(int xPositionIn, int yPositionIn, int roomWidth, int roomHeight, int xDoorPosition, int yDoorPosition)
//{
//	if (xPositionIn + roomWidth > mapWidth || yPositionIn + roomHeight > mapHeight)
//	{
//
//	}
//	else
//	{
//		for (int j = yPositionIn; j <= roomHeight + 1; j++)
//		{
//			for (int i = xPositionIn; i <= roomHeight + 1; i++)
//			{
//				if (j == yPositionIn || i == xPositionIn || j == roomHeight + 1 || i == roomWidth + 1 )
//				{
//					gridTile[j][i].addWall("Black");
//					if (i == xDoorPosition && j == yDoorPosition)
//					{
//						gridTile[j][i].addDoor();
//					}
//				}
//			}
//		}
//	}
//}


void Map::draw(SDL_Renderer* gRenderer)
{

	floorTiles.loadFromFile(floorTiles.filePath, gRenderer);

	for (int j = 0; j < gridTile.size()-5; j++)
	{
		for (int i = 0; i < gridTile[j].size()- 5; i++)
		{
			//gridTile[j][i].draw(gRenderer);
		floorTiles.render(gridTile[j][i].xPosition, gridTile[j][i].yPosition, gridTile[j][i].tileFloorRect, gRenderer);
		}
	}
}

void Map::loadMap(std::string mapName)
{
	gridTile.clear();
	std::vector<Tile> row;
	SDL_Rect* Stuff;
	SDL_Rect* Stuff2;
	int tileCountW, tileCountH, mapHeight, tileHeight, mapWidth, tileWidth;
	Stuff = new SDL_Rect;
	Stuff2 = new SDL_Rect;

	if (mapName == "Main Apartment - Level 3")
	{
		
		mapWidth = 1024;
		mapHeight = 768;
		tileHeight = 32;
		tileWidth = 32;

		floorTiles.filePath = "Images\Apartment\FloorTiles.png";
	}
	else
	{

	}


	tileCountW = mapWidth / tileWidth;
	tileCountH = mapHeight / tileHeight;
	for (int j = 0; j < tileCountH; j++)
	{
		row.clear();
		for (int i = 0; i < tileCountW; i++)
		{
			//row.push_back(Tile(j * mapWidth, i * tileHeight, tileHeight, mapWidth, mapWidth  * i, tileHeight * j));
			row.push_back(Tile(0, 0, tileHeight, tileWidth, tileCountW  * i, tileCountH * j));
		}
		gridTile.push_back(row);
	}
	


	if (mapName == "Main Apartment - Level 3")
	{
		Stuff->x = 0;
		Stuff->y = 0;
		Stuff->w = 32;
		Stuff->h = 32;
		Stuff2->x = 128;
		Stuff2->y = 0;
		Stuff2->w = 32;
		Stuff2->h = 32;
		for (int j = 0; j < tileCountH; j++)
		{
			for (int i = 0; i < tileCountW; i++)
			{
				//128
				if (j >= 15 && j <= 15 && i >= 10 && i <= 25)
				{
					gridTile[j][i].tileFloorRect = Stuff;
				}
				else
				{
					gridTile[j][i].tileFloorRect = Stuff2;
				}
				
			}
		}
	}

	//if (mapName == "Main Apartment - Level 3")
	//{
	//	addRoom(0, 0, 5, 5, 1, 6);

	//}

}