#include "Button.h"

Button::Button(std::string btnText, std::function<void()> callback) :
  Widget(),
  callback(callback),
	text(btnText, buttonFont)
{
  sf::FloatRect textRect = text.getLocalBounds();
  sf::IntRect textureRect = { 0, 0, textRect.width + 10, textRect.height + 10 };

	sprite.setTexture(buttonTexture);
  sprite.setTextureRect(textureRect);

	sf::FloatRect bounds = sprite.getLocalBounds();
	text.setPosition(bounds.width / 2.f, bounds.height / 2.f);
}

sf::Font & Button::buttonFont = AssetManager::getInstance()->getFont("Beleren-Bold.ttf");

bool Button::isClicked(sf::Vector2f mousePosition)
{
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