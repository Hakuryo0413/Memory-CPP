#include "Button.h"

Button::Button(std::string btnText, std::function<void()> callback) :
	GUIComponent(),
	callback(callback),
	text(btnText, buttonFont),
	timeout(new SetTimeout()),
	active(false)
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
	delete timeout;
}

sf::Font & Button::buttonFont = AssetManager::getInstance()->getFont("Beleren-Bold.ttf");
sf::Texture & Button::buttonTexture = AssetManager::getInstance()->getTexture("ButtonNormalSmall.png");

bool Button::isSelectable()
{
	return true;
}

void Button::update(sf::Time deltaTime)
{
	timeout->update(deltaTime);
}

bool Button::isClicked(sf::Vector2f mousePosition)
{
	sf::FloatRect globalBounds = getTransform().transformRect(shape.getLocalBounds());
	return globalBounds.contains(mousePosition);
}

bool Button::isClicked(sf::Vector2f mousePosition, const sf::Transform & parentTransform)
{
	sf::Transform newTransform = getTransform() * parentTransform;
	sf::FloatRect globalBounds = newTransform.transformRect(shape.getLocalBounds());
	return globalBounds.contains(mousePosition);
}

void Button::handleMouseClick(sf::Vector2f mousePosition)
{
	if (isClicked(mousePosition) && !timeout->delaying)
	{
		callback();
		toggleActive();
		timeout->startTimeout(sf::seconds(0.3), std::bind(&Button::toggleActive, this));
	}
}

void Button::handleMouseClick(sf::Vector2f mousePosition, const sf::Transform & parentTransform)
{
	if (isClicked(mousePosition, parentTransform))
	{
		callback();
		toggleActive();
		timeout->startTimeout(sf::seconds(0.3), std::bind(&Button::toggleActive, this));
	}
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

void Button::toggleActive()
{
	if (!active)
	{
		shape.setOutlineThickness(-1.f);
		active = true;
	}
	else
	{
		shape.setOutlineThickness(1.f);
		active = false;
	}
}
