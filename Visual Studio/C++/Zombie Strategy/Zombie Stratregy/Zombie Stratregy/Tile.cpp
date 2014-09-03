#include "Tile.h"
#include "PreCompile.h"

Tile::Tile(int elevationIn, int terrainDifficultyIn, int heightIn, int widthIn, int xPositionIn, int yPositionIn)
{
	elevation = elevationIn;
	terrainDifficulty = terrainDifficultyIn;
	height = heightIn;
	width = widthIn;

	red = rand() % 254;
	green =  rand() % 254;
	blue = rand() % 254;

	tile = { xPositionIn, yPositionIn, widthIn, heightIn };
}


Tile::Tile(int elevationIn, int terrainDifficultyIn, int heightIn, int widthIn, int xPositionIn, int yPositionIn, int gidIn, LTexture* SpriteSheetIn)
{
	elevation = elevationIn;
	terrainDifficulty = terrainDifficultyIn;
	height = heightIn;
	width = widthIn;

	tile = { xPositionIn, yPositionIn, widthIn, heightIn };

	gid = gidIn;

	Spritesheet = SpriteSheetIn;

	buildType = 1;
}

void Tile::draw(SDL_Renderer* gRenderer, double zoom, SDL_Texture* SpriteSheetIn)
{
	SDL_Rect rectToDraw = tile;
	if (buildType = 1)
	{
		SDL_RenderCopy(gRenderer, SpriteSheetIn, &rectToDraw,&tile);
	}
	else
	{

		//SDL_Rect rectToDraw = tile;
		//SDL_Rect rectToDraw = { floor(this->tile.x  * zoom), floor(this->tile.y  * zoom), floor(this->tile.h  * zoom), floor(this->tile.w * zoom) };
		SDL_SetRenderDrawColor(gRenderer, red, green, blue, 255);

		//SDL_RenderDrawRect(gRenderer, &rectToDraw);

		SDL_RenderFillRect(gRenderer, &rectToDraw);
	}

}

Tile::~Tile()
{
}
 