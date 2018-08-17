#include "stdafx.h"
#include "TextInput.h"

TextInput::TextInput() :
  shape(sf::Vector2f(100.f, 50.f)),
  playerText("", inputFont)
{
  shape.setOutlineThickness(2.f);
  shape.setOutlineColor(outlineColor);
}

TextInput::~TextInput()
{
}

sf::Font & TextInput::inputFont = AssetManager::getInstance()->getFont("Beleren-Bold.ttf");
sf::Color TextInput::outlineColor(168, 118, 62, 255);
sf::Color TextInput::selectedOutlineColor(111, 26, 7, 255);

bool TextInput::isSelectable()
{
  return true;
}

bool TextInput::isClicked(sf::Vector2f mousePosition)
{
  sf::FloatRect globalBounds = getTransform().transformRect(shape.getLocalBounds());
  if (!globalBounds.contains(mousePosition))
  {
    toggleSelected();
  }
  return globalBounds.contains(mousePosition);
}

void TextInput::handleMouseClick()
{
  toggleSelected();
}

void TextInput::handleTextEntry(sf::Event::TextEvent textEvent)
{
  if (selected)
  {
    playerInput += textEvent.unicode;
    playerText.setString(playerInput);
  }
}

sf::Vector2f TextInput::getSize()
{
  return sf::Vector2f(shape.getLocalBounds.width, shape.getLocalBounds.height);
}

std::string TextInput::getPlayerInput()
{
  return playerInput;
}

void TextInput::resetInput()
{
  playerInput = "";
  playerText.setString(playerInput);
  toggleSelected();
}

void TextInput::toggleSelected()
{
  if (selected)
  {
    shape.setOutlineColor(outlineColor);
  }
  else
  {
    shape.setOutlineColor(selectedOutlineColor);
  }
  selected = !selected;
}



