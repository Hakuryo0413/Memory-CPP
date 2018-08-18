#pragma once
#include "Animation.h"

class FadeAnimation :
	public Animation<sf::Text>
{
public:
	FadeAnimation();
	FadeAnimation(sf::Text * animated, sf::Time animationDuration);
	~FadeAnimation();

	void startAnimation(bool direction);
private:
	bool fadeDirection;
	virtual void applyTransformation();
};