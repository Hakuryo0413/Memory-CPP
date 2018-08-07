#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#define GRAPHICS_PATH "data/graphics/"


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
	static sf::Texture airCardTexture;
	static sf::Texture earthCardTexture;
	static sf::Texture fireCardTexture;
	static sf::Texture waterCardTexture;
};

