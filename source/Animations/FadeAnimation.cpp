#include "FadeAnimation.h"

FadeAnimation::FadeAnimation() :
	Animation()
{
}

FadeAnimation::FadeAnimation(sf::Text * animated, sf::Time animationDuration) :
	Animation(animated, animationDuration),
	fadeDirection(true)
{
}

FadeAnimation::~FadeAnimation()
{
}

void FadeAnimation::startAnimation(bool direction)
{
	Animation::startAnimation();
	fadeDirection = direction;
}

void FadeAnimation::applyTransformation()
{
	sf::Uint8 startAlpha;
	sf::Uint8 endAlpha;
	if (fadeDirection)
	{
		startAlpha = 0;
		endAlpha = 255;
	}
	else
	{
		startAlpha = 255;
		endAlpha = 0;
	}
	sf::Uint8 alpha = (endAlpha - startAlpha) * std::sin(elapsedTime / animationDuration * pi / 2) + startAlpha;
	animated->setFillColor(sf::Color(255, 255, 255, alpha));
};