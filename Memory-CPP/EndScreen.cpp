#include "stdafx.h"
#include "EndScreen.h"

EndScreen::EndScreen(StateManager * stateManager, std::vector<Player*> players) :
	GameScreen(stateManager),
	players(players)
{
}

EndScreen::~EndScreen()
{
}

void EndScreen::renderScreen(sf::RenderWindow & window)
{
}

void EndScreen::updateScreen(sf::Time deltaTime)
{
}

void EndScreen::handleEnterPressed()
{
	stateManager->switchScreen(new StartScreen(stateManager));
}
