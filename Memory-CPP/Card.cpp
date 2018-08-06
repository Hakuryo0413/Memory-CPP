#include "stdafx.h"
#include "Card.h"

Card::Card(unsigned id) : id(id)
{
	cardShape.setSize(size);
	cardShape.setFillColor(sf::Color(28, 110, 140));
}


Card::~Card()
{
}

sf::Vector2f Card::size = { 75.0f, 100.0f };

void Card::renderCard(sf::RenderWindow &window)
{
	window.draw(cardShape);
}

void Card::setPosition(sf::Vector2u deckPosition)
{
	sf::Vector2f position;
	position.x = float(deckPosition.x) * size.x + 10.0f * deckPosition.x;
	position.y = float(deckPosition.y) * size.y + 10.0f * deckPosition.y;
	cardShape.setPosition(position);
}

bool Card::isCardClicked(sf::Vector2f mousePosition)
{
	return cardShape.getGlobalBounds().contains(mousePosition);
}

void Card::revealCard()
{
	std::cout << id << std::endl;
}

Card::Suit Card::getSuit()
{
	return cardSuit;
}
