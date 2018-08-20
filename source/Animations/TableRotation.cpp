#include "TableRotation.h"

TableRotation::TableRotation() :
	Animation()
{
}

TableRotation::TableRotation(sf::View * animated, sf::Time animationDuration) :
	Animation(animated, animationDuration)
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

void TableRotation::applyTransformation()
{
	float currentRotation = rotationAngle * elapsedTime / animationDuration;
	animated->rotate(currentRotation);
};