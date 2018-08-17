#pragma once
#include "GUIComponent.h"

class Label : public GUIComponent
{
public:
  Label(std::string text);
  ~Label();

	virtual bool isSelectable();
  void setText(std::string text);

	virtual sf::Vector2f getSize();
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	static sf::Font & labelFont;
  sf::Text labelText;
};