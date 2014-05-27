#pragma once
#include "Button.h"
#include <vector>

class Menu
{
private:
	std::string menuName;
public:
	Menu();
	~Menu();

	virtual void draw(SDL_Renderer* gRenderer) = 0;
	virtual std::string checkEvents(SDL_Event* e) = 0;
	virtual void setName(std::string NameIn) = 0;
	virtual std::string getName() = 0;

};
