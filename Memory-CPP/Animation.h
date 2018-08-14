#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation();
	Animation(sf::Sprite * sprite, sf::Time animationDuration);
	~Animation();

	virtual void startAnimation();
	virtual void stopAnimation();
	void updateSprite(sf::Time deltaTime);
protected:
	bool playing;
	static const double pi;
	sf::Time elapsedTime;
	sf::Sprite * sprite;
	sf::Time animationDuration;
	virtual void applyTransformation() = 0;
};