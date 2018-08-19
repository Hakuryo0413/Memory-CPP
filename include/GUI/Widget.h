#pragma once
#include "GUIComponent.h"

class Widget : public GUIComponent
{
public:
	Widget();
	~Widget();

	virtual bool isSelectable();
	virtual void update(sf::Time deltaTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual bool isClicked(sf::Vector2f mousePosition);
	virtual void handleMouseClick(sf::Vector2f mousePosition);
	virtual void handleTextEntry(sf::Event::TextEvent textEntry);
protected:
	bool supportsTextEntry;
	std::vector<GUIComponent *> components;
	std::vector<GUIComponent *> secondRow;
	virtual void positionRow(std::vector<GUIComponent *> & widgetRow, sf::Vector2f startPosition);
};