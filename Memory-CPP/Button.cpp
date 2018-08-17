#include "stdafx.h"
#include "Button.h"
#include <iostream>

Button::Button(std::string btnText, std::function<void()> callback) :
	GUIComponent(),
	callback(callback),
	text(btnText, buttonFont)
{
	sf::FloatRect textBounds = text.getLocalBounds();

	if (btnText.size() > 1)
	{
		shape = sf::RectangleShape({ textBounds.width + 20.f, textBounds.height + 20.f });
	}
	else
	{
		shape = sf::RectangleShape({ 30.f, 30.f });
	}
	shape.setTexture(&buttonTexture);
	shape.setOutlineThickness(1.f);

	sf::FloatRect shapeBounds = shape.getLocalBounds();
	text.setPosition(shapeBounds.width / 2.f - textBounds.width / 2.f - 3.f, shapeBounds.height / 2.f - text.getCharacterSize() / 2.f - 5.f);
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

bool Button::isClicked(sf::Vector2f mousePosition, sf::Transform parentTransform)
{
	sf::Transform newTransform = getTransform() * parentTransform;
	sf::FloatRect globalBounds = newTransform.transformRect(shape.getLocalBounds());
	return globalBounds.contains(mousePosition);
}

void Button::handleMouseClick(sf::Vector2f mousePosition)
{
	callback();
}

sf::Vector2f Button::getSize()
{
	return sf::Vector2f(shape.getLocalBounds().width, shape.getLocalBounds().height);
}

void Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(shape, states);
	target.draw(text, states);
}