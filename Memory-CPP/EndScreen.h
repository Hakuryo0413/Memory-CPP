#pragma once
#include "GameScreen.h"
#include "StartScreen.h"
#include "Player.h"

class EndScreen :
	public GameScreen
{
public:
	EndScreen(StateManager * stateManager, std::vector<Player*> players);
	~EndScreen();

	void renderScreen(sf::RenderWindow &window);
	void updateScreen(sf::Time deltaTime);
	void handleEnterPressed();
private:
	std::vector<Player*> players;
	void renderPlayerList(sf::RenderWindow & window);
	void renderPlayAgainButton(sf::RenderWindow & window);
	void displayPlayerScores();
	void sortPlayers();
	void setWinner();
	void positionTags();
	bool comparePlayers(Player * firstPlayer, Player * secondPlayer);
};

