#pragma once
#include "GameScreen.h"
#include "StartScreen.h"
#include "Player.h"
#include "Button.h"

class EndScreen :
	public GameScreen
{
public:
	EndScreen(StateManager * stateManager);
	~EndScreen();

	virtual void renderScreen(sf::RenderWindow & window);
	virtual void updateScreen(sf::Time deltaTime);
	virtual void handleMouseClick(sf::Vector2f mousePosition);
private:
	void renderPlayerList(sf::RenderWindow & window);
	void renderPlayAgainButton(sf::RenderWindow & window);
	void updatePlayerList(sf::Time deltaTime);
	void displayPlayerScores();
	void sortPlayers();
	void setWinner();
	void positionTags();
	void fadeInPlayerList();
	static bool sortByScore(const Player * firstPlayer, const Player * const secondPlayer);
	std::vector<Player *> players;
	Button * playAgainButton;
	void restartGame();
};