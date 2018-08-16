#include "stdafx.h"
#include "StartScreen.h"
#include "Button.h"

StartScreen::StartScreen(StateManager * stateManager) :
	GameScreen(stateManager)
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
	labels.push_back(createLabel("Playing board width: ", {50.f, 100.f}));
	widgets.push_back(createButton("-", std::bind(&StartScreen::decrementBoardWidth, this), {50.f, 200.f}));
	widgets.push_back(createButton("+", std::bind(&StartScreen::incrementBoardWidth, this), {100.f, 200.f}));
	labels.push_back(createLabel("Playing board height: ", {200.f, 100.f}));
	widgets.push_back(createButton("-", std::bind(&StartScreen::decrementBoardHeight, this), {200.f, 200.f}));
	widgets.push_back(createButton("+", std::bind(&StartScreen::incrementBoardHeight, this), {250.f, 200.f}));
	labels.push_back(createLabel("Add Player", {50.f, 300.f}));
	widgets.push_back(createButton("+", std::bind(&StartScreen::createNewPlayer, this), {200.f, 300.f}));
	labels.push_back(createLabel("Players: ", {50.f, 400.f}));
}

sf::Text * StartScreen::createLabel(std::string labelText, sf::Vector2f labelPosition)
{
	sf::Text * label = new sf::Text(labelText, labelFont);
	label->setPosition(labelPosition);
	return label;
}

Widget * StartScreen::createButton(std::string btnText, std::function<void()> callback, sf::Vector2f widgetPosition)
{
	Widget * widget = new Button(btnText, callback);
	widget->setPosition(widgetPosition);
	return widget;
}

void StartScreen::renderScreen(sf::RenderWindow &window)
{
	renderWidgets(window);
	renderLabels(window);
	renderPlayerList(window);
}

void StartScreen::updateScreen(sf::Time deltaTime)
{
}

void StartScreen::handleMouseClick(sf::Vector2f mousePosition)
{
	Widget * clickedWidget = widgetClicked(mousePosition);
	if (clickedWidget)
	{
		clickedWidget->handleMouseClick();
	}
}

void StartScreen::handleTextEntry(sf::Event::TextEvent textEvent)
{
	playerInput += textEvent.unicode;
	playerText.setString(playerInput);
}

void StartScreen::handleEnterPressed()
{
	players.push_back(new Player("Tihana"));
	players.push_back(new Player("Ivan"));
	boardSize = { 4, 4 };
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

void StartScreen::renderLabels(sf::RenderWindow &window)
{
	for (size_t i = 0; i < labels.size(); i++)
	{
		window.draw(*labels[i]);
	}
}

void StartScreen::renderPlayerList(sf::RenderWindow &window)
{
	for (size_t i = 0; i < players.size(); i++)
	{
		players[i]->renderPlayer(window, Player::PlayerComponents::Name);
	}
}

Widget * StartScreen::widgetClicked(sf::Vector2f mousePosition)
{
	for (size_t i = 0; i < widgets.size(); i++)
	{
		if (widgets[i]->isClicked(mousePosition))
		{
			return widgets[i];
			break;
		}
	}
	return nullptr;
}

void StartScreen::decrementBoardWidth()
{
	boardSize.x++;
}

void StartScreen::incrementBoardWidth()
{
	boardSize.x--;
}

void StartScreen::decrementBoardHeight()
{
	boardSize.y++;
}

void StartScreen::incrementBoardHeight()
{
	boardSize.y--;
}

void createNewPlayer()
{
	// Player * newPlayer = new Player();
	// players.push_back(player);
}