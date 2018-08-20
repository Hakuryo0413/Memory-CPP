#pragma once;
#include "Animation.h"

class TableRotation : public Animation<sf::View>
{
public:
	TableRotation();
	TableRotation(sf::View * animated, sf::Time animationDuration);
	~TableRotation();

	virtual void startAnimation(float angle = 90.f);
	virtual void stopAnimation();
private:
	virtual void applyTransformation();
	float rotationAngle;
	float currentRotation;
};