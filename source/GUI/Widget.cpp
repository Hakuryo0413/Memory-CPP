#include "Widget.h"

Widget::Widget()
{
}

Widget::~Widget()
{
	for (size_t i = 0; i < components.size(); i++)
	{
		delete components[i];
	}
	components.clear();
}

bool Widget::isSelectable()
{
	return true;
}

void Widget::update(sf::Time deltaTime)
{
	for (size_t i = 0; i < components.size(); i++)
	{
		components[i]->update(deltaTime);
	}
}

void Widget::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	for (size_t i = 0; i < components.size(); i++)
	{
		target.draw(*components[i], states);
	}
}

bool Widget::isClicked(sf::Vector2f mousePosition)
{
	for (size_t i = 0; i < components.size(); i++)
	{
		if (components[i]->isSelectable())
		{
			return components[i]->isClicked(mousePosition, getTransform());
		}
		else
		{
			return false;
		}
	}
}

void Widget::handleMouseClick(sf::Vector2f mousePosition)
{
	for (size_t i = 0; i < components.size(); i++)
	{
		if (components[i]->isSelectable())
		{
			components[i]->handleMouseClick(mousePosition, getTransform());
		}
	}
}

void Widget::handleTextEntry(sf::Event::TextEvent textEntry)
{
	if (!supportsTextEntry)
	{
		return;
	}
}

void Widget::positionRow(std::vector<GUIComponent *> & widgetRow, sf::Vector2f startPosition)
{
	float rowWidth = startPosition.x;
	for (size_t i = 0; i < widgetRow.size(); i++)
	{
		widgetRow[i]->setPosition(rowWidth, startPosition.y);
		rowWidth += widgetRow[i]->getSize().x + 30.f;
	}

}
