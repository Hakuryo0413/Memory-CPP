#pragma once
#include <SFML/Graphics.hpp>

class GameScreen
{
public:
	GameScreen();
	~GameScreen();
	virtual void renderScreen(sf::RenderWindow &window) = 0;
};

