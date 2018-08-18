#pragma once
#include <SFML/Graphics.hpp>
#include "AssetManager.h"

class GUIComponent : public sf::Drawable, public sf::Transformable
{
public:
	GUIComponent();
	~GUIComponent();

	virtual bool isSelectable() = 0;
	virtual void update(sf::Time deltaTime);
	virtual bool isClicked(sf::Vector2f mousePosition);
	virtual bool isClicked(sf::Vector2f mousePosition, const sf::Transform & parentTransform);
	virtual void handleMouseClick(sf::Vector2f mousePosition);
	virtual void handleMouseClick(sf::Vector2f mousePosition, const sf::Transform & parentTransform);
	virtual void handleTextEntry(sf::Event::TextEvent textEntry);
	virtual sf::Vector2f getSize();
};