#include "stdafx.h"
#include "StateManager.h"


StateManager::StateManager()
{
}

StateManager::~StateManager()
{
	delete currentScreen;
}

void StateManager::switchScreen(GameScreen * nextScreen)
{
	if (currentScreen != nullptr)
	{
		delete currentScreen;
	}
	currentScreen = nextScreen;
}
