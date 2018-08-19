#include "TextInput.h"

TextInput::TextInput() :
	shape(sf::Vector2f(125.f, 40.f)),
	playerText("", GUIFont)
{
	playerText.setPosition(5.f, 0);
	shape.setFillColor(backgroundColor);
	shape.setOutlineThickness(2.f);
	shape.setOutlineColor(outlineColor);
}

TextInput::~TextInput()
{
}

bool TextInput::isSelectable()
{
	return true;
}

bool TextInput::isClicked(sf::Vector2f mousePosition)
{
	sf::FloatRect globalBounds = getTransform().transformRect(shape.getLocalBounds());
	if (!globalBounds.contains(mousePosition))
	{
		toggleSelected(false);
	}
	return globalBounds.contains(mousePosition);
}

bool TextInput::isClicked(sf::Vector2f mousePosition, const sf::Transform & parentTransform)
{
	sf::Transform newTransform = getTransform() * parentTransform;
	sf::FloatRect globalBounds = newTransform.transformRect(shape.getLocalBounds());
	if (!globalBounds.contains(mousePosition))
	{
		toggleSelected(false);
	}
	return globalBounds.contains(mousePosition);
}

void TextInput::handleMouseClick(sf::Vector2f mousePosition)
{
	if (isClicked(mousePosition))
	{
		toggleSelected(true);
	}
}

void TextInput::handleMouseClick(sf::Vector2f mousePosition, const sf::Transform & parentTransform)
{
	if (isClicked(mousePosition, parentTransform))
	{
		toggleSelected(true);
	}
}

void TextInput::handleTextEntry(sf::Event::TextEvent textEvent)
{
	if (selected)
	{
		if (textEvent.unicode == '\b')
		{
			if (playerInput.size() > 0)
			{
				playerInput.pop_back();
			}
		}
		else if (textEvent.unicode == 13)
		{
			if (playerInput.size() > 0 && callback != nullptr)
			{
				callback();
				toggleSelected(true);
			}
		}
		else if (textEvent.unicode < 128 && playerInput.size() < 7)
		{
			playerInput += static_cast<char>(textEvent.unicode);
		}
		playerText.setString(playerInput);
	}
}

sf::Vector2f TextInput::getSize()
{
	return sf::Vector2f(shape.getLocalBounds().width, shape.getLocalBounds().height);
}

std::string TextInput::getPlayerInput()
{
	return playerInput;
}

void TextInput::resetInput()
{
	playerInput = "";
	playerText.setString(playerInput);
	toggleSelected(false);
}

void TextInput::setEnterCallback(std::function<void()> enterCallback)
{
	callback = enterCallback;
}

void TextInput::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(shape, states);
	target.draw(playerText, states);
}

void TextInput::toggleSelected(bool direction)
{
	if (direction)
	{
		selected = true;
		shape.setOutlineColor(activeOutlineColor);
	}
	else
	{
		selected = false;
		shape.setOutlineColor(outlineColor);
	}
}



