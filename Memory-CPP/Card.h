#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Card
{
public:
	Card(unsigned id);
	~Card();

	void renderCard(sf::RenderWindow &window);
	void setPosition(sf::Vector2u deckPosition);
	bool isCardClicked(sf::Vector2f mousePosition);
	void revealCard();
	// Suit getSuit();
private:
	unsigned id;
	static sf::Vector2f size;
	sf::RectangleShape cardShape;
	enum class Suit
	{
		Air, Earth, Fire, Water
	};

	Suit cardSuit;
public:
	Suit getSuit();
};

