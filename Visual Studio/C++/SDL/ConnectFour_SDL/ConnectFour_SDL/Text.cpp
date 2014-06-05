#pragma once
#include "Text.h"

//Text::Text()
//{};

Text::Text(std::string textNameIn, std::string textIn, int xPositionIn, int yPositionIn,  char *fileLocation, int fontSizeIn, SDL_Color fontColorIn)
{
	TTF_Init();
	setName(textNameIn);
	setText(textIn);
	setXPosition(xPositionIn);
	setYPosition(yPositionIn);
	setFontColor(fontColorIn);
	font = loadFont(fileLocation, fontSizeIn);
	TTF_SetFontStyle(font, TTF_STYLE_BOLD);
	message = TTF_RenderText_Solid(font, getCharText(), getFontColor());
};

Text::Text(std::string textNameIn, std::string textIn, int xPositionIn, int yPositionIn,  int fontSizeIn, SDL_Color fontColorIn)
{
	TTF_Init();
	setName(textNameIn);
	setText(textIn);
	setXPosition(xPositionIn);
	setYPosition(yPositionIn);

	setFontColor(fontColorIn);
	font = loadFont("C:/windows/fonts/cour.ttf", fontSizeIn);
	TTF_SetFontStyle(font, TTF_STYLE_BOLD);
	message = TTF_RenderText_Solid(font, getCharText(), getFontColor());
};

Text::Text(std::string textNameIn, std::string textIn, std::string alignmentV, std::string alignmentH, int objectXposition, int objectYPosition, char *fileLocation, int fontSizeIn, SDL_Color fontColorIn)
{
	TTF_Init();
	setName(textNameIn);
	setText(textIn);
	setXPosition(xPositionIn);
	setYPosition(yPositionIn);

	setFontColor(fontColorIn);
	font = loadFont(fileLocation, fontSizeIn);
	TTF_SetFontStyle(font, TTF_STYLE_BOLD);
	message = TTF_RenderText_Solid(font, getCharText(), getFontColor());
};


TTF_Font* Text::loadFont(char* file, int ptsize)
{
	tmpfont;
	tmpfont = TTF_OpenFont(file, ptsize);
	if (tmpfont == NULL) {
		printf("Unable to load font: %s %s \n", file, TTF_GetError());
		// Handle the error here.
	}
	return tmpfont;
}



Text::~Text()
{
	SDL_FreeSurface(message);
};

void Text::draw(SDL_Renderer* gRenderer)
{	

	renderQuad = { getXPosition(), getYPosition(), message->w, message->h };
//	SDL_DestroyTexture(mTexture);
	if (mTexture == NULL)
	{
		mTexture = SDL_CreateTextureFromSurface(gRenderer, message);
	}
	//SDL_RenderCopyEx(gRenderer, mTexture, NULL, &renderQuad, NULL, NULL, SDL_FLIP_NONE);
	SDL_RenderCopy(gRenderer, mTexture, NULL, &renderQuad);
};

void Text::checkEvents(SDL_Event* e){};
void Text::setName(std::string NameIn)
{
	textName = NameIn;
};
std::string Text::getName()
{
	return textName;
};
void Text::setText(std::string textIn)
{
	textValue = textIn;
};
std::string Text::getText()
{
	return textValue;
};
const char *Text::getCharText()
{
	//const char *cstr = 
	return textValue.c_str();
};
void Text::setHeight(int HeightIn)
{
	height = HeightIn;
};
int Text::getHeight()
{
	return height;
};
void Text::setWidth(int widthIn)
{
	width = widthIn;
};
int Text::getWidth()
{
	return width;
};
void Text::setXPosition(int xPositionIn)
{
	xPosition = xPositionIn;
};
int Text::getXPosition()
{
	return xPosition;
};
void Text::setYPosition(int yPositionIn)
{
	yPosition = yPositionIn;
};
int Text::getYPosition()
{
	return yPosition;
};

void Text::setFontColor(SDL_Color fontColorIn)
{
	fontColor = fontColorIn;
};
SDL_Color Text::getFontColor()
{
	return fontColor;
};