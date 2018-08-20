#pragma once
#include "Animation.h"

class PulseAnimation :
	public Animation<sf::Text>
{
public:
	PulseAnimation();
	PulseAnimation(sf::Text * animated, sf::Time animationDuration);
	~PulseAnimation();

private:
	virtual void applyTransformation();
};
