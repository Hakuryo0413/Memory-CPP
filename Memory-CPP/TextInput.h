#pragma once
#include "GUIComponent.h"

class TextInput : public GUIComponent
{
public:
  TextInput();
  ~TextInput();

  virtual bool isSelectable();
  virtual bool isClicked(sf::Vector2f mousePosition);
	virtual void handleMouseClick();
  void handleTextEntry(sf::Event::TextEvent textEvent);
	virtual sf::Vector2f getSize();
  std::string getPlayerInput();
  void resetInput();
private:
  void toggleSelected();
	static sf::Font & inputFont;
  static sf::Color outlineColor;
  static sf::Color selectedOutlineColor;
  sf::RectangleShape shape;
  sf::Text playerText;
  std::string playerInput;
  bool selected;
};