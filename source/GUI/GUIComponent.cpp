#include "GUIComponent.h"

GUIComponent::GUIComponent()
{
}

GUIComponent::~GUIComponent()
{
}

bool GUIComponent::isSelectable()
{
	return false;
}

void GUIComponent::update(sf::Time deltaTime)
{
}

bool GUIComponent::isClicked(sf::Vector2f mousePosition)
{
	return false;
}

bool GUIComponent::isClicked(sf::Vector2f mousePosition, const sf::Transform & parentTransform)
{
	return false;
}

void GUIComponent::handleMouseClick(sf::Vector2f mousePosition)
{
}

void GUIComponent::handleMouseClick(sf::Vector2f mousePosition, const sf::Transform & parentTransform)
{
}

void GUIComponent::handleTextEntry(sf::Event::TextEvent textEntry)
{
}

sf::Vector2f GUIComponent::getSize()
{
	return sf::Vector2f();
}

