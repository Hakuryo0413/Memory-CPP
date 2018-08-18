#pragma once
#include <SFML/Graphics.hpp>
#include "StateManager.h"

class GameScreen
{
public:
	GameScreen();
	GameScreen(StateManager * stateManager);
	~GameScreen();

	virtual void renderScreen(sf::RenderWindow &window);
	virtual void updateScreen(sf::Time deltaTime) = 0;
	virtual void handleMouseClick(sf::Vector2f mousePosition);
	virtual void handleTextEntry(sf::Event::TextEvent textEvent);

protected:
	static sf::Sprite background;
	StateManager * stateManager;
};

