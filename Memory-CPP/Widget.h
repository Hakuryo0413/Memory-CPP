#pragma once
#include "GUIComponent.h"

class Widget : public sf::Drawable, public sf::Transformable
{
public:
  Widget();
  ~Widget();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  virtual bool isClicked(sf::Vector2f mousePosition);
	virtual void handleMouseClick(sf::Vector2f mousePosition);
  virtual void handleTextEntry(sf::Event::TextEvent textEntry);
protected:
  bool supportsTextEntry;
  std::vector<GUIComponent *> components;
  virtual void positionRow(std::vector<GUIComponent *> & widgetRow, sf::Vector2f startPosition);
};