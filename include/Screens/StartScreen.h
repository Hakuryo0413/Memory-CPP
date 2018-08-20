#pragma once
#include <functional>
#include "GameScreen.h"
#include "SetTimeout.h"
#include "GameBoard.h"
#include "Player.h"
#include "GUIComponent.h"

class TextInput;

class StartScreen :
	public GameScreen
{
public:
	StartScreen(StateManager * stateManager);
	~StartScreen();

	virtual void renderScreen(sf::RenderWindow & window);
	virtual void updateScreen(sf::Time deltaTime);
	virtual void handleMouseClick(sf::Vector2f mousePosition);
	virtual void handleTextEntry(sf::Event::TextEvent textEvent);
private:
	void createGUI();
	void createLabel(std::string labelText, sf::Vector2f labelPosition, bool center = false);
	void createButton(std::string labelText, std::function<void()> callback,sf::Vector2f buttonPosition);
	void createCounter(unsigned * value, std::string labelText, sf::Vector2f widgetPosition);
	void createAddTextItem(std::string labelText, std::function<void(std::string text)> addItemCallback, sf::Vector2f widgetPosition);

	void renderWidgets(sf::RenderWindow & window);
	void renderPlayerList(sf::RenderWindow & window);

	float playerListHeight;
	float playerListIndent;

	std::vector<GUIComponent *> GUIComponents;
	std::vector<GUIComponent *> textInputs;
	std::vector<Player *> players;
	sf::Vector2u boardSize;

	SetTimeout * timeout;
	void removeErrorMessage();

	void createNewPlayer(std::string newPlayerName);
	bool settingsValidated;
	void validateSettings();
	void startGame();
};

