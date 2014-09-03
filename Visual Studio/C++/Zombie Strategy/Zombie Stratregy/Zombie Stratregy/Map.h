#pragma once
#include "PreCompile.h"
#include "Tile.h"
#include "LTexture.h"
class Map
{
public:
	int mapHeight;
	int mapWidth;
	int mapViewWidth;
	int mapViewHeight;
	int tileCountW;
	int tileCountH;
	int buildType;
	bool pressed;
	double zoom;
	std::vector <SDL_Rect> gSpriteClips;
	std::vector <LTexture> gSpriteSheetTexture;


	SDL_Rect camera;
	//bool keysHeld[323]; //Initialize keystates with null
	const Uint8 *keys ;

	std::vector<std::vector<Tile>> gridTile;
	std::vector <SDL_Rect> floorTilePositions;
	std::vector <SDL_Rect> wallTilePositions;
	//std::vector<tinyxml2::XMLDocument> maps;
	tinyxml2::XMLDocument *theMap;


	Map(int tileWidth, int tileHeight, int mapWidth, int mapHeight, int mapViewWidthIn, int mapViewHeightIn );
	Map(std::string mapName, SDL_Renderer* gRenderer);
	~Map();
	void addRoom(int xPosition, int yPosition, int roomWidth, int roomHeight, int xDoorPosition, int yDoorPosition);
	void loadMap(std::string mapName, SDL_Renderer* gRenderer);
	void draw(SDL_Renderer* gRenderer);
	bool check_collision(SDL_Rect A, SDL_Rect B);
	void handleEvent(SDL_Event e);
	
};


