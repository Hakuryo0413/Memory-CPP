#pragma once
#include <vector>
#include <algorithm>
#include <random>
#include "GameScreen.h"
#include "Card.h"
class GameBoard :
	public GameScreen
{
public:
	GameBoard(sf::Vector2u boardSize);
	~GameBoard();

	sf::Vector2u boardSize;
	void renderScreen(sf::RenderWindow &window);
	void handleMouseClick(sf::Vector2f mousePosition);
private:
	std::vector<Card*> deck;
	std::vector<Card*> revealedCards;
	std::vector<Card*> solvedCards;
	std::vector<Card*> createDeck(sf::Vector2u boardSize);
	void renderDeck(sf::RenderWindow &window);
	Card* cardClicked(sf::Vector2f mousePosition);
	void resolvePair();
};