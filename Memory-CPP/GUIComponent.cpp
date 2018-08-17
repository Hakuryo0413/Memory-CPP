#include "stdafx.h"
#include "GUIComponent.h"

GUIComponent::GUIComponent()
	: selected(false)
{
}

GUIComponent::~GUIComponent()
{
}

bool GUIComponent::isSelectable()
{
	return false;
}

bool GUIComponent::isClicked(sf::Vector2f mousePosition)
{
	if (!isSelectable())
	{
		return false;
	}
}

bool GUIComponent::isSelected() const
{
	return selected;
}

void GUIComponent::select()
{
	selected = true;
}

void GUIComponent::deselect()
{
	selected = false;
}

void GUIComponent::handleMouseClick()
{

}

