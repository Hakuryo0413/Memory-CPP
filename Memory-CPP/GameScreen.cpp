#include "stdafx.h"
#include "GameScreen.h"

GameScreen::GameScreen()
{
}

GameScreen::GameScreen(StateManager * stateManager, StateManager::GameSettings * gameSettings) :
	stateManager(stateManager),
	gameSettings(gameSettings)
{
}

GameScreen::~GameScreen()
{
}

void GameScreen::handleMouseClick(sf::Vector2f mousePosition)
{
}

void GameScreen::handleEnterPressed()
{
}

