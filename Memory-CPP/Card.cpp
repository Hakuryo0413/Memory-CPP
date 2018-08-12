#include "stdafx.h"
#include "Card.h"

Card::Card(unsigned id, Card::Suit suit) :
	id(id),
	cardSuit(suit),
	cardSprite(cardBackTexture),
	cardTexture(),
	isFlipped(false),
	spinning(false),
	elapsedTime(sf::Time::Zero)
{
	setCardTexture(suit);
}

Card::~Card()
{
}

sf::Texture & Card::cardBackTexture = TextureManager::getInstance()->getTexture("CardBack(90x160).png");
sf::Vector2u Card::size = cardBackTexture.getSize();

sf::Time Card::animationTime = sf::seconds(0.5);
const double Card::pi = std::acos(-1);

void Card::renderCard(sf::RenderWindow &window)
{
	window.draw(cardSprite);
}

void Card::updateCard(sf::Time deltaTime)
{
	if (!spinning)
	{
		return;
	}

	elapsedTime += deltaTime;
	if (elapsedTime >= animationTime)
	{
		spinning = false;
		isFlipped = false;
		elapsedTime = sf::Time::Zero;
		return;
	}

	if (elapsedTime >= animationTime / 2.f && !isFlipped)
	{
		toggleTexture();
		isFlipped = true;
	}

	if (elapsedTime < animationTime / 2.f) {
		float scale = 1.f - elapsedTime / (animationTime / 2.f);
		cardSprite.setScale(std::sin(scale * pi / 2), 1);
	}
	else {
		float scale = (elapsedTime - (animationTime / 2.f)) / (animationTime / 2.f);
		cardSprite.setScale(std::sin(scale * pi / 2), 1);
	}
}

void Card::setPosition(sf::Vector2u deckPosition)
{
	cardSprite.setOrigin(float(size.x/2), float(size.y/2)); // set origin to center of card
	sf::Vector2f position;
	position.x = deckPosition.x * size.x + 10.0f * deckPosition.x + size.x/2;  // position of card + origin offset + margin
	position.y = deckPosition.y * size.y + 10.0f * deckPosition.y + size.y/2;
	cardSprite.setPosition(position);
}

bool Card::isCardClicked(sf::Vector2f mousePosition)
{
	return cardSprite.getGlobalBounds().contains(mousePosition);
}

void Card::flipCard()
{
	if (!spinning)
	{
		spinning = true;
	}
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
		filename = "AirCard(90x160).png";
		break;
	case Card::Earth:
		filename = "EarthCard(90x160).png";
		break;
	case Card::Fire:
		filename = "FireCard(90x160).png";
		break;
	case Card::Water:
		filename = "WaterCard(90x160).png";
		break;
	default:
		break;
	}

	cardTexture = TextureManager::getInstance()->getTexture(filename);
}

void Card::toggleTexture()
{
	if (cardSprite.getTexture() == & cardBackTexture)
	{
		cardSprite.setTexture(cardTexture);
	}
	else
	{
		cardSprite.setTexture(cardBackTexture);
	}
}
