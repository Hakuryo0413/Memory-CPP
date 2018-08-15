#pragma once
#include "Animation.h"

class FadeInAnimation :
	public Animation<sf::Text>
{
public:
	FadeInAnimation();
	FadeInAnimation(sf::Text * animated, sf::Time animationDuration);
	~FadeInAnimation();

private:
  void applyTransformation();
};