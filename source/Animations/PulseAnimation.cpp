#include "PulseAnimation.h"

PulseAnimation::PulseAnimation() :
	Animation()
{
}

PulseAnimation::PulseAnimation(sf::Text * animated, sf::Time animationDuration) :
	Animation(animated, animationDuration)
{
}

PulseAnimation::~PulseAnimation()
{
}

void PulseAnimation::applyTransformation()
{
	if (elapsedTime < animationDuration / 2.f) {
		float time = elapsedTime / (animationDuration / 2.f);
		float scale = 0.25f * float(std::sin(time * pi / 2)) + 1.f;
		animated->setScale(scale, scale);
	}
	else {
		float time = (elapsedTime - (animationDuration / 2.f)) / (animationDuration / 2.f);
		float scale = -0.25f * float(std::sin(time * pi / 2)) + 1.25f;
		animated->setScale(scale, scale);
	}
};