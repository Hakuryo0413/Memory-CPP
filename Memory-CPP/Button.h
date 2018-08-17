
#pragma once
#include "GUIComponent.h"
#include "AssetManager.h"
#include <functional>

class Button : public GUIComponent
{
public:
    Button(std::string btnText, std::function<void()> callback);
	~Button();

	bool isSelectable();
	virtual bool isClicked(sf::Vector2f mousePosition, sf::Transform parentTransform);
	virtual void handleMouseClick(sf::Vector2f mousePosition);
	virtual sf::Vector2f getSize();
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	std::function<void()> callback;

	static sf::Texture & buttonTexture;
	static sf::Font & buttonFont;

	sf::RectangleShape shape;
	sf::Text text;
};