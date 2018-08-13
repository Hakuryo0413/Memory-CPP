#pragma once
#include "string"
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

class Player
{
public:
	Player(std::string name);
	~Player();

	void renderPlayerTag(sf::RenderWindow &window);
	void renderPlayerScore(sf::RenderWindow &window);
	void increaseScore();
	sf::Text playerTag;
	sf::Text playerScore;
	unsigned score;
private:
	std::string name;
	static sf::Font & playerFont;
};

