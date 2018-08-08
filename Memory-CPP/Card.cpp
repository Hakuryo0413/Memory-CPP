#include "stdafx.h"
#include "Card.h"

Card::Card(unsigned id, Card::Suit suit) : 
	id(id), 
	cardSuit(suit),
	cardShape(),
	cardTexture()
{
	cardShape.setSize(size);
	setCardTexture(suit);
}

Card::~Card()
{
}

sf::Vector2f Card::size = { 50.0f, 95.0f };

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
	cardShape.setTexture(&cardTexture);
}

Card::Suit Card::getSuit()
{
	return cardSuit;
}

void Card::setCardTexture(Suit suit)
{
	std::string filename;
	switch (suit)
	{
	case Card::Air:
		filename = "AirCard.png";
		break;
	case Card::Earth:
		filename = "EarthCard.png";
		break;
	case Card::Fire:
		filename = "FireCard.png";
		break;
	case Card::Water:
		filename = "WaterCard.png";
		break;
	default:
		break;
	}

	cardTexture = TextureManager::getTextureManager()->getTexture(filename);
}
