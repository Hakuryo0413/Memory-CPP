#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "AssetManager.h"
#include "CardAnimation.h"
class Card
{
public:
	enum Suit
	{
		Air, Earth, Fire, Water, COUNT
	};

	Card(unsigned id, Suit suit);
	~Card();

	void renderCard(sf::RenderWindow & window);
	void updateCard(sf::Time deltaTime);
	void setPosition(sf::Vector2u deckPosition);
	bool isCardClicked(sf::Vector2f mousePosition);
	void flipCard();
	Suit getSuit();
	static sf::Vector2u getSize();

private:
	unsigned id;

	static sf::Vector2u size;
	static sf::Time animationTime;
	static sf::Texture & cardBackTexture;
	static sf::Sound cardSound;

	sf::Sprite cardSprite;
	sf::Texture cardTexture;

	Suit cardSuit;
	void setCardTexture(Suit suit);

	CardAnimation * cardAnimation;
};

