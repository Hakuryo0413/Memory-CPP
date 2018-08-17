#include "stdafx.h"
#include "Button.h"
#include <iostream>

Button::Button(std::string btnText, std::function<void()> callback) :
	GUIComponent(),
	callback(callback),
	text(btnText, buttonFont),
  shape()
{
	sf::FloatRect textBounds = text.getLocalBounds();
  shape.setSize(sf::Vector2f(textBounds.width + 10.f, textBounds.height + 10.f));
	shape.setTexture(&buttonTexture);
  shape.setOutlineThickness(1.f);

	sf::FloatRect spriteBounds = shape.getLocalBounds();
	text.setPosition(spriteBounds.width / 2.f - textBounds.width / 2.f - 3.f, spriteBounds.height / 2.f - text.getCharacterSize() / 2.f - 3.f);
}

Button::~Button()
{
}

sf::Font & Button::buttonFont = AssetManager::getInstance()->getFont("Beleren-Bold.ttf");
sf::Texture & Button::buttonTexture = AssetManager::getInstance()->getTexture("ButtonNormalSmall.png");

bool Button::isSelectable()
{
  return true;
}

bool Button::isClicked(sf::Vector2f mousePosition)
{
	// return shape.getGlobalBounds().contains(mousePosition);
  sf::FloatRect globalBounds = getTransform().transformRect(shape.getLocalBounds());
  return globalBounds.contains(mousePosition);
  // return point.x > 0.f && point.x < m_size.x &&
	//        point.y > 0.f && point.y < m_size.y;
}

void Button::handleMouseClick()
{
	callback();
}

sf::Vector2f Button::getSize()
{
  return sf::Vector2f(shape.getLocalBounds.width, shape.getLocalBounds.height);
}

void Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(shape, states);
	target.draw(text, states);
}