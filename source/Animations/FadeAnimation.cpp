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
	sf::Uint8 startAlpha = 0;
	sf::Uint8 endAlpha = 255;
	sf::Uint8 alpha = startAlpha + (endAlpha - startAlpha) * sf::Uint8(elapsedTime / animationDuration);
	animated->setFillColor(sf::Color(255, 255, 255, alpha));
};