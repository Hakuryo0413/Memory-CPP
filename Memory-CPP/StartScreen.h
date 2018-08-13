#pragma once
#include "GameScreen.h"
#include "GameBoard.h"
#include "Player.h"

class StartScreen :
	public GameScreen
{
public:
	StartScreen(StateManager * stateManager);
	~StartScreen();
	void renderScreen(sf::RenderWindow &window);
	void updateScreen(sf::Time deltaTime);
	void handleEnterPressed();
private:
	std::vector<Player *> players;
	sf::Vector2u boardSize;
};

