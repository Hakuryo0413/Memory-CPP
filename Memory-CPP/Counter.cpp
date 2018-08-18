#include "stdafx.h"
#include "Counter.h"

Counter::Counter(unsigned * value, std::string labelText) :
	Widget(),
	value(value),
	label(new Label(labelText)),
	valueIndicator(new Label(std::to_string(*value)))
{
	decrementButton = new Button("-", std::bind(std::bind(&Counter::decrementValue, this)));
	incrementButton = new Button("+", std::bind(std::bind(&Counter::incrementValue, this)));

	components = { label, decrementButton, valueIndicator, incrementButton };
	secondRow = { components.begin() + 1, components.end() };

	sf::Vector2f rowStartPosition(10.f, label->getSize().y + 20.f);
	positionRow(secondRow, rowStartPosition);
}

Counter::~Counter()
{
}

void Counter::setLabel(std::string text)
{
	label->setText(text);
}

sf::Vector2f Counter::getSize()
{
	sf::Vector2f size;

	return sf::Vector2f();
}

void Counter::incrementValue()
{
	(*value)++;
	valueIndicator->setText(std::to_string(*value));
}

void Counter::decrementValue()
{
	if (*value > 1)
	{
		(*value)--;
		valueIndicator->setText(std::to_string(*value));
	}
}
