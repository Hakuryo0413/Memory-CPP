#include "StartScreen.h"
#include "Counter.h"
#include "AddTextItem.h"
#include "Label.h"
#include "Button.h"

StartScreen::StartScreen(StateManager * stateManager) :
	GameScreen(stateManager),
	boardSize(4, 4),
	timeout(new SetTimeout),
	playerListHeight(500.f),
	playerListIndent(500.f),
	settingsValidated(false)
{
	createGUI();
}

StartScreen::~StartScreen()
{
	for (size_t i = 0; i < GUIComponents.size(); i++)
	{
		delete GUIComponents[i];
	}
	delete timeout;
}

void StartScreen::createGUI()
{
	createLabel("A Game of Memory", { 350.f, 50.f });
	createLabel("Welcome, Player!", { 360.f, 100.f });
	createLabel("Please choose the desired board width, and add players!", { 50.f, 200.f });
	createCounter(&boardSize.x, "Playing board width: ", { 50.f, 300.f });
	createCounter(&boardSize.y, "Playing board height: ", { 50.f, 450.f });
	createAddTextItem("Add Player", std::bind(&StartScreen::createNewPlayer, this, std::placeholders::_1), { 500.f, 300.f });
	createLabel("Players: ", { 500.f, 450.f });
	createButton("StartGame", std::bind(&StartScreen::validateSettings, this), { 50.f, 600.f });
}

void StartScreen::createLabel(std::string labelText, sf::Vector2f labelPosition)
{
	GUIComponent * label = new Label(labelText);
	label->setPosition(labelPosition);
	GUIComponents.push_back(label);
}

void StartScreen::createButton(std::string btnText, std::function<void()> callback, sf::Vector2f buttonPosition)
{
	GUIComponent * button = new Button(btnText, callback);
	button->setPosition(buttonPosition);
	GUIComponents.push_back(button);
}

void StartScreen::createCounter(unsigned * value, std::string labelText, sf::Vector2f widgetPosition)
{
	GUIComponent * counter = new Counter(value, labelText);
	counter->setPosition(widgetPosition);
	GUIComponents.push_back(counter);
}

void StartScreen::createAddTextItem(std::string labelText, std::function<void(std::string text)> addItemCallback, sf::Vector2f widgetPosition)
{
	GUIComponent * addTextItem = new AddTextItem(labelText, addItemCallback);
	addTextItem->setPosition(widgetPosition);
	GUIComponents.push_back(addTextItem);
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
	timeout->update(deltaTime);
	for (size_t i = 0; i < GUIComponents.size(); i++)
	{
		GUIComponents[i]->update(deltaTime);
	}
}

void StartScreen::handleMouseClick(sf::Vector2f mousePosition)
{
	if (timeout->delaying)
	{
		return;
	}
	for (size_t i = 0; i < GUIComponents.size(); i++)
	{
		GUIComponents[i]->handleMouseClick(mousePosition);
	}
	if (settingsValidated)
	{
		startGame();
	}
}

void StartScreen::handleTextEntry(sf::Event::TextEvent textEvent)
{
	for (size_t i = 0; i < textInputs.size(); i++)
	{
		textInputs[i]->handleTextEntry(textEvent);
	}
}

void StartScreen::renderWidgets(sf::RenderWindow & window)
{
	for (size_t i = 0; i < GUIComponents.size(); i++)
	{
		window.draw(*GUIComponents[i]);
	}
}

void StartScreen::renderPlayerList(sf::RenderWindow & window)
{
	for (size_t i = 0; i < players.size(); i++)
	{
		players[i]->renderPlayer(window, Player::PlayerComponents::Name);
	}
}

void StartScreen::removeErrorMessage()
{
	GUIComponents.pop_back();
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
	if (playerListIndent > 900)
	{
		playerListHeight = 500.f;
		playerListIndent = 500.f;
		players.end()[-12]->playerTag.setFillColor(sf::Color::Transparent);
	}
	players.push_back(newPlayer);
}

void StartScreen::validateSettings()
{
	if (players.size() == 0)
	{
		createLabel("Add at least one player!", { 50.f, 700.f });
		timeout->startTimeout(sf::seconds(1), std::bind(&StartScreen::removeErrorMessage, this));
	}
	else if (boardSize.x * boardSize.y % 2)
	{
		createLabel("A Memory Game has to have an even number of cards!", { 50.f, 700.f });
		timeout->startTimeout(sf::seconds(1), std::bind(&StartScreen::removeErrorMessage, this));
	}
	else
	{
		settingsValidated = true;
	}
}

void StartScreen::startGame()
{
	stateManager->setPlayers(players);
	stateManager->setBoardSize(boardSize);
	stateManager->switchScreen(StateManager::Screen::Gameboard);
}
