#include "stdafx.h"
#include "Player.h"

Player::Player(std::string name) :
	name(name),
	score(0)
{
	playerTag.setString(name);
}

Player::~Player()
{
}

void Player::renderPlayerTag(sf::RenderWindow & window)
{
	window.draw(playerTag);
}

void Player::increaseScore()
{
	score++;
}
