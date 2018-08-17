#pragma once
#include "GUIComponent.h"

class TextInput : public GUIComponent
{
public:
	TextInput();
	~TextInput();

	virtual bool isSelectable();
	virtual bool isClicked(sf::Vector2f mousePosition, sf::Transform parentTransform);
	virtual void handleMouseClick(sf::Vector2f mousePosition);
	void handleTextEntry(sf::Event::TextEvent textEvent);
	virtual sf::Vector2f getSize();
	std::string getPlayerInput();
	void resetInput();
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void toggleSelected(bool direction);
	static sf::Font & inputFont;
	static sf::Color outlineColor;
	static sf::Color selectedOutlineColor;
	sf::RectangleShape shape;
	sf::Text playerText;
	std::string playerInput;
	bool selected;
};