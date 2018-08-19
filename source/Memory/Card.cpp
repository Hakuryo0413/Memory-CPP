#include "Card.h"

Card::Card(unsigned id, Card::Suit suit) :
	id(id),
	cardSuit(suit),
	cardSprite(cardBackTexture)
{
	setCardTexture(suit);
	cardAnimation = new CardAnimation(&cardSprite, animationTime, &cardTexture);
}

Card::~Card()
{
	delete cardAnimation;
}

sf::Texture & Card::cardBackTexture = AssetManager::getInstance()->getTexture("CardBack(90x160).png");
sf::Vector2u Card::size = cardBackTexture.getSize();

sf::Time Card::animationTime = sf::seconds(0.5f);

void Card::renderCard(sf::RenderWindow &window)
{
	window.draw(cardSprite);
}

void Card::updateCard(sf::Time deltaTime)
{
	cardAnimation->updateAnimated(deltaTime);
}

void Card::setPosition(sf::Vector2u deckPosition)
{
	cardSprite.setOrigin(float(size.x / 2), float(size.y / 2)); // set origin to center of card
	sf::Vector2f position;
	position.x = deckPosition.x * size.x + 10.0f * deckPosition.x + size.x / 2;  // position of card + origin offset + margin
	position.y = deckPosition.y * size.y + 10.0f * deckPosition.y + size.y / 2;
	cardSprite.setPosition(position);
}

bool Card::isCardClicked(sf::Vector2f mousePosition)
{
	return cardSprite.getGlobalBounds().contains(mousePosition);
}

void Card::flipCard()
{
	cardAnimation->startAnimation();
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

	cardTexture = AssetManager::getInstance()->getTexture(filename);
}

