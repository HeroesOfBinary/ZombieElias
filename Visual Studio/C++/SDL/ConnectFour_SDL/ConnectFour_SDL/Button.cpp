#pragma once
#include <SDL.h>

class Button
{
	//Button(SDL_Renderer* gRenderer, int redIn, int greenIn, int blueIn, int opacityIn){
	//	setBaseColor(redIn,greenIn,blueIn,opacityIn);
	//	
	//};

	Button(SDL_Renderer* gRenderer, int redIn, int greenIn, int blueIn, int opacityIn, int widthIn, int heightIn, int xPositionIn, int yPositionIn){
		setBaseColor(redIn, greenIn, blueIn, opacityIn);
		setWidth(widthIn);
		setHeight(heightIn);
		setxPosition(xPositionIn);
		setyPosition(yPositionIn);
	};

	virtual void draw(SDL_Renderer* gRenderer)
	{
		SDL_Rect fillRect = { getxPosition(), getyPosition(), getWidth(), getHeight() };
		//SDL_SetRenderDrawColor(gRenderer, 255, 0x00, 0x00, 0xFF);
		
		SDL_RenderFillRect(gRenderer, &fillRect);
	}

	virtual void checkEvents(SDL_Event e)
	{

	}

	virtual void setBaseColor(int redIn, int greenIn, int blueIn, int opacityIn)
	{
		
	}
	virtual void renderUpColor(SDL_Renderer* gRenderer)
	{
		SDL_SetRenderDrawColor(gRenderer, red, green, blue, opacity);
	}
	virtual void renderDownColor(SDL_Renderer* gRenderer)
	{
		int darkerRed, darkerGreen, darkerBlue;
		if (red > 20)
		{
			darkerRed = red - 20;
		}

		if (green > 20)
		{
			darkerGreen = green - 20;
		}

		if (blue > 20)
		{
			darkerBlue = blue - 20;
		}

		SDL_SetRenderDrawColor(gRenderer, darkerRed, darkerGreen, darkerBlue, opacity);
	}

	virtual void setRed(int redIn)
	{
		if (0 <= redIn && redIn <= 255)
		{
			red = redIn;
		}
		else
		{
			redIn = 155;
		}
	}
	virtual void setGreen(int greenIn)
	{
		if (0 <= greenIn && greenIn <= 255)
		{
			green = greenIn;
		}
		else
		{
			greenIn = 155;
		}
	}
	virtual void setBlue(int blueIn)
	{
		if (0 <= blueIn && blueIn <= 255)
		{
			blue = blueIn;
		}
		else
		{
			blue = 155;
		}
	}
	virtual void setOpacity(int opacityIn)
	{
		if (0 <= opacityIn  && opacityIn <= 255)
		{
			opacity = opacityIn;
		}
		else
		{
			opacityIn = 255;
		}
}	
	virtual int getRed()
	{
		return red;
	}
	virtual int getGreen()
	{
		return green;
	}
	virtual int getBlue()
	{
		return blue;
	}
	virtual int getOpacity()
	{
		return opacity;
	}
	virtual int getWidth()
	{
		return width;
	}
	virtual void setWidth(int WidthIn)
	{
		width = WidthIn;
	}
	virtual int getHeight()
	{
		return height;
	}
	virtual void setHeight(int heightIn)
	{
		height = heightIn;
	}
	virtual int getxPosition()
	{
		return xPosition;
	}
	virtual void setxPosition(int xPositionIn)
	{
		xPosition = xPositionIn;
	}
	virtual int getyPosition()
	{
		return yPosition;
	}
	virtual void setyPosition(int yPositionIn)
	{
		yPosition = yPositionIn;
	}

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
//#include <SDL.h>
////#include <SDL_image.h>
//#include <stdio.h>
//#include <string>
//#include <cmath>
//
//const int BUTTON_WIDTH = 300;
//const int BUTTON_HEIGHT = 200;
//
//class LButton
//{
//public:
//	//Initializes internal variables
//	LButton();
//	
//	//Sets top left position
//	void setPosition(int x, int y);
//	void setBaseColor(Uint8 red, Uint8 green, Uint8 blue);
//	void setColor(Uint8 red, Uint8 green, Uint8 blue);
//	//Handles mouse event
//	void handleEvent(SDL_Event* e);
//
//	//Shows button sprite
//	void render();
//
//private:
//	//Top left position
//	SDL_Point mPosition;
//
//};
//
//
//void LButton::setPosition(int x, int y)
//{
//	mPosition.x = x;
//	mPosition.y = y;
//}
//
//
//void LButton::render()
//{
//	//Show current button sprite
//	gRenderer
//}
//
//
//void LButton::handleEvent(SDL_Event* e)
//{
//	//If mouse event happened
//	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
//	{
//		//Get mouse position
//		int x, y;
//		SDL_GetMouseState(&x, &y);
//
//		//Check if mouse is in button
//		bool inside = true;
//
//		//Mouse is left of the button
//		if (x < mPosition.x)
//		{
//			inside = false;
//		}
//		//Mouse is right of the button
//		else if (x > mPosition.x + BUTTON_WIDTH)
//		{
//			inside = false;
//		}
//		//Mouse above the button
//		else if (y < mPosition.y)
//		{
//			inside = false;
//		}
//		//Mouse below the button
//		else if (y > mPosition.y + BUTTON_HEIGHT)
//		{
//			inside = false;
//		}
//
//		//Mouse is outside button
//		if (!inside)
//		{
//			//mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
//		}
//		//Mouse is inside button
//		else
//		{
//			//Set mouse over sprite
//			switch (e->type)
//			{
//			//case SDL_MOUSEMOTION:
//				//mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
//				//break;
//
//			case SDL_MOUSEBUTTONDOWN:
//				//Set state to "Pressed"
//				mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
//				break;
//
//			case SDL_MOUSEBUTTONUP:
//				//mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
//				//break;
//			}
//		}
//	}
//}
//
//void LButton::setColor(Uint8 red, Uint8 green, Uint8 blue)
//{
//	//Modulate texture rgb
//	SDL_SetTextureColorMod(mTexture, red, green, blue);
//}
//
//void LButton::setBaseColor(Uint8 red, Uint8 green, Uint8 blue)
//{
//	//Modulate texture rgb
//	SDL_SetTextureColorMod(mTexture, red, green, blue);
//}