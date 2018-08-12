#pragma once
#include "GameScreen.h"
#include <iostream>

class StartScreen :
	public GameScreen
{
public:
	StartScreen();
	~StartScreen();
	void renderScreen(sf::RenderWindow &window);
	void updateScreen(sf::Time deltaTime);
};

