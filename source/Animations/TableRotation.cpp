#include "TableRotation.h"
#include <iostream>

TableRotation::TableRotation() :
	Animation(),
	currentRotation(0.f)
{
}

TableRotation::TableRotation(sf::View * animated, sf::Time animationDuration) :
	Animation(animated, animationDuration),
	currentRotation(0.f)
{
}

TableRotation::~TableRotation()
{
}

void TableRotation::startAnimation(float angle)
{
	Animation::startAnimation();
	rotationAngle = angle;
}

void TableRotation::stopAnimation()
{
	Animation::stopAnimation();
	currentRotation += rotationAngle;
	if (currentRotation >= 360.f)
	{
		currentRotation -= 360.f;
	}
	rotationAngle = 0.f;
}

void TableRotation::applyTransformation()
{
	float rotation = rotationAngle * float(std::sin(elapsedTime / animationDuration * (pi / 2.f))) + currentRotation;
	animated->setRotation(rotation);
};