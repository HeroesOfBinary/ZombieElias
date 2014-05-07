#pragma once
#include "MainMenu.h"
#include <SDL.h>
#include "Button.cpp"
#include <vector>





//enum MenuButtons { StartGameButton, ExitButton };
class MainMenu {
private:
	std::vector<Button> menuButtons;
public:

	MainMenu()
	{
		menuButtons.push_back(Button(100, 100, 100, 255, 100, 100, 100, 100));
		menuButtons.push_back(Button(100, 100, 100, 255, 100, 100, 100, 210));
		menuButtons.push_back(Button(100, 100, 100, 255, 100, 100, 100, 310));
		//StartGameButton(200,200,200,255,100,100,100,100);
		//SettingsButton = new Button(200, 200, 200, 255, 100, 100, 100, 210);
		//ExitButton = new Button(200,200, 200, 255, 100, 100, 100, 320);
	};



	virtual void draw(SDL_Renderer* gRenderer)
	{
		for (std::vector<Button>::iterator it = menuButtons.begin(); it != menuButtons.end(); ++it) 
		{
			it->draw(gRenderer);
		}

		//StartGameButton.draw();
	}
	
	
	virtual void checkEvents(SDL_Event* e)
	{
		for (std::vector<Button>::iterator it = menuButtons.begin(); it != menuButtons.end(); ++it)
		{
			it->checkEvents(e);
		}
	}

};