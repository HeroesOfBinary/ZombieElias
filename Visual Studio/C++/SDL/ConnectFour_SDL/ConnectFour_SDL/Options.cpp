#pragma once
#include "Options.h"
#include <sstream>
//enum MenuButtons { StartGameButton, ExitButton };

Options::Options(std::string menuName)
{

	setName(menuName);
	menuButtons = std::vector<Button>();
	menuButtons.push_back(Button(73, 79, 230, 255, 400, 100, 100, 100, "Option1", "Option 1"));
	menuButtons.push_back(Button(135, 230, 84, 255, 400, 100, 100, 210, "Option2", "Option2"));
	menuButtons.push_back(Button(230, 78, 68, 255, 400, 100, 100, 320, "Back", "Go Back"));
};

Options::~Options()
{
}

void Options::draw(SDL_Renderer* gRenderer)
{

	for (std::vector<Button>::iterator it = menuButtons.begin(); it != menuButtons.end(); ++it)
	{
		it->draw(gRenderer);
	}
}


std::string Options::checkEvents(SDL_Event* e)
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

void Options::setName(std::string NameIn)
{
	menuName = NameIn;
}

std::string Options::getName()
{
	return menuName;
}
