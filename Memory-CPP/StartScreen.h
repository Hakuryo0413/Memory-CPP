#pragma once
#include <functional>
#include "GameScreen.h"
#include "GameBoard.h"
#include "Player.h"
#include "Widget.h"

class TextInput;

class StartScreen :
	public GameScreen
{
public:
	StartScreen(StateManager * stateManager);
	~StartScreen();
	void renderScreen(sf::RenderWindow &window);
	void updateScreen(sf::Time deltaTime);
	void handleMouseClick(sf::Vector2f mousePosition);
	void handleTextEntry(sf::Event::TextEvent textEvent);
	void handleEnterPressed();
private:
	void createGUI();
	void createCounter(unsigned * value, std::string labelText, sf::Vector2f widgetPosition);
	void createAddTextItem(std::string labelText, std::function<void(std::string text)> addItemCallback, sf::Vector2f widgetPosition);

	static sf::Font & labelFont;

	void renderWidgets(sf::RenderWindow &window);
	void renderLabels(sf::RenderWindow &window);
	void renderPlayerList(sf::RenderWindow &window);

	std::vector<Widget *> widgets;
	std::vector<Widget *> textInputs;
	std::vector<Player *> players;
	sf::Vector2u boardSize;

	void changeBoardSize(bool direction);
	void createNewPlayer(std::string newPlayerName);
};

