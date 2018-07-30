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
private:
	unsigned id;
	static sf::Vector2f size;
	sf::RectangleShape cardShape;
};

