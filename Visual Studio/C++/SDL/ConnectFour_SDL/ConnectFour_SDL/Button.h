#include <SDL.h>
#pragma once

class Button
{
public:
	// Common to all menus:
	// (for example)
	virtual void draw(SDL_Renderer* gRenderer){};
	virtual void checkEvents(SDL_Event e){};

	virtual void setBaseColor(int redIn, int greenIn, int blueIn, int opacityIn){}	
	virtual void renderUpColor(SDL_Renderer* gRender){}
	virtual void renderDownColor(SDL_Renderer* gRender)	{}
	virtual void setRed(int redIn){}
	virtual void setGreen(int greenIn){}
	virtual void setBlue(int blueIn){}
	virtual void setOpacity(int OpacityIn){}
	virtual int getRed(){}
	virtual int getGreen(){}
	virtual int getBlue(){}
	virtual void getOpacity(){}
	virtual int getWidth(){}
	virtual void setWidth(int WidthIn){}
	virtual int getHeight(){}
	virtual void setHeight(int heightIn){}
	virtual int getxPosition(){}
	virtual void setxPosition(int xPositionIn){}
	virtual int getyPosition(){}
	virtual void setyPosition(int yPositionIn){}


private:
	int red;
	int green;
	int blue;
	int opacity;
	int width;
	int height;
	int xPosition;
	int yPosition;
};