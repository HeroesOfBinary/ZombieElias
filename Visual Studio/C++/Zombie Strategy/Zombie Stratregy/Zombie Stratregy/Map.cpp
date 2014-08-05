#include "Map.h"

Map::Map(int tileWidthIn, int tileHeightIn, int mapWidthIn, int mapHeightIn, int mapViewWidthIn, int mapViewHeightIn)
{
	int tileCountW, tileCountH;
	std::vector<Tile> row;

	//Will Need Sanitized./
	mapHeight = mapHeightIn;
	mapWidth = mapWidthIn;
	mapViewWidth = mapViewWidthIn;
	mapViewHeight = mapViewHeightIn;
	pressed = false;

	tileCountW = mapWidthIn / tileWidthIn;
	tileCountH = mapHeightIn / tileHeightIn;

	camera = { 0, 0, mapViewWidth, mapViewHeight };

	for (int j = 0; j < tileCountH; j++)
	{
		for (int i = 0; i < tileCountW; i++)
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
		//Move Map Down
		if ((camera.y + mapViewHeight) <= mapHeight)
		{
			for (size_t j = 0; j < gridTile.size(); j++)
			{
				for (size_t i = 0; i < gridTile[j].size(); i++)
				{
					gridTile[j][i].tile.y = gridTile[j][i].tile.y  + 1;
				}
			}
		}
	}
	else if (e.key.keysym.sym == SDLK_LEFT)
	{
		//Move Map Left
		for (size_t j = 0; j < gridTile.size(); j++)
		{
			for (size_t i = 0; i < gridTile[j].size(); i++)
			{
				gridTile[j][i].tile.x  = gridTile[j][i].tile.x - 1;
			}
		}
	}
	else if (e.key.keysym.sym == SDLK_UP)
	{
		//Move Map Up
		for (size_t j = 0; j < gridTile.size(); j++)
		{
			for (size_t i = 0; i < gridTile[j].size(); i++)
			{
				gridTile[j][i].tile.y = gridTile[j][i].tile.y -1;
			}
		}
	}
	
	else if (e.key.keysym.sym == SDLK_RIGHT)
	{
		//Move Map Down
		for (size_t j = 0; j < gridTile.size() ; j++)
		{
			for (size_t i = 0; i < gridTile[j].size() ; i++)
			{
					gridTile[j][i].tile.x = gridTile[j][i].tile.x + 1;
			}
		}
	}
	else if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		//Set map to be draggable
		pressed = true;
	}
	else if (e.type == SDL_MOUSEBUTTONUP)
	{
		//Stop map being draggable
		pressed = false;
	}
	else if (e.type == SDL_MOUSEMOTION)
	{
		//if mouse pressed move map
		if (pressed == true)
		{
			for (size_t j = 0; j < gridTile.size(); j++)
			{
				for (size_t i = 0; i < gridTile[j].size(); i++)
				{
					gridTile[j][i].tile.x += e.motion.xrel;
					gridTile[j][i].tile.y += e.motion.yrel;
				}
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
	for (size_t j = 0; j < gridTile.size() ; j++)
	{
		for (size_t i = 0; i < gridTile[j].size() ; i++)
		{
			if (check_collision(camera, gridTile[j][i].tile) == true)
			{
				gridTile[j][i].draw(gRenderer, zoom);
			}
		}
	}
}

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