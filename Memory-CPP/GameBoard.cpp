#include "stdafx.h"
#include "GameBoard.h"


GameBoard::GameBoard(sf::Vector2u boardSize) : boardSize(boardSize)
{
	deck = createDeck(boardSize);
}


GameBoard::~GameBoard()
{
}

void GameBoard::renderScreen(sf::RenderWindow &window)
{
	renderDeck(window);
}

std::vector<Card*> GameBoard::createDeck(sf::Vector2u boardSize)
{
	std::vector<Card*> deck;
	for (unsigned i = 0; i < boardSize.x * boardSize.y; i++)
	{
		Card* card = new Card(i);
		deck.push_back(card);
	}
	std::default_random_engine seed = std::default_random_engine{};
	std::shuffle(std::begin(deck), std::end(deck), seed);
	int index = 0;
	for (unsigned i = 0; i < boardSize.x; i++)
	{
		for (unsigned j = 0; j < boardSize.y; j++)
		{
			sf::Vector2u position(i, j);
			deck[index]->setPosition(position);
			index++;
		}
	}
	return deck;
}

void GameBoard::renderDeck(sf::RenderWindow &window)
{
	for (size_t i = 0; i < deck.size(); i++)
	{
		deck[i]->renderCard(window);
	}
}


