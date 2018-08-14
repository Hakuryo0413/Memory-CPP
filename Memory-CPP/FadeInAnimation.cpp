#include "stdafx.h"
#include "FadeInAnimation.h"

FadeInAnimation::FadeInAnimation() :
  Animation()
{
}

FadeInAnimation::FadeInAnimation(sf::Sprite * sprite, sf::Time animationDuration) :
  Animation(sprite, animationDuration)
{
}

FadeInAnimation::~FadeInAnimation()
{
}

void FadeInAnimation::applyTransformation()
{
  float scale = 1.f - elapsedTime / (animationDuration);
  sprite->setColor(sf::Color(255, 255, 255, std::sin(scale * pi / 2)));
};