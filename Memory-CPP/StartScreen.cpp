#include "stdafx.h"
#include "StartScreen.h"

StartScreen::StartScreen(StateManager * stateManager, StateManager::GameSettings * gameSettings) :
	GameScreen(stateManager, gameSettings)
{
	gameSettings->players.push_back(new Player("Tihana"));
	gameSettings->boardSize = { 4, 4 };
}

StartScreen::~StartScreen()
{
	delete gameSettings;
}

void StartScreen::renderScreen(sf::RenderWindow &window)
{
}

void StartScreen::updateScreen(sf::Time deltaTime)
{
}

void StartScreen::handleEnterPressed()
{
	stateManager->setGameSettings(gameSettings);
	stateManager->switchScreen(StateManager::Screen::Gameboard);
}
