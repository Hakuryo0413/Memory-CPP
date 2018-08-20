#include "Player.h"

Player::Player(std::string name) :
	name(name),
	score(0),
	playerTag(name, playerFont),
	playerScore("0", playerFont)
{
	nameAnimation = new FadeAnimation(&playerTag, animationTime);
	scoreAnimation = new FadeAnimation(&playerScore, animationTime);
	pulseAnimation = new PulseAnimation(&playerTag, animationTime);
}

Player::~Player()
{
	delete nameAnimation;
	delete scoreAnimation;
	delete pulseAnimation;
}

sf::Font & Player::playerFont = AssetManager::getInstance()->getFont("Beleren-Bold.ttf");
sf::Time Player::animationTime = sf::seconds(0.3f);

void Player::renderPlayer(sf::RenderWindow & window, PlayerComponents component)
{
	switch (component)
	{
	case PlayerComponents::Name:
		window.draw(playerTag);
		break;
	case PlayerComponents::Score:
		window.draw(playerScore);
		break;
	case PlayerComponents::All:
		window.draw(playerTag);
		window.draw(playerScore);
		break;
	default:
		break;
	}
}

void Player::updatePlayer(sf::Time deltaTime, PlayerComponents component)
{
	switch (component)
	{
	case PlayerComponents::Name:
		nameAnimation->updateAnimated(deltaTime);
		pulseAnimation->updateAnimated(deltaTime);
		break;
	case PlayerComponents::Score:
		scoreAnimation->updateAnimated(deltaTime);
		break;
	case PlayerComponents::All:
		nameAnimation->updateAnimated(deltaTime);
		scoreAnimation->updateAnimated(deltaTime);
		pulseAnimation->updateAnimated(deltaTime);
		break;
	default:
		break;
	}
}

void Player::fadePlayer(bool direction, PlayerComponents component)
{
	switch (component)
	{
	case PlayerComponents::Name:
		nameAnimation->startAnimation(direction);
		break;
	case PlayerComponents::Score:
		scoreAnimation->startAnimation(direction);
		break;
	case PlayerComponents::All:
		nameAnimation->startAnimation(direction);
		scoreAnimation->startAnimation(direction);
		break;
	default:
		break;
	}
}

void Player::pulsePlayer()
{
	pulseAnimation->startAnimation();
}

void Player::centarTag(bool center)
{
	if (center)
	{
		float playerWidth = playerTag.getLocalBounds().width;
		int playerHeight = playerTag.getCharacterSize();
		playerTag.setOrigin(playerWidth / 2.f, playerHeight / 2.f);
	}
	else
	{
		playerTag.setOrigin(0, 0);
	}
}

void Player::increaseScore()
{
	score++;
	playerScore.setString(std::to_string(score));
}
