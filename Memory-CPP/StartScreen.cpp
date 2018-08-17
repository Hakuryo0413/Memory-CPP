#include "stdafx.h"
#include "StartScreen.h"
#include "Counter.h"
#include "AddTextItem.h"
#include "Label.h"
#include "Button.h"

StartScreen::StartScreen(StateManager * stateManager) :
	GameScreen(stateManager),
	boardSize(4, 4),
	errorMessageTimeout(new SetTimeout),
	playerListHeight(500.f),
	playerListIndent(500.f)
{
	createGUI();
}

StartScreen::~StartScreen()
{
	// delete[] labels;
	// delete[] widgets;
}

void StartScreen::createGUI()
{
	createLabel("A Game of Memory", { 350.f, 50.f });
	createLabel("Welcome, Player!", { 360.f, 100.f });
	createLabel("Please choose the desired board width, and add players!", { 50.f, 200.f });
	createCounter(& boardSize.x, "Playing board width: ", {50.f, 300.f});
	createCounter(& boardSize.y, "Playing board height: ", {50.f, 450.f});
	createAddTextItem("Add Player", std::bind(&StartScreen::createNewPlayer, this, std::placeholders::_1), {500.f, 300.f});
	createLabel("Players: ", { 500.f, 450.f });
	//createButton("StartGame", std::bind(&StartScreen::startGame, this), { 50.f, 600.f });
}

void StartScreen::createLabel(std::string labelText, sf::Vector2f labelPosition)
{
	GUIComponent * label = new Label(labelText);
	label->setPosition(labelPosition);
	widgets.push_back(label);
}

void StartScreen::createButton(std::string buttonText, std::function<void()> callback, sf::Vector2f buttonPosition)
{
	GUIComponent * button = new Button(buttonText, callback);
	button->setPosition(buttonPosition);
	widgets.push_back(button);
}

void StartScreen::createCounter(unsigned * value, std::string labelText, sf::Vector2f widgetPosition)
{
	GUIComponent * counter = new Counter(value, labelText);
	counter->setPosition(widgetPosition);
	widgets.push_back(counter);
}

void StartScreen::createAddTextItem(std::string labelText, std::function<void(std::string text)> addItemCallback, sf::Vector2f widgetPosition)
{
	GUIComponent * addTextItem = new AddTextItem(labelText, addItemCallback);
	addTextItem->setPosition(widgetPosition);
	widgets.push_back(addTextItem);
	textInputs.push_back(addTextItem);
}

void StartScreen::renderScreen(sf::RenderWindow &window)
{
	GameScreen::renderScreen(window);
	renderWidgets(window);
	renderPlayerList(window);
}

void StartScreen::updateScreen(sf::Time deltaTime)
{
}

void StartScreen::handleMouseClick(sf::Vector2f mousePosition)
{
	if (errorMessageTimeout->delaying)
	{
		return;
	}
	for(size_t i = 0; i < widgets.size(); i++)
	{
		widgets[i]->handleMouseClick(mousePosition);
	}
}

void StartScreen::handleTextEntry(sf::Event::TextEvent textEvent)
{
	for(size_t i = 0; i < textInputs.size(); i++)
	{
		textInputs[i]->handleTextEntry(textEvent);
	}
}

void StartScreen::handleEnterPressed()
{
	stateManager->setPlayers(players);
	stateManager->setBoardSize(boardSize);
	stateManager->switchScreen(StateManager::Screen::Gameboard);
}

void StartScreen::renderWidgets(sf::RenderWindow &window)
{
	for (size_t i = 0; i < widgets.size(); i++)
	{
		window.draw(*widgets[i]);
	}
}

void StartScreen::renderPlayerList(sf::RenderWindow &window)
{
	for (size_t i = 0; i < players.size(); i++)
	{
		players[i]->renderPlayer(window, Player::PlayerComponents::Name);
	}
}

void StartScreen::removeErrorMessage()
{
	widgets.pop_back();
}

void StartScreen::createNewPlayer(std::string newPlayerName)
{
	Player * newPlayer = new Player(newPlayerName);
	newPlayer->playerTag.setPosition(playerListIndent, playerListHeight);
	playerListHeight += newPlayer->playerTag.getCharacterSize() + 15.f;
	if (playerListHeight > 700.f)
	{
		playerListHeight = 500.f;
		playerListIndent += 150.f;
	}
	players.push_back(newPlayer);
}

void StartScreen::startGame()
{
	if (players.size() < 1)
	{
		//createLabel("Add at least one player!", { 50.f, 700.f });
		//errorMessageTimeout->startTimeout(sf::seconds(1), std::bind(&StartScreen::removeErrorMessage, this));
	}
	stateManager->setPlayers(players);
	stateManager->setBoardSize(boardSize);
	stateManager->switchScreen(StateManager::Screen::Gameboard);
}
