#include "stdafx.h"
#include "Animation.h"

Animation::Animation() :
	elapsedTime(sf::Time::Zero),
	playing(false)
{
}

Animation::Animation(sf::Sprite * sprite, sf::Time animationDuration) :
	sprite(sprite),
	animationDuration(animationDuration),
	elapsedTime(sf::Time::Zero),
	playing(false)
{
}

Animation::~Animation()
{
}

const double Animation::pi = std::acos(-1);

void Animation::startAnimation()
{
	if (!playing)
	{
		playing = true;
	}
}

void Animation::stopAnimation()
{
	playing = false;
	elapsedTime = sf::Time::Zero;
}

void Animation::updateSprite(sf::Time deltaTime)
{
	if (!playing)
	{
		return;
	}
	elapsedTime += deltaTime;
	if (elapsedTime >= animationDuration)
	{
		stopAnimation();
		return;
	}

	applyTransformation();
}