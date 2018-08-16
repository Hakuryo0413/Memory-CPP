
#pragma once
#include <functional>
#include "Widget.h"
#include "AssetManager.h"

class Button : public Widget
{
public:
    Button(std::string btnText, std::function<void()> callback);
	~Button();

	virtual bool isClicked(sf::Vector2f mousePosition);
	virtual void handleMouseClick();
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	std::function<void()> callback;

	static sf::Texture & buttonTexture;
	static sf::Font & buttonFont;

	sf::Sprite sprite;
	sf::Text text;
};