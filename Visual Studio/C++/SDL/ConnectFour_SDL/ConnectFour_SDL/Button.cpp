#pragma once
#include "Button.h"

Button::Button(int redIn, int greenIn, int blueIn, int opacityIn, int widthIn, int heightIn, int xPositionIn, int yPositionIn, std::string buttonNameIn, std::string buttonTextIn, int fontSize)
{
		setBaseColor(redIn, greenIn, blueIn, opacityIn);
		setWidth(widthIn);
		setHeight(heightIn);
		setxPosition(xPositionIn);
		setyPosition(yPositionIn);
		setButtonName(buttonNameIn);
		setButtonText(buttonTextIn);
		setPressed(false);

		tmpfontcolor = { 225, 225, 225, 255 };

		labelText = new Text("myLabel",
			buttonTextIn, 
			(getxPosition() + (getWidth() * .25)), // xPosition
			(getyPosition() + (getHeight() * .25)), //yPosition
			getWidth() / 2, //Width
			getHeight() *.25,  //Height
			fontSize, 
			tmpfontcolor);
	};

	Button::~Button()
	{

	};

	void Button::setButtonName(std::string setValue)
	{
		buttonName = setValue;
	};
	std::string Button::getButtonName()
	{
		return buttonName;
	};

	void Button::setButtonText(std::string setValue)
	{
		buttonText = setValue;
	};
	std::string Button::getButtonText()
	{
		return buttonText;
	};

	void Button::setPressed(bool setValue)
	{
		pressed = setValue;
	}

	bool Button::getPressed()
	{
		return pressed;
	};

	void Button::setHovering(bool setValue)
	{
		hovering = setValue;
	}

	bool Button::getHovering()
	{
		return hovering;
	};

	void Button::draw(SDL_Renderer* gRenderer)
	{
		
		

		if (pressed == true)
		{
			fillRect = { getxPosition(), getyPosition(), getWidth(), getHeight() };
			renderUpColor(gRenderer);
			SDL_RenderFillRect(gRenderer, &fillRect);

			fillRect = { getxPosition() + 10, getyPosition() + 10, getWidth() - 20, getHeight() - 20 };
			renderDownColor(gRenderer);
			SDL_RenderFillRect(gRenderer, &fillRect);
		}
		else
		{
			if (hovering == true)
			{
				fillRect = { getxPosition(), getyPosition(), getWidth(), getHeight() };
				renderDownColor(gRenderer);
				SDL_RenderFillRect(gRenderer, &fillRect);

				fillRect = { getxPosition() + 10, getyPosition() + 10, getWidth() - 20, getHeight() - 20 };
				renderHoverColor(gRenderer);
				SDL_RenderFillRect(gRenderer, &fillRect);
			}
			else
			{
				fillRect = { getxPosition(), getyPosition(), getWidth(), getHeight() };
				renderDownColor(gRenderer);
				SDL_RenderFillRect(gRenderer, &fillRect);
			}
		}

		labelText->draw(gRenderer);
			//SDL_SetRenderDrawColor(gRenderer, 255, 0x00, 0x00, 0xFF);
		
		
	}

	bool Button::checkEvents(SDL_Event* e)
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);

		//Set "Button Execution" Return
		bool buttonExecuted;
		buttonExecuted = false;
		
		
		//If mouse event happened
		if (e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP || e->type == SDL_MOUSEMOTION) //(e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
		{
			if (e->type == SDL_MOUSEBUTTONDOWN)
			{
				//Check if mouse is in button

				//Mouse is left of the button
				if (x >= getxPosition() && x <= (getxPosition() + getWidth()) && y >= getyPosition() && y <= (getyPosition() + getHeight()))
				{
					setPressed(true);
				}
				else
				{
					setPressed(false);
				}

			}
			else if (e->type == SDL_MOUSEMOTION)
			{
				//Check if mouse is in button

				//Mouse is left of the button
				if (x >= getxPosition() && x <= (getxPosition() + getWidth()) && y >= getyPosition() && y <= (getyPosition() + getHeight()))
				{
					setHovering(true);
				}
				else
				{
					setHovering(false);
				}

			}
			else if (e->type == SDL_MOUSEBUTTONUP)
			{
				setPressed(false);
				if (x >= getxPosition() && x <= (getxPosition() + getWidth()) && y >= getyPosition() && y <= (getyPosition() + getHeight()))
				{
					buttonExecuted = true;
				}
				
			}
			else
			{
				setPressed(false);
			}
			return buttonExecuted;
			//Get mouse position
			//int x, y;
			//SDL_GetMouseState(&x, &y);
		}
		else
		{
			if (e->type != SDL_MOUSEMOTION)
			{
				setPressed(false);
			}
		}



		return getPressed();
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
			darkerRed = red - 20;
		}
		else
		{
			darkerRed = 0;
		}

		if (green > 20)
		{
			darkerGreen = green - 20;
		}
		else
		{
			darkerGreen = 0;
		}

		if (blue > 20)
		{
			darkerBlue = blue - 20;
		}
		else
		{
			darkerBlue = 0;
		}

		SDL_SetRenderDrawColor(gRenderer, darkerRed, darkerGreen, darkerBlue, opacity);
	}


	void Button::renderHoverColor(SDL_Renderer* gRenderer)
	{
		int lighterRed, lighterGreen, lighterBlue;
		if (red < 235)
		{
			lighterRed = red + 20;
		}
		else
		{
			lighterRed = 255;
		}

		if (green < 235)
		{
			lighterGreen = green + 20;
		}
		else
		{
			lighterGreen = 255;
		}

		if (blue < 235)
		{
			lighterBlue = blue + 20;
		}
		else
		{
			lighterBlue = 255;
		}

		SDL_SetRenderDrawColor(gRenderer, lighterRed, lighterGreen, lighterBlue, opacity);
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