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
	delete gameSettings;
}

void StateManager::switchScreen(Screen nextScreen)
{
	if (currentScreen != nullptr)
	{
		delete currentScreen;
	}
	
	switch (nextScreen)
	{
	case Screen::StartScreen:
		currentScreen = new StartScreen(this);
		break;
	case Screen::Gameboard:
		currentScreen = new GameBoard(this);
		break;
	case Screen::EndScreen:
		currentScreen = new EndScreen(this);
		break;
	default:
		break;
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

