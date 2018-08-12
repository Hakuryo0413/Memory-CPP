#pragma once
#include "string"
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(std::string name);
	~Player();

	void renderPlayerTag(sf::RenderWindow &window);
	void increaseScore();
	std::string name;
	unsigned score;
private:
	sf::Font playerFont;
	sf::Text playerTag;

};

