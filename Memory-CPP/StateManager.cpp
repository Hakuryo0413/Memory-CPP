#include "stdafx.h"
#include "StateManager.h"
#include "GameScreen.h"
#include "StartScreen.h"
#include "GameBoard.h"
#include "EndScreen.h"

StateManager::StateManager() :
	gameSettings(new GameSettings)
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
		currentScreen = new StartScreen(this, gameSettings);
		break;
	case Screen::Gameboard:
		currentScreen = new GameBoard(this, gameSettings);
		break;
	case Screen::EndScreen:
		currentScreen = new EndScreen(this, gameSettings);
		break;
	default:
		break;
	}
}

void StateManager::setGameSettings(GameSettings * gameSettings)
{
	gameSettings = gameSettings;
}

StateManager::GameSettings * StateManager::getGameSettings()
{
	return gameSettings;
}

