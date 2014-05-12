#pragma once
#include "Button.h"

	Button::Button(int redIn, int greenIn, int blueIn, int opacityIn, int widthIn, int heightIn, int xPositionIn, int yPositionIn){
		setBaseColor(redIn, greenIn, blueIn, opacityIn);
		setWidth(widthIn);
		setHeight(heightIn);
		setxPosition(xPositionIn);
		setyPosition(yPositionIn);
		pressed = false;
	};

	Button::~Button()
	{

	};

	void Button::draw(SDL_Renderer* gRenderer)
	{
		
		SDL_Rect fillRect = { getxPosition(), getyPosition(), getWidth(), getHeight() };

		if (pressed = true)
		{
			renderDownColor(gRenderer);
		}
		else
		{
			renderUpColor(gRenderer);
		}
			
			//SDL_SetRenderDrawColor(gRenderer, 255, 0x00, 0x00, 0xFF);
		
		SDL_RenderFillRect(gRenderer, &fillRect);
	}

	bool Button::checkEvents(SDL_Event e)
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);
		
		//If mouse event happened
		if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP) //(e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
		{
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				

				//Check if mouse is in button

				//Mouse is left of the button
				if (x >= getxPosition() && x <= (getxPosition() + getWidth()) && y >= getyPosition() && y <= (getyPosition() + getHeight()))
				{
					pressed = true;
					return pressed;
				}
				else
				{
					pressed = false;
					return pressed;
				}

			}
			else if (e.type == SDL_MOUSEBUTTONUP)
			{
				pressed = false;
				return pressed;
			}
			else
			{
				pressed = false;
				return pressed;
			}

			//Get mouse position
			//int x, y;
			//SDL_GetMouseState(&x, &y);
		}
		else
		{
			pressed = false;
			return pressed;
		}
	};

	void Button::setBaseColor(int redIn, int greenIn, int blueIn, int opacityIn)
	{
		setRed(redIn);
		setBlue(blueIn);
		setGreen(greenIn);
		setOpacity(opacityIn);
	}
	void Button::renderUpColor(SDL_Renderer* gRenderer)
	{
		SDL_SetRenderDrawColor(gRenderer, red, green, blue, opacity);
	}
	void Button::renderDownColor(SDL_Renderer* gRenderer)
	{
		int darkerRed, darkerGreen, darkerBlue;
		if (red > 20)
		{
			darkerRed = red - 40;
		}

		if (green > 20)
		{
			darkerGreen = green - 40;
		}

		if (blue > 20)
		{
			darkerBlue = blue - 40;
		}

		SDL_SetRenderDrawColor(gRenderer, darkerRed, darkerGreen, darkerBlue, opacity);
	}

	void Button::setRed(int redIn)
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
	void Button::setGreen(int greenIn)
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
	void Button::setBlue(int blueIn)
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
	void Button::setOpacity(int opacityIn)
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
	int Button::getRed()
	{
		return red;
	}
	int Button::getGreen()
	{
		return green;
	}
	int Button::getBlue()
	{
		return blue;
	}
	int Button::getOpacity()
	{
		return opacity;
	}
	int Button::getWidth()
	{
		return width;
	}
	void Button::setWidth(int WidthIn)
	{
		width = WidthIn;
	}
	int Button::getHeight()
	{
		return height;
	}
	void Button::setHeight(int heightIn)
	{
		height = heightIn;
	}
	int Button::getxPosition()
	{
		return xPosition;
	}
	void Button::setxPosition(int xPositionIn)
	{
		xPosition = xPositionIn;
	}
	int Button::getyPosition()
	{
		return yPosition;
	}
	void Button::setyPosition(int yPositionIn)
	{
		yPosition = yPositionIn;
	}
/*
private:
	int red;
	int green;
	int blue;
	int opacity;
	int width;
	int height;
	int xPosition;*/
//};
//#
	//int yPosition;
	//bool pressed;include <SDL.h>
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