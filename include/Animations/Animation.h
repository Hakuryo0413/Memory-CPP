#pragma once
#include <SFML/Graphics.hpp>

template <typename Animated>
class Animation
{
public:
	Animation();
	Animation(Animated * animated, sf::Time animationDuration);
	~Animation();

	virtual void startAnimation();
	virtual void stopAnimation();
	void updateAnimated(sf::Time deltaTime);
protected:
	bool playing;
	static const double pi;
	sf::Time elapsedTime;
	Animated * animated;
	sf::Time animationDuration;
	virtual void applyTransformation() = 0;
};

#include "Animation.inl"