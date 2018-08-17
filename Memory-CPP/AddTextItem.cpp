#include "stdafx.h"
#include "AddTextItem.h"

AddTextItem::AddTextItem(std::string labelText, std::function<void(std::string text)> addItemCallback) :
  Widget(),
  label(new Label(labelText)),
  addButton(new Button("+", std::bind(&AddTextItem::submitNewItem, this))),
  textInput(),
  addItemCallback(addItemCallback)
{
  components = { label, textInput, addButton };

  sf::Vector2f rowStartPosition(50.f, label->getSize().y);
  std::vector<GUIComponent *> widgetRow (components.begin() + 1, components.end());
  positionRow(widgetRow, rowStartPosition);
}

AddTextItem::~AddTextItem()
{
}

void AddTextItem::setLabel(std::string text)
{
  label->setText(text);
}

void AddTextItem::handleTextEntry(sf::Event::TextEvent textEvent)
{
  textInput->handleTextEntry(textEvent);
}

void AddTextItem::submitNewItem()
{
  addItemCallback(textInput->getPlayerInput());
  textInput->resetInput();
}
