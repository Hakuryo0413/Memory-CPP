#include "stdafx.h"
#include "EndScreen.h"

EndScreen::EndScreen(StateManager * stateManager, std::vector<Player*> players) :
	GameScreen(stateManager),
	players(players)
{
	displayPlayerScore();
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
	stateManager->switchScreen(new StartScreen(stateManager));
}

void EndScreen::displayPlayerScore()
{
	sortPlayers();
	setWinner();
	positionTags();
}

void EndScreen::sortPlayers()
{
	std::sort(players.begin(), players.end(), comparePlayers);
}

bool EndScreen::comparePlayers(Player * firstPlayer, Player * secondPlayer)
{
	return (firstPlayer->score < secondPlayer->score);
}

void EndScreen::setWinner()
{
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
		player[i]->playerTag.setPosition(playerListHeight, 100.f);
		player[i]->playerScore.setPosition(playerListHeight, 300.f);
		playerListHeight += player[i]->playerTag.getCharacterSize() + 16.f;
	}
}

void renderPlayerList(sf::RenderWindow & window)
{
	for (size_t i = 0; i < players.size(); i++)
	{
		player[i]->renderPlayerTag(window);
		player[i]->renderPlayerScore(window);
	}
}
