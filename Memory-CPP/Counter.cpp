#include "stdafx.h"
#include "Counter.h"

Counter::Counter(int * value, std::string labelText) :
  Widget(),
  value(value),
  label(new Label(labelText)),
  incrementButton(new Button("+", std::bind(std::bind(&Counter::incrementValue, this)))),
  decrementButton(new Button("-", std::bind(std::bind(&Counter::decrementValue, this)))),
  valueIndicator(new Label(std::to_string(*value)))
{
  components = { label, incrementButton, valueIndicator, decrementButton };

  sf::Vector2f rowStartPosition(50.f, label->getSize().y);
  std::vector<GUIComponent *> widgetRow (components.begin() + 1, components.end());
  positionRow(widgetRow, rowStartPosition);
}

Counter::~Counter()
{
}

void Counter::setLabel(std::string text)
{
  label->setText(text);
}

void Counter::incrementValue()
{
  *value++;
  valueIndicator->setText(std::to_string(*value));
}

void Counter::decrementValue()
{
  *value--;
  valueIndicator->setText(std::to_string(*value));
}
