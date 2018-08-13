#include "stdafx.h"
#include "Animation.h"

Animation::Animation() :
  elapsedTime(sf::Time::Zero),
  playing(false)
{
}

Animation::Animation(sf::Sprite sprite, sf::Time animationDuration) :
	spirite(sprite),
  animationDuration(animationDuration),
  elapsedTime(sf::Time::Zero),
  playing(false)
{
}

Animation::~Animation()
{
}

const double Card::pi = std::acos(-1);

void Animation::startAnimation()
{
  playing = true;
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
    playing = false;
    elapsedTime = sf::Time::Zero;
    return;
  }

  applyTransformation();
}