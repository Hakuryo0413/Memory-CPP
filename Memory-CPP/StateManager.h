#pragma once
#include "GameScreen.h"
#include "Player.h"

class GameScreen;

class StateManager
{
public:
	StateManager();
	~StateManager();

	void switchScreen(GameScreen* nextScreen);
	GameScreen* currentScreen;
	std::vector<Player*> players;
	sf::Vector2u boardSize;
};

