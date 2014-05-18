#pragma once
#include "MainMenu.h"
#include <sstream>
//enum MenuButtons { StartGameButton, ExitButton };

MainMenu::MainMenu(std::string menuName)
	{

		setName(menuName);
		menuButtons = std::vector<Button>();
		menuButtons.push_back(Button(73, 79, 230, 255, 400, 100, 100, 100, "StartGame", "StartGame"));
		menuButtons.push_back(Button(135, 230, 84, 255, 400, 100, 100, 210,"Options","Options"));
		menuButtons.push_back(Button(230, 90, 81, 255, 400, 100, 100, 320,"Exit","Exit Game"));
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
		for (std::vector<Button>::iterator it = menuButtons.begin(); it != menuButtons.end(); ++it)
		{
			buttonExecuted = it->checkEvents(e);
			
			if (buttonExecuted == true)
			{
				return it->getButtonName();
			}
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
