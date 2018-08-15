#include "stdafx.h"
#include "FadeInAnimation.h"

FadeInAnimation::FadeInAnimation() :
  Animation()
{
}

FadeInAnimation::FadeInAnimation(sf::Text * animated, sf::Time animationDuration) :
  Animation(animated, animationDuration)
{
}

FadeInAnimation::~FadeInAnimation()
{
}

void FadeInAnimation::applyTransformation()
{
  float scale = 1.f - elapsedTime / (animationDuration);
  animated->setFillColor(sf::Color(255, 255, 255, sf::Uint8(std::sin(scale * pi / 2))));
};