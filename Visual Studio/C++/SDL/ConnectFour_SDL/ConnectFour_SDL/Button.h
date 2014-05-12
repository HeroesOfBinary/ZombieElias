#pragma once
#include <SDL.h>
#include <string>

class Button
{
private:
	int red;
	int green;
	int blue;
	int opacity;
	int width;
	int height;
	int xPosition;
	int yPosition;
	bool pressed = false;
public:
	// Common to all menus:
	// (for example)
	Button(int redIn, int greenIn, int blueIn, int opacityIn, int widthIn, int heightIn, int xPositionIn, int yPositionIn);
	~Button();
	virtual void draw(SDL_Renderer* gRenderer);
	virtual bool checkEvents(SDL_Event e);
	virtual void setBaseColor(int redIn, int greenIn, int blueIn, int opacityIn);
	virtual void renderUpColor(SDL_Renderer* gRender);
	virtual void renderDownColor(SDL_Renderer* gRender);
	virtual void setRed(int redIn);
	virtual void setGreen(int greenIn);
	virtual void setBlue(int blueIn);
	virtual void setOpacity(int OpacityIn);
	virtual int getRed();
	virtual int getGreen();
	virtual int getBlue();
	virtual int getOpacity();
	virtual int getWidth();
	virtual void setWidth(int WidthIn);
	virtual int getHeight();
	virtual void setHeight(int heightIn);
	virtual int getxPosition();
	virtual void setxPosition(int xPositionIn);
	virtual int getyPosition();
	virtual void setyPosition(int yPositionIn);
};