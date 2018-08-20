#include "Label.h"
#include "AssetManager.h"

Label::Label(std::string text, bool center) :
	GUIComponent(),
	labelText(text, GUIFont)
{
	if (center)
	{
		labelText.setOrigin({ labelText.getLocalBounds().width / 2.f, labelText.getCharacterSize() / 2.f });
	}
}

Label::~Label()
{
}

bool Label::isSelectable()
{
	return false;
}

sf::Vector2f Label::getSize()
{
	return sf::Vector2f(labelText.getLocalBounds().width, labelText.getLocalBounds().height);
}

void Label::setText(std::string text)
{
	labelText.setString(text);
}

void Label::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(labelText, states);
}
