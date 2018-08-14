#pragma once
#include "Animation.h"

class FadeInAnimation :
	public Animation
{
public:
	FadeInAnimation();
	FadeInAnimation(sf::Sprite * sprite, sf::Time animationDuration);
	~FadeInAnimation();

private:
  void applyTransformation();
};