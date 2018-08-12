#include "stdafx.h"
#include "EndScreen.h"

EndScreen::EndScreen(StateManager * stateManager, std::vector<Player*> players) :
	GameScreen(stateManager),
	players(players)
{
	sortPlayers();
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

void EndScreen::sortPlayers()
{
	std::sort(players.begin(), players.end(), comparePlayers);
}

bool EndScreen::comparePlayers(Player * firstPlayer, Player * secondPlayer)
{
	return (firstPlayer->score < secondPlayer->score);
}
