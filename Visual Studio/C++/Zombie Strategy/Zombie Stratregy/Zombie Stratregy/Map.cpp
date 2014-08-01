#include "Map.h"


#include <iostream>
Map::Map(int tileWidthIn, int tileHeightIn, int mapWidthIn, int mapHeightIn, int mapViewWidthIn, int mapViewHeightIn)
{
	int tileCountW, tileCountH;
	std::vector<Tile> row;

	//Will Need Sanitized./
	mapHeight = mapHeightIn;
	mapWidth = mapWidthIn;
	mapViewWidth = mapViewWidthIn;
	mapViewHeight = mapViewHeightIn;

	tileCountW = mapWidthIn / tileWidthIn;
	tileCountH = mapHeightIn / tileHeightIn;

	camera = { 0, 0, mapViewWidth, mapViewHeight };

	for (int j = 0; j <= tileCountH; j++)
	{
		for (int i = 0; i <= tileCountW; i++)
		{
			row.push_back(Tile(j * tileWidthIn, i * tileHeightIn, tileHeightIn, tileWidthIn, tileWidthIn  * i, tileHeightIn * j));
		}
		gridTile.push_back(row);
	}
}

void Map::handleEvent(SDL_Event e)
{


	if (e.key.keysym.sym == SDLK_DOWN)
	{
		if ((camera.y + mapViewHeight) <= mapHeight)
		{
			//camera.y = camera.y + 1;

			for (size_t j = 0; j < gridTile.size() - 1; j++)
			{
				for (size_t i = 0; i < gridTile[j].size() - 1; i++)
				{
					//gridTile[j][i].draw(gRenderer);
					//gridTile.draw(gridTile[j][i].xPosition, gridTile[j][i].yPosition, gridTile[j][i].tileFloorRect, gRenderer);
					
						gridTile[j][i].yPosition = gridTile[j][i].yPosition + 1;
					
				}
			}
			
		}
	}
	else if (e.key.keysym.sym == SDLK_LEFT)
	{
		//if (camera.x  >= 0)
		//{
			//camera.x = camera.x -1; 

			for (size_t j = 0; j < gridTile.size() - 1; j++)
			{
				for (size_t i = 0; i < gridTile[j].size() - 1; i++)
				{
					//gridTile[j][i].draw(gRenderer);
					//gridTile.draw(gridTile[j][i].xPosition, gridTile[j][i].yPosition, gridTile[j][i].tileFloorRect, gRenderer);
					
						gridTile[j][i].xPosition = gridTile[j][i].xPosition - 1;
					
				}
			}

		//}
	}
	else if (e.key.keysym.sym == SDLK_UP)
	{
		/*if ((camera.y + mapViewHeight) <= mapHeight)
		{
			camera.y = camera.y - 1;
		}*/

		for (size_t j = 0; j < gridTile.size() - 1; j++)
		{
			for (size_t i = 0; i < gridTile[j].size() - 1; i++)
			{
				//gridTile[j][i].draw(gRenderer);
				//gridTile.draw(gridTile[j][i].xPosition, gridTile[j][i].yPosition, gridTile[j][i].tileFloorRect, gRenderer);
				
					gridTile[j][i].yPosition = gridTile[j][i].yPosition - 1;
				
			}
		}


	}
	else if (e.key.keysym.sym == SDLK_RIGHT)
	{
		/*if (camera.x + mapViewWidth <= mapWidth)
		{
			camera.x = camera.x + 1;
		}*/

		for (size_t j = 0; j < gridTile.size() - 1; j++)
		{
			for (size_t i = 0; i < gridTile[j].size() - 1; i++)
			{
				//gridTile[j][i].draw(gRenderer);
				//gridTile.draw(gridTile[j][i].xPosition, gridTile[j][i].yPosition, gridTile[j][i].tileFloorRect, gRenderer);

					gridTile[j][i].xPosition = gridTile[j][i].xPosition + 1;
				
			}
		}

	}
	else if (e.wheel.y < 0)
	{
		if (zoom > .5)
		{
			zoom = zoom - .1;
		}
	}
	else if (e.wheel.y > 0)
	{
		if (zoom < 1.5)
		{
			zoom = zoom + .1;
		}
	}
}

void Map::draw(SDL_Renderer* gRenderer)
{
	for (size_t j = 0; j < gridTile.size() - 1; j++)
	{
		for (size_t i = 0; i < gridTile[j].size() - 1; i++)
		{
			//gridTile[j][i].draw(gRenderer);
			//gridTile.draw(gridTile[j][i].xPosition, gridTile[j][i].yPosition, gridTile[j][i].tileFloorRect, gRenderer);
			if (check_collision(camera, gridTile[j][i].tile) == true)
			{
				gridTile[j][i].draw(gRenderer, zoom);
			}
		}
	}
}
//Map::Map(std::string mapName)
//{
//	loadMap(mapName);
//}

Map::~Map()
{
}

bool Map::check_collision( SDL_Rect A, SDL_Rect B )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;

    //Calculate the sides of rect B
    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}