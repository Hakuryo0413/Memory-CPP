#include "stdafx.h"
#include "GameBoard.h"


GameBoard::GameBoard(StateManager * stateManager, sf::Vector2u boardSize, std::vector<Player*> players) :
	GameScreen(stateManager),
	boardSize(boardSize),
	players(players),
	resolving(false),
	resolveDelayTime(sf::seconds(1)),
	elapsedTime(sf::Time::Zero)
{
	deck = createDeck(boardSize);
}


GameBoard::~GameBoard()
{
}

void GameBoard::renderScreen(sf::RenderWindow &window)
{
	renderDeck(window);
	renderPlayers(window);
}

void GameBoard::updateScreen(sf::Time deltaTime)
{
	if (resolving)
	{
		elapsedTime += deltaTime;
		if (elapsedTime >= resolveDelayTime)
		{
			elapsedTime = sf::Time::Zero;
			resolving = false;
			resolvePair();
		}
	}
	updateDeck(deltaTime);
}

void GameBoard::handleMouseClick(sf::Vector2f mousePosition)
{
	if (resolving)		// disable click events while resolving
	{
		return;
	}
	Card * clickedCard = cardClicked(mousePosition);
	if (clickedCard)
	{
		handleCardClick(clickedCard);
	}
}

std::vector<Card*> GameBoard::createDeck(sf::Vector2u boardSize)
{
	std::vector<Card*> deck;
	unsigned deckSize = boardSize.x * boardSize.y;
	unsigned cardsPerSuit = deckSize / Card::Suit::COUNT;
	unsigned cardIndex = 0;

	for (unsigned i = 0; i < Card::Suit::COUNT; i++) {
		for (unsigned j = 0; j < cardsPerSuit; j++)
		{
			Card* card = new Card(cardIndex, static_cast<Card::Suit>(i));
			deck.push_back(card);
			cardIndex++;
		}
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

void GameBoard::updateDeck(sf::Time deltaTime)
{
	for (size_t i = 0; i < deck.size(); i++)
	{
		deck[i]->updateCard(deltaTime);
	}
}

void GameBoard::renderPlayers(sf::RenderWindow & window)
{
	for (size_t i = 0; i < players.size(); i++)
	{
		players[i]->renderPlayerTag(window);
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

void GameBoard::handleCardClick(Card * clickedCard)
{
	std::vector<Card*>::iterator itSolved = std::find(solvedCards.begin(), solvedCards.end(), clickedCard);
	if (itSolved != solvedCards.end())			// ignore click on solved cards
	{
		return;
	}

	std::vector<Card*>::iterator itRevealed = std::find(revealedCards.begin(), revealedCards.end(), clickedCard);
	if (itRevealed == revealedCards.end())		// if card not already revealed, reveal it
	{
		revealedCards.push_back(clickedCard);
		clickedCard->flipCard();
	}

	if (revealedCards.size() == 2)				// when two cards are revealed, start resolving with time delay
	{
		resolving = true;
	}
	//else if (revealedCards.size() > 2)
	//{
	//	revealedCards.erase(revealedCards.begin() + 1, revealedCards.end());
	//	resolving = true;
	//}
}

void GameBoard::resolvePair()
{
	if (revealedCards[0]->getSuit() == revealedCards[1]->getSuit())
	{
		solvedCards.insert(solvedCards.end(), revealedCards.begin(), revealedCards.end());
		revealedCards.clear();

		if (solvedCards.size() == deck.size())
		{
			finishGame();
		}
	}
	else
	{
		for (size_t i = 0; i < revealedCards.size(); i++)
		{
			revealedCards[i]->flipCard();
		}
		revealedCards.clear();
	}
}

void GameBoard::finishGame()
{
	stateManager->switchScreen(new EndScreen(stateManager, players));
}


