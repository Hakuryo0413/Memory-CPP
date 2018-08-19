#pragma once
#include "GUIComponent.h"
#include <functional>

class TextInput : public GUIComponent
{
public:
	TextInput();
	~TextInput();

	virtual bool isSelectable();
	virtual bool isClicked(sf::Vector2f mousePosition);
	virtual bool isClicked(sf::Vector2f mousePosition, const sf::Transform & parentTransform);
	virtual void handleMouseClick(sf::Vector2f mousePosition);
	virtual void handleMouseClick(sf::Vector2f mousePosition, const sf::Transform & parentTransform);
	virtual void handleTextEntry(sf::Event::TextEvent textEvent);
	virtual sf::Vector2f getSize();
	std::string getPlayerInput();
	void resetInput();
	void setEnterCallback(std::function<void()> callback);
private:
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

	void toggleSelected(bool direction);
	sf::RectangleShape shape;
	sf::Text playerText;
	std::string playerInput;
	bool selected;
	std::function<void()> callback;
};