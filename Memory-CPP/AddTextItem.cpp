#include "stdafx.h"
#include "AddTextItem.h"

AddTextItem::AddTextItem(std::string labelText, std::function<void(std::string text)> addItemCallback) :
  Widget(),
  label(new Label(labelText)),
  addButton(new Button("+", std::bind(&AddTextItem::submitNewItem, this))),
  textInput(new TextInput()),
  addItemCallback(addItemCallback)
{
  components = { label, textInput, addButton };
  secondRow = { components.begin() + 1, components.end() };

  sf::Vector2f rowStartPosition(10.f, label->getSize().y + 20.f);
  positionRow(secondRow, rowStartPosition);
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
