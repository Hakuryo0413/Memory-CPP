#include "stdafx.h"
#include "CardAnimation.h"


CardAnimation::CardAnimation() :
	Animation()
{
}

CardAnimation::CardAnimation(sf::Sprite * sprite, sf::Time animationDuration, sf::Texture * cardTexture) :
	Animation(sprite, animationDuration),
	cardBackTexture(sprite->getTexture()),
	cardTexture(cardTexture),
	isFlipped(false)
{
}


CardAnimation::~CardAnimation()
{
}

void CardAnimation::stopAnimation()
{
	Animation::stopAnimation();
	isFlipped = false;
}

void CardAnimation::applyTransformation()
{
	if (elapsedTime >= animationDuration / 2.f && !isFlipped)
	{
		toggleTexture();
		isFlipped = true;
	}

	if (elapsedTime < animationDuration / 2.f) {
		float scale = 1.f - elapsedTime / (animationDuration / 2.f);
		sprite->setScale(float(std::sin(scale * pi / 2)), 1.f);
	}
	else {
		float scale = (elapsedTime - (animationDuration / 2.f)) / (animationDuration / 2.f);
		sprite->setScale(float(std::sin(scale * pi / 2)), 1.f);
	}
}

void CardAnimation::toggleTexture()
{
	if (sprite->getTexture() == cardBackTexture)
	{
		sprite->setTexture(*cardTexture);
	}
	else
	{
		sprite->setTexture(*cardBackTexture);
	}
}
