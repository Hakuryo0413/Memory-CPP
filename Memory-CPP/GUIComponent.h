#pragma once
#include <SFML/Graphics.hpp>
#include "AssetManager.h"

class GUIComponent : public sf::Drawable, public sf::Transformable
{
public:
	GUIComponent();
	~GUIComponent();

	virtual bool isSelectable() = 0;
	virtual bool isClicked(sf::Vector2f mousePosition);
	virtual void handleMouseClick();
	virtual sf::Vector2f getSize() = 0;
};