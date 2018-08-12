#include "stdafx.h"
#include "Player.h"

Player::Player(std::string name) :
	name(name)
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
