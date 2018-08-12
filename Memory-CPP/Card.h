#pragma once
#include <iostream>
#include "TextureManager.h"
#include <SFML/Graphics.hpp>

class Card
{
public:
	enum Suit
	{
		Air, Earth, Fire, Water, COUNT
	};

	Card(unsigned id, Suit suit);
	~Card();

	void renderCard(sf::RenderWindow &window);
	void updateCard(sf::Time deltaTime);
	void setPosition(sf::Vector2u deckPosition);
	bool isCardClicked(sf::Vector2f mousePosition);
	void flipCard();
	Suit getSuit();

private:
	unsigned id;
	bool isFlipped;
	bool spinning;

	static sf::Vector2u size;
	static sf::Time animationTime;
	static sf::Texture & cardBackTexture;
	static const double pi;

	sf::Sprite cardSprite;
	sf::Texture cardTexture;
	sf::Time elapsedTime;

	Suit cardSuit;
	void setCardTexture(Suit suit);
	void toggleTexture();
};

