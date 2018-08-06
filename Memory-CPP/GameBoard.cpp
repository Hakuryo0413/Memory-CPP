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

void GameBoard::handleMouseClick(sf::Vector2f mousePosition)
{
	Card * clickedCard = cardClicked(mousePosition);
	if (clickedCard)
	{
		std::vector<Card*>::iterator it = std::find(revealedCards.begin(), revealedCards.end(), clickedCard);
		if (it == revealedCards.end())
		{
			revealedCards.push_back(clickedCard);
			clickedCard->revealCard();
		}
		if (revealedCards.size() == 2)
		{
			// setTimeout(() = > this.resolvePair(), 1000);
		}
		else if (revealedCards.size() > 2)
		{
			resolvePair();
			revealedCards.push_back(clickedCard);
			clickedCard->revealCard();
		}
	}
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

Card * GameBoard::cardClicked(sf::Vector2f mousePosition)
{
	for (size_t i = 0; i < deck.size(); i++)
	{
		if (deck[i]->isCardClicked(mousePosition))
		{
			return deck[i];
			break;
		}
	}
	return nullptr;
}

void GameBoard::resolvePair()
{
	if (revealedCards[0]->getSuit() == revealedCards[1]->getSuit())
	{
		solvedCards.push_back(revealedCards[0]);
		solvedCards.push_back(revealedCards[1]);
	}
}


