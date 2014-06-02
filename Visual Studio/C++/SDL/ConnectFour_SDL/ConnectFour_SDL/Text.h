#pragma once
#include <SDL.h>
#include <string>
#include <SDL_ttf.h>


class Text {
private:
	//std::vector<Button> menuButtons;
	std::string textName;
	std::string textValue;
	int xPosition;
	int yPosition;
	int width;
	int height;
	SDL_Texture* mTexture = NULL;
	SDL_Surface* message = NULL;
	TTF_Font* font;
	SDL_Color fontColor;
	SDL_Rect renderQuad;
	TTF_Font* tmpfont;
public:
	Text();
	Text(std::string textNameIn, std::string textIn, int xPositionIn, int yPositionIn, int rectWidth, int rectHeight, int fontSizeIn, SDL_Color fontColorIn);
	Text(std::string textNameIn, std::string textIn, int xPositionIn, int yPositionIn, int rectWidth, int rectHeight, char *fileLocation, int fontSizeIn, SDL_Color fontColorIn);
	~Text();
	virtual void draw(SDL_Renderer* gRenderer);
	virtual void checkEvents(SDL_Event* e);
	virtual void setName(std::string NameIn);
	virtual std::string getName();
	virtual void setText(std::string NameIn);
	virtual std::string getText();
	virtual const char *getCharText();
	virtual void setHeight(int HeightIn);
	virtual int getHeight();
	virtual void setWidth(int widthIn);
	virtual int getWidth();
	virtual void setXPosition(int xPositionIn);
	virtual int getXPosition();
	virtual void setYPosition(int yPositionIn);
	virtual int getYPosition();
	virtual void setFontColor(SDL_Color fontColorIn);
	virtual SDL_Color getFontColor();
	virtual TTF_Font* loadFont(char* file, int ptsize);
	
};