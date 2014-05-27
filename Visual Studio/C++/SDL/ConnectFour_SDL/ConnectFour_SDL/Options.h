#pragma once
#include "Menu.h"

class Options : public Menu {
private:
	std::vector<Button> menuButtons;
	std::string menuName;
public:
	Options(std::string menuName);
	~Options();
	virtual void draw(SDL_Renderer* gRenderer);
	virtual std::string checkEvents(SDL_Event* e);
	virtual void setName(std::string NameIn);
	virtual std::string getName();
};