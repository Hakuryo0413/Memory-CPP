#include "stdafx.h"
#include "StartScreen.h"
#include "Counter.h"
#include "AddTextItem.h"
#include "TextInput.h"

StartScreen::StartScreen(StateManager * stateManager) :
	GameScreen(stateManager),
	boardSize(4, 4)
{
	createGUI();
}

StartScreen::~StartScreen()
{
	// delete[] labels;
	// delete[] widgets;
}

sf::Font & StartScreen::labelFont = AssetManager::getInstance()->getFont("Beleren-Bold.ttf");

void StartScreen::createGUI()
{
	createCounter(& boardSize.x, "Playing board width: ", {50.f, 100.f});
	createCounter(& boardSize.y, "Playing board height: ", {500.f, 100.f});
	createAddTextItem("Add Player", std::bind(&StartScreen::createNewPlayer, this), {200.f, 300.f});
	// labels.push_back(createLabel("Playing board width: ", {50.f, 100.f}));
	// widgets.push_back(createButton("-", std::bind(&StartScreen::decrementBoardWidth, this), {50.f, 200.f}));
	// boardWidth = createLabel(std::to_string(boardSize.x), { 120.f, 205.f });
	// labels.push_back(boardWidth);
	// widgets.push_back(createButton("+", std::bind(&StartScreen::incrementBoardWidth, this), {150.f, 200.f}));
	// labels.push_back(createLabel("Playing board height: ", {500.f, 100.f}));
	// widgets.push_back(createButton("-", std::bind(&StartScreen::decrementBoardHeight, this), {500.f, 200.f}));
	// boardHeight = createLabel(std::to_string(boardSize.x), { 570.f, 205.f });
	// labels.push_back(boardHeight);
	// widgets.push_back(createButton("+", std::bind(&StartScreen::incrementBoardHeight, this), {600.f, 200.f}));
	// labels.push_back(createLabel("Add Player", {50.f, 300.f}));
	// widgets.push_back(createButton("+", std::bind(&StartScreen::createNewPlayer, this), {200.f, 300.f}));
	// labels.push_back(createLabel("Players: ", {50.f, 400.f}));
}

void StartScreen::createCounter(unsigned * value, std::string labelText, sf::Vector2f widgetPosition)
{
	Widget * counter = new Counter(value, labelText);
	counter->setPosition(widgetPosition);
	widgets.push_back(counter);
}

void StartScreen::createAddTextItem(std::string labelText, std::function<void(std::string text)> addItemCallback, sf::Vector2f widgetPosition)
{
	Widget * addTextItem = new AddTextItem(labelText, addItemCallback);
	addTextItem->setPosition(widgetPosition);
	widgets.push_back(addTextItem);
	textInputs.push_back(addTextItem);
}

void StartScreen::renderScreen(sf::RenderWindow &window)
{
	renderWidgets(window);
	renderPlayerList(window);
}

void StartScreen::updateScreen(sf::Time deltaTime)
{
}

void StartScreen::handleMouseClick(sf::Vector2f mousePosition)
{

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
	players.push_back(new Player("Tihana"));
	players.push_back(new Player("Ivan"));
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

void StartScreen::createNewPlayer(std::string newPlayerName)
{
	Player * newPlayer = new Player(newPlayerName);
	players.push_back(newPlayer);
}