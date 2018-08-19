#pragma once
#include "Widget.h"
#include "Button.h"
#include "Label.h"
#include "TextInput.h"

class AddTextItem : public Widget
{
public:
  AddTextItem(std::string labelText, std::function<void(std::string text)> addItemCallback);
  ~AddTextItem();

  void setLabel(std::string text);
  void handleTextEntry(sf::Event::TextEvent textEvent);
private:
  void submitNewItem();
  std::function<void(std::string)> addItemCallback;

  Button * addButton;
  Label * label;
  TextInput * textInput;
};