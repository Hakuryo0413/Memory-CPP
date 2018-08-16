#pragma once
#include <functional>
#include "GameScreen.h"
#include "GameBoard.h"
#include "Player.h"
#include "Widget.h"

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
	sf::Text * createLabel(std::string labelText, sf::Vector2f labelPosition);
	Widget * createButton(std::string btnText, std::function<void()> callback, sf::Vector2f widgetPosition);

	static sf::Font & labelFont;

	void renderWidgets(sf::RenderWindow &window);
	void renderLabels(sf::RenderWindow &window);
	void renderPlayerList(sf::RenderWindow &window);

	Widget* widgetClicked(sf::Vector2f mousePosition);

	std::vector<Widget *> widgets;
	std::vector<sf::Text *> labels;
	std::vector<Player *> players;
	sf::Vector2u boardSize;

	sf::Text * boardWidth;
	sf::Text * boardHeight;

	void decrementBoardWidth();
	void incrementBoardWidth();
	void decrementBoardHeight();
	void incrementBoardHeight();
	void createNewPlayer();

	std::string playerInput;
	sf::Text playerText;
};

