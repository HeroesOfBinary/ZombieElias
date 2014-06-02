#pragma once
#include "Text.h"


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
	std::string buttonName;
	bool pressed = false;
	std::string buttonText;
	bool hovering = false;
	Text* labelText;
	SDL_Rect fillRect;
	SDL_Color tmpfontcolor;

public:
	// Common to all menus:
	// (for example)

	virtual void setButtonText(std::string setValue);
	virtual std::string getButtonText();
	virtual void setButtonName(std::string setValue);
	virtual std::string getButtonName();
	virtual void setPressed(bool setValue);
	virtual bool getPressed();
	virtual void setHovering(bool setValue);
	virtual bool getHovering();
	Button(int redIn, int greenIn, int blueIn, int opacityIn, int widthIn, int heightIn, int xPositionIn, int yPositionIn, std::string buttonName, std::string buttonText, int fontSize);
	~Button();
	virtual void draw(SDL_Renderer* gRenderer);
	virtual bool checkEvents(SDL_Event* e);
	virtual void setBaseColor(int redIn, int greenIn, int blueIn, int opacityIn);
	virtual void renderUpColor(SDL_Renderer* gRender);
	virtual void renderDownColor(SDL_Renderer* gRender);
	virtual void renderHoverColor(SDL_Renderer* gRender);
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