#pragma once
#include "GUIComponent.h"

class Label : public GUIComponent
{
public:
	Label(std::string text, bool center = false);
	~Label();

	virtual bool isSelectable();
	void setText(std::string text);

	virtual sf::Vector2f getSize();
private:
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
	sf::Text labelText;
};