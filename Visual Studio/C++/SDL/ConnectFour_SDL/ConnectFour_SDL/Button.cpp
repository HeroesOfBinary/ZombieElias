#pragma once
#include <SDL.h>

class Button
{
	Button(){

	};

	virtual void draw(SDL_Renderer* gRenderer)
	{

	}
	virtual void checkEvents(SDL_Event e)
	{

	}
	virtual void setBaseColor(int red, int green, int blue, int opacity)
	{

	}
	virtual void setUpColor(int red, int green, int blue, int opacity)
	{

	}
	virtual void setDownColor(int red, int green, int blue, int opacity)
	{

	}
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