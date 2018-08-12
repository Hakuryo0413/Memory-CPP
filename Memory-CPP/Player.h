#pragma once
#include "string"
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(std::string name);
	~Player();

	void renderPlayerTag(sf::RenderWindow &window);
private:
	std::string name;
	sf::Font playerFont;
	sf::Text playerTag;

	unsigned score;
};

