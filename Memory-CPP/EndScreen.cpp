#include "stdafx.h"
#include "EndScreen.h"

EndScreen::EndScreen(StateManager * stateManager) :
	GameScreen(stateManager),
	players(stateManager->gameSettings->players)
{
	displayPlayerScores();
}

EndScreen::~EndScreen()
{
}

void EndScreen::renderScreen(sf::RenderWindow & window)
{
	renderPlayerList(window);
	renderPlayAgainButton(window);
}

void EndScreen::updateScreen(sf::Time deltaTime)
{
}

void EndScreen::handleEnterPressed()
{
	stateManager->clearSettings();
	stateManager->switchScreen(StateManager::Screen::StartScreen);
}

void EndScreen::displayPlayerScores()
{
	sortPlayers();
	setWinner();
	positionTags();
}

void EndScreen::sortPlayers()
{
	std::sort(players.begin(), players.end(), sortByScore);
}

bool EndScreen::sortByScore(const Player * firstPlayer, const Player * secondPlayer)
{
	return (firstPlayer->score < secondPlayer->score);
}

void EndScreen::setWinner()
{
	if (players.size() == 1)
	{
		return;
	}
	for (size_t i = 0; i < players.size(); i++)
	{
		players[i]->playerTag.setCharacterSize(48);
		players[i]->playerScore.setCharacterSize(48);
		if (players[i]->score > players[i++]->score)
		{
			break;
		}
	}
}

void EndScreen::positionTags()
{
	float playerListHeight = 100.f;
	for (size_t i = 0; i < players.size(); i++)
	{
		players[i]->playerTag.setPosition(playerListHeight, 100.f);
		players[i]->playerScore.setPosition(playerListHeight, 300.f);
		playerListHeight += players[i]->playerTag.getCharacterSize() + 16.f;
	}
}

void EndScreen::renderPlayerList(sf::RenderWindow & window)
{
	for (size_t i = 0; i < players.size(); i++)
	{
		players[i]->renderPlayerTag(window);
		players[i]->renderPlayerScore(window);
	}
}

void EndScreen::renderPlayAgainButton(sf::RenderWindow & window)
{
}
