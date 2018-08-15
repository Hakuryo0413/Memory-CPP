#include "stdafx.h"
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
	float scale = 1.f - elapsedTime / (animationDuration);
	animated->setFillColor(sf::Color(255, 255, 255, sf::Uint8(std::sin(scale * pi / 2))));
};