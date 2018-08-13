#pragma once
#include "GameScreen.h"
#include "GameBoard.h"
#include "Player.h"

class StartScreen :
	public GameScreen
{
public:
	StartScreen(StateManager * stateManager, StateManager::GameSettings * gameSettings);
	~StartScreen();
	void renderScreen(sf::RenderWindow &window);
	void updateScreen(sf::Time deltaTime);
	void handleEnterPressed();
};

