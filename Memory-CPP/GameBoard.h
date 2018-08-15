#pragma once
#include <vector>
#include <algorithm>
#include <random>
#include "GameScreen.h"
#include "EndScreen.h"
#include "Card.h"
#include "Player.h"
#include "SetTimeout.h"

class GameBoard :
	public GameScreen
{
public:
	GameBoard(StateManager * stateManager);
	~GameBoard();

	void renderScreen(sf::RenderWindow &window);
	void updateScreen(sf::Time deltaTime);
	void handleMouseClick(sf::Vector2f mousePosition);

	// TODO remove for release
	void handleEnterPressed();
private:
	std::vector<Card*> deck;
	std::vector<Card*> revealedCards;
	std::vector<Card*> solvedCards;
	std::vector<Card*> createDeck(sf::Vector2u boardSize);

	std::vector<Player *> players;
	Player * currentPlayer;
	void callNextPlayer();

	void renderDeck(sf::RenderWindow &window);
	void updateDeck(sf::Time deltaTime);
	void renderPlayers(sf::RenderWindow &window);

	Card* cardClicked(sf::Vector2f mousePosition);
	void handleCardClick(Card * clickedCard);
	void resolvePair(bool isPair);
	void finishGame();

	SetTimeout * resolveTimeout;
	sf::Time resolveDelayTime;
};