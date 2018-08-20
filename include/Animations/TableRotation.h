#pragma once;
#include "Animation.h"

class TableRotation : public Animation<sf::View>
{
public:
	TableRotation();
	TableRotation(sf::View * animated, sf::Time animationDuration);
	~TableRotation();

	void startAnimation(float angle = 90.f);
private:
	virtual void applyTransformation();
	float rotationAngle;
};