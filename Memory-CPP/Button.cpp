#include "stdafx.h"
#include "Button.h"
#include <iostream>

Button::Button(std::string btnText, std::function<void()> callback) :
	Widget(),
	callback(callback),
	text(btnText, buttonFont)
{
	sprite.setTexture(buttonTexture);

	sf::FloatRect spriteBounds = sprite.getLocalBounds();
	sf::FloatRect textBounds = text.getLocalBounds();
	text.setPosition(spriteBounds.width / 2.f - textBounds.width / 2.f - 3.f, spriteBounds.height / 2.f - text.getCharacterSize() / 2.f - 3.f);
}

Button::~Button()
{
}

sf::Font & Button::buttonFont = AssetManager::getInstance()->getFont("Beleren-Bold.ttf");
sf::Texture & Button::buttonTexture = AssetManager::getInstance()->getTexture("ButtonNormalSmall.png");

bool Button::isClicked(sf::Vector2f mousePosition)
{
	std::cout << sprite.getGlobalBounds().contains(mousePosition) << std::endl;
	return sprite.getGlobalBounds().contains(mousePosition);
}

void Button::handleMouseClick()
{
	callback();
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(sprite, states);
	target.draw(text, states);
}