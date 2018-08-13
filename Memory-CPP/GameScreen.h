#pragma once
#include <SFML/Graphics.hpp>
#include "StateManager.h"

class GameScreen
{
public:
	GameScreen();
	GameScreen(StateManager * stateManager, StateManager::GameSettings * gameSettings);
	~GameScreen();

	virtual void renderScreen(sf::RenderWindow &window) = 0;
	virtual void updateScreen(sf::Time deltaTime) = 0;
	virtual void handleMouseClick(sf::Vector2f mousePosition);
	virtual void handleEnterPressed();

protected:
	StateManager * stateManager;
	StateManager::GameSettings * gameSettings;
};

