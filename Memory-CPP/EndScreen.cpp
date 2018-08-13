#include "stdafx.h"
#include "EndScreen.h"

EndScreen::EndScreen(StateManager * stateManager, StateManager::GameSettings * gameSettings) :
	GameScreen(stateManager, gameSettings)
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
	gameSettings->clearSettings();
	stateManager->switchScreen(StateManager::Screen::StartScreen);
}

void EndScreen::setPlayers(std::vector<Player*> players)
{
	players = gameSettings->players;
}

void EndScreen::displayPlayerScores()
{
	sortPlayers();
	setWinner();
	positionTags();
}

void EndScreen::sortPlayers()
{
	std::sort(gameSettings->players.begin(), gameSettings->players.end(), sortByScore);
}

bool EndScreen::sortByScore(const Player * firstPlayer, const Player * secondPlayer)
{
	return (firstPlayer->score < secondPlayer->score);
}

void EndScreen::setWinner()
{
	if (gameSettings->players.size() == 1)
	{
		return;
	}
	for (size_t i = 0; i < gameSettings->players.size(); i++)
	{
		gameSettings->players[i]->playerTag.setCharacterSize(48);
		gameSettings->players[i]->playerScore.setCharacterSize(48);
		if (gameSettings->players[i]->score > gameSettings->players[i++]->score)
		{
			break;
		}
	}
}

void EndScreen::positionTags()
{
	float playerListHeight = 100.f;
	for (size_t i = 0; i < gameSettings->players.size(); i++)
	{
		gameSettings->players[i]->playerTag.setPosition(playerListHeight, 100.f);
		gameSettings->players[i]->playerScore.setPosition(playerListHeight, 300.f);
		playerListHeight += gameSettings->players[i]->playerTag.getCharacterSize() + 16.f;
	}
}

void EndScreen::renderPlayerList(sf::RenderWindow & window)
{
	for (size_t i = 0; i < gameSettings->players.size(); i++)
	{
		gameSettings->players[i]->renderPlayerTag(window);
		gameSettings->players[i]->renderPlayerScore(window);
	}
}

void EndScreen::renderPlayAgainButton(sf::RenderWindow & window)
{
}
