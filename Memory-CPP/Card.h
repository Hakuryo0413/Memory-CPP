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
	void setPosition(sf::Vector2u deckPosition);
	bool isCardClicked(sf::Vector2f mousePosition);
	void revealCard();
	Suit getSuit();

private:
	unsigned id;
	static sf::Vector2f size;
	sf::RectangleShape cardShape;
	Suit cardSuit;
	// static sf::Texture cardBackTexture;
	sf::Texture cardTexture;
	void setCardTexture(Suit suit);
};

