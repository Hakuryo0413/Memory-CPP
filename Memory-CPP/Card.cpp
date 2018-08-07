#include "stdafx.h"
#include "Card.h"

Card::Card(unsigned id, Card::Suit suit) : id(id), cardSuit(suit)
{
	cardShape.setSize(size);
	airCardTexture.loadFromFile(GRAPHICS_PATH "AirCard.png");
	earthCardTexture.loadFromFile(GRAPHICS_PATH "EarthCard.png");
	airCardTexture.loadFromFile(GRAPHICS_PATH "FireCard.png");
	waterCardTexture.loadFromFile(GRAPHICS_PATH "WaterCard.png");
}

Card::~Card()
{
}

sf::Vector2f Card::size = { 50.0f, 95.0f };
sf::Texture Card::airCardTexture;
sf::Texture Card::earthCardTexture;
sf::Texture Card::fireCardTexture;
sf::Texture Card::waterCardTexture;


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
	switch (cardSuit)
	{
	case Card::Suit::Air:
		cardShape.setTexture(&airCardTexture);
		break;
	case Card::Suit::Earth:
		cardShape.setTexture(&earthCardTexture);
		break;
	case Card::Suit::Fire:
		cardShape.setTexture(&fireCardTexture);
		break;
	case Card::Suit::Water:
		cardShape.setTexture(&waterCardTexture);
		break;
	default:
		break;
	}
}

Card::Suit Card::getSuit()
{
	return cardSuit;
}
