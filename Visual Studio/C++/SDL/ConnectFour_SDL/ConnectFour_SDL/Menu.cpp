#pragma once
#include "Menu.h"

Menu::Menu(){};
Menu::~Menu(){};

void Menu::draw(SDL_Renderer* gRenderer){};
std::string Menu::checkEvents(SDL_Event* e){};
void Menu::setName(std::string NameIn){};
std::string Menu::getName(){};
