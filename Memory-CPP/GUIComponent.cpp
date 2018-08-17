#include "stdafx.h"
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

bool GUIComponent::isClicked(sf::Vector2f mousePosition, sf::Transform parentTransform)
{
	return false;
}

void GUIComponent::handleMouseClick(sf::Vector2f mousePosition)
{

}

void GUIComponent::handleTextEntry(sf::Event::TextEvent textEntry)
{
}

sf::Vector2f GUIComponent::getSize()
{
	return sf::Vector2f();
}

