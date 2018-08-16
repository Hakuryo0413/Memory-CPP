#pragma once
#include <SFML/Graphics.hpp>
#include "AssetManager.h"

class Widget : public sf::Drawable, public sf::Transformable
{
public:
	Widget();
	~Widget();

	bool isSelected() const;
	virtual void select();
	virtual void deselect();
	virtual bool isClicked(sf::Vector2f mousePosition) = 0;

	virtual void handleMouseClick() = 0;
protected:
	bool selected;
}