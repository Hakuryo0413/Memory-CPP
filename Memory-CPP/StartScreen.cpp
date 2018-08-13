#include "stdafx.h"
#include "StartScreen.h"

StartScreen::StartScreen(StateManager * stateManager) :
	GameScreen(stateManager)
{
	players.push_back(new Player("Tihana"));
	boardSize = { 4, 4 };
}

StartScreen::~StartScreen()
{
}

void StartScreen::renderScreen(sf::RenderWindow &window)
{
}

void StartScreen::updateScreen(sf::Time deltaTime)
{
}

void StartScreen::handleEnterPressed()
{
	stateManager->setPlayers(players);
	stateManager->setBoardSize(boardSize);
	stateManager->switchScreen(StateManager::Screen::Gameboard);
}
