#pragma once
#include "MainMenu.h"
#include <sstream>
//enum MenuButtons { StartGameButton, ExitButton };

	MainMenu::MainMenu()
	{
		menuButtons = std::vector<Button>();
		menuButtons.push_back(Button(73, 79, 255, 255, 400, 100, 100, 100, "StartGame", "StartGame"));
		menuButtons.push_back(Button(135, 255, 84, 255, 400, 100, 100, 210,"Options","Options"));
		menuButtons.push_back(Button(255, 90, 81, 255, 400, 100, 100, 320,"Exit","Exit Game"));
		//StartGameButton(200,200,200,255,100,100,100,100);
		//SettingsButton = new Button(200, 200, 200, 255, 100, 100, 100, 210);
		//ExitButton = new Button(200,200, 200, 255, 100, 100, 100, 320);
	};

	MainMenu::~MainMenu()
	{
	}

	void MainMenu::draw(SDL_Renderer* gRenderer)
	{
		for (std::vector<Button>::iterator it = menuButtons.begin(); it != menuButtons.end(); ++it) 
		{
			it->draw(gRenderer);
		}

		//StartGameButton.draw();
	}
	
	
	void MainMenu::checkEvents(SDL_Event* e)
	{
	
		for (std::vector<Button>::iterator it = menuButtons.begin(); it != menuButtons.end(); ++it)
		{
			it->checkEvents(e);
		}
	}
