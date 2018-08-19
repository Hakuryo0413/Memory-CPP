#pragma once
#include "Widget.h"
#include "Button.h"
#include "Label.h"

class Counter : public Widget
{
public:
  Counter(unsigned * value, std::string labelText);
  ~Counter();

  void setLabel(std::string text);
  virtual sf::Vector2f getSize();
private:
  unsigned * value;
  void incrementValue();
  void decrementValue();

  Button * incrementButton;
  Button * decrementButton;
  Label * label;
  Label * valueIndicator;
};