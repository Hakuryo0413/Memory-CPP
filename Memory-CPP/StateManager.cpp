#include "stdafx.h"
#include "StateManager.h"
#include "GameScreen.h"
#include "StartScreen.h"
#include "GameBoard.h"
#include "EndScreen.h"

StateManager::StateManager() :
	gameSettings(new GameSettings())
{
}

StateManager::~StateManager()
{
	delete currentScreen;
	delete nextScreen;
	delete gameSettings;
}

void StateManager::switchScreen(Screen newScreen)
{
	if (nextScreen != nullptr)
	{
		delete nextScreen;
		nextScreen = nullptr;
	}

	switch (newScreen)
	{
	case Screen::StartScreen:
		nextScreen = new StartScreen(this);
		break;
	case Screen::Gameboard:
		nextScreen = new GameBoard(this);
		break;
	case Screen::EndScreen:
		nextScreen = new EndScreen(this);
		break;
	default:
		break;
	}

	if (nextScreen != nullptr)
	{
		std::swap(currentScreen, nextScreen);
	}
}

std::vector<Player*> StateManager::getPlayers()
{
	return gameSettings->players;
}

void StateManager::setPlayers(std::vector<Player*> players)
{
	gameSettings->players = players;
}

void StateManager::setBoardSize(sf::Vector2u boardSize)
{
	gameSettings->boardSize = boardSize;
}

void StateManager::clearSettings()
{
	gameSettings->players.clear();
	gameSettings->boardSize = { 4, 4 };
}

