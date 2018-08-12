#include "stdafx.h"
#include "StartScreen.h"

StartScreen::StartScreen(StateManager * stateManager) :
	GameScreen(stateManager),
	boardSize(4, 4)
{
	players.push_back(new Player("Tihana"));
}

StartScreen::~StartScreen()
{
	for (size_t i = 0; i < players.size(); i++)
	{
		delete players[i];
	}
}

void StartScreen::renderScreen(sf::RenderWindow &window)
{
}

void StartScreen::updateScreen(sf::Time deltaTime)
{
}

void StartScreen::handleEnterPressed()
{
	stateManager->switchScreen(new GameBoard(stateManager, boardSize, players));
}
