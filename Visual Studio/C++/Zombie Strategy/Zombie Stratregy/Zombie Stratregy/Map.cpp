#include "Map.h"

Map::Map(int tileWidthIn, int tileHeightIn, int mapWidthIn, int mapHeightIn, int mapViewWidthIn, int mapViewHeightIn)
{
	std::vector<Tile> row;

	//Will Need Sanitized./
	buildType = 0;
	mapHeight = mapHeightIn;
	mapWidth = mapWidthIn;
	mapViewWidth = mapViewWidthIn;
	mapViewHeight = mapViewHeightIn;
	pressed = false;

	//keysHeld[323] = { false };
	keys = SDL_GetKeyboardState(NULL);
	tileCountW = mapWidthIn / tileWidthIn;
	tileCountH = mapHeightIn / tileHeightIn;


	SDL_SetClipRect(surface, &camera);
	for (int j = 0; j <= tileCountH; j++)
	{
		row.clear();
		for (int i = 0; i <= tileCountW; i++)
		{
			row.push_back(Tile(j * tileWidthIn, i * tileHeightIn, tileHeightIn, tileWidthIn, tileWidthIn  * i, tileHeightIn * j));
		}
		gridTile.push_back(row);
	}
}

Map::Map(std::string mapName, SDL_Renderer* gRenderer)
{

	keys = SDL_GetKeyboardState(NULL);
	int mapCount, spriteWidth, spriteHeight, tileSetWidth, tileSetHeight;
	std::string test;
	buildType = 1;
	std::string mapLocation;
	LTexture map;

	SDL_Rect sprite;
	std::vector<Tile> row;
	tinyxml2::XMLElement* tileData;
	theMap = new tinyxml2::XMLDocument;
	if (mapName == "OutsideMap_Desert1")
	{
		mapCount = 1;

		theMap->LoadFile("OutsideMap_Desert1.tmx");
		
	}

	//Load Textures into Vector via loop
	
	//mapLocation = theMap->FirstChildElement("map")->FirstChildElement("tileset")->FirstChildElement("image")->Attribute("source");
	mapLocation = "E:\hyptosis_tile-art-batch-1_0.png";
	//mapLocation  = "../Assets/" + mapLocation;
	gSpriteSheetTexture.loadFromFile(mapLocation, gRenderer);
	//gSpriteSheetTexture.push_back(map);

	spriteWidth = atoi(theMap->FirstChildElement("map")->FirstChildElement("tileset")->Attribute("tilewidth"));
	spriteHeight = atoi(theMap->FirstChildElement("map")->FirstChildElement("tileset")->Attribute("tileheight"));

	test = theMap->FirstChildElement("map")->FirstChildElement("tileset")->FirstChildElement("image")->Attribute("width");
	tileSetWidth = atoi(theMap->FirstChildElement("map")->FirstChildElement("tileset")->FirstChildElement("image")->Attribute("width"));
	tileSetHeight = atoi(theMap->FirstChildElement("map")->FirstChildElement("tileset")->FirstChildElement("image")->Attribute("height"));

	tileCountW = atoi(theMap->FirstChildElement("map")->Attribute("width"));
	tileCountH = atoi(theMap->FirstChildElement("map")->Attribute("height"));

	sprite = { 0, 0, 0, 0 };
	gSpriteClips.push_back(sprite);

	camera = { 0, 0, 1024, 768 };

	for (int j = 0; j < tileSetHeight; j+=spriteHeight)
	{

		for (int i = 0; i < tileSetWidth; i+=spriteWidth)
		{
			sprite = { i, j , spriteWidth, spriteHeight };

			gSpriteClips.push_back(sprite);
		}

	}


	tileData = theMap->FirstChildElement("map")->FirstChildElement("layer")->FirstChildElement("data");
	//for (tinyxml2::XMLElement* child = theMap->FirstChildElement("map")->FirstChildElement("layer")->FirstChildElement("data"); child != NULL; child = child->NextSiblingElement())
	//{
	//	 do something with each child element
	//}
	tinyxml2::XMLElement* child = tileData->FirstChildElement();
	for (int j = 0; j < tileCountH; j++)
	{
		row.clear();
		for (int i = 0; i < tileCountW; i++)
		{
			
			row.push_back(Tile(0 ,
								0,
								spriteHeight,
								spriteWidth,
								i * spriteHeight,
								j * spriteWidth,
								atoi(child->Attribute("gid"))));
			//atoi(tileData->Attribute("gid"))
			child = child->NextSiblingElement();
								//gSpriteClips[(int)tileData->FirstChildElement("tile")->Attribute("gid")]));
		}
		gridTile.push_back(row);
	}

	
	//Load tile with Gids, and pass textures down to tile with pointer



}

void Map::handleEvent(SDL_Event e)
{	
	
	/*if (e.key.keysym.sym == SDLK_DOWN)*/
	if (keys[SDL_SCANCODE_DOWN])
	{
		//Move Map Down
		for (int j = 0; j < tileCountH; j++)
		{
			for (int i = 0; i < tileCountW; i++)
			{
				gridTile[j][i].tile.y = gridTile[j][i].tile.y  + 5;
			}
		}
	}
	//else if (e.key.keysym.sym == SDLK_LEFT)
	if (keys[SDL_SCANCODE_LEFT])
	{
		//Move Map Left
		for (int j = 0; j < tileCountH; j++)
		{
			for (int i = 0; i < tileCountW; i++)
			{
				gridTile[j][i].tile.x  = gridTile[j][i].tile.x - 5;
			}
		}
	}
	//else if (e.key.keysym.sym == SDLK_UP)
	if (keys[SDL_SCANCODE_UP])
	{
		//Move Map Up
		for (int j = 0; j < tileCountH; j++)
		{
			for (int i = 0; i < tileCountW; i++)
			{
				gridTile[j][i].tile.y = gridTile[j][i].tile.y -5;
			}
		}
	}
	
	//else if (e.key.keysym.sym == SDLK_RIGHT)
	if (keys[SDL_SCANCODE_RIGHT])
	{
		//Move Map Down
		for (int j = 0; j < tileCountH; j++)
		{
			for (int i = 0; i < tileCountW; i++)
			{
					gridTile[j][i].tile.x = gridTile[j][i].tile.x + 5;
			}
		}
	}

	if (e.type == SDL_MOUSEBUTTONDOWN)
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
			for (int j = 0; j < tileCountH; j++)
			{
				for (int i = 0; i < tileCountW; i++)
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
	//gSpriteSheetTexture.render(0, 0, gRenderer, NULL);
	//SDL_RenderCopy(gRenderer, gSpriteSheetTexture[0].mTexture, NULL, NULL);

	for (int j = 0; j < tileCountH; j++)
	{
		for (int i = 0; i < tileCountW; i++)
		{
			if (check_collision(camera, gridTile[j][i].tile) == true)
			{

				if (buildType == 1  )
				{
					
					gridTile[j][i].draw(gRenderer, zoom, gSpriteSheetTexture.mTexture, gSpriteClips[gridTile[j][i].gid]);

//					//SDL_RenderCopy(gRenderer, gSpriteSheetTexture.mTexture, &gSpriteClips[gridTile[j][i].gid], &gSpriteClips[gridTile[j][i].gid]);

				}
				else
				{
					//gridTile[j][i].draw(gRenderer, zoom);
				}
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