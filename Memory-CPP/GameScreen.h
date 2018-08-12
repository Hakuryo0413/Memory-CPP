#pragma once
#include <SFML/Graphics.hpp>

class GameScreen
{
public:
	GameScreen();
	~GameScreen();
	virtual void renderScreen(sf::RenderWindow &window) = 0;
	virtual void updateScreen(sf::Time deltaTime) = 0;
	virtual void handleMouseClick(sf::Vector2f mousePosition);
};

