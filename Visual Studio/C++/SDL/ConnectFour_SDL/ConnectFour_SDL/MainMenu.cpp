#pragma once
#include "MainMenu.h"
#include <sstream>
//enum MenuButtons { StartGameButton, ExitButton };

MainMenu::MainMenu(std::string menuName)
	{

		setName(menuName);
		menuButtons = std::vector<Button>();
		menuButtons.push_back(Button(73, 79, 230, 255, 400, 100, 100, 100, "StartGame", "Start Game",40));
		menuButtons.push_back(Button(135, 230, 84, 255, 400, 100, 100, 210,"Options","Options",40));
		menuButtons.push_back(Button(230, 90, 81, 255, 400, 100, 100, 320,"Exit","Exit Game",40));
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
	}
	
	
	std::string MainMenu::checkEvents(SDL_Event* e)
	{
		bool buttonExecuted;
		std::string buttonName;
		std::string buttonToReturn;
		for (std::vector<Button>::iterator it = menuButtons.begin(); it != menuButtons.end(); ++it)
		{
			buttonExecuted = it->checkEvents(e);
			
			if (buttonExecuted == true)
			{
				buttonToReturn = it->getButtonName();
			}
		}

		if (buttonToReturn.empty())
		{
			return "";
		}
		else
		{
			return buttonToReturn;
		}
	}

	void MainMenu::setName(std::string NameIn)
	{
		menuName = NameIn;
	}
	
	std::string MainMenu::getName()
	{
		return menuName;
	}
