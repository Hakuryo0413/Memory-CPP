#pragma once
#include "string"
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "FadeAnimation.h"

class Player
{
public:
	Player(std::string name);
	~Player();

	enum PlayerComponents					// which part to operate on
	{
		Name,
		Score,
		All
	};

	void renderPlayer(sf::RenderWindow & window, PlayerComponents component);
	void updatePlayer(sf::Time deltaTime, PlayerComponents component);
	void fadePlayer(bool direction, PlayerComponents component);		// fade in (true), fade out (false)

	void increaseScore();
	sf::Text playerTag;
	sf::Text playerScore;
	unsigned score;
private:
	std::string name;
	static sf::Font & playerFont;
	static sf::Time animationTime;

	FadeAnimation * nameAnimation;
	FadeAnimation * scoreAnimation;
};

