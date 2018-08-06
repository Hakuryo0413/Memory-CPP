#include "stdafx.h"
#include "Game.h"


Game::Game() : window(sf::VideoMode(WIDTH, HEIGHT), "Memory")
{
	window.setFramerateLimit(60);
	numberOfPlayers = 1;
	boardSize = {4, 4};
	currentScreen = Screen::GameBoard;
	startScreen = new StartScreen();
	gameBoard = new GameBoard(boardSize);
}


Game::~Game()
{
	delete startScreen;
	delete gameBoard;
}

void Game::run()
{
	while (window.isOpen())
	{
		processInput();
		update();
		render();
	}
}

void Game::processInput()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				// sf::Vector2f mousePosition(event.mouseButton.x, event.mouseButton.y);
				sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
				handleMouseClick(mousePosition);
			}
			break;
		case sf::Event::TextEntered:
			handleTextEntry();
			break;
		case sf::Event::Closed:
			window.close();
			break;
		default:
			break;
		}
	}
}

void Game::update()
{
}

void Game::render()
{
	window.clear();
	renderScreen();
	window.display();
}

void Game::renderScreen()
{
	switch (currentScreen)
	{
	case Screen::StartScreen:
		startScreen->renderScreen(window);
		break;
	case Screen::GameBoard:
		gameBoard->renderScreen(window);
		break;
	case Screen::EndScreen:
		endScreen->renderScreen(window);
		break;
	default:
		break;
	}
}

void Game::handleMouseClick(sf::Vector2f mousePosition)
{
	switch (currentScreen)
	{
	case Screen::StartScreen:
		startScreen->handleMouseClick(mousePosition);
		break;
	case Screen::GameBoard:
		gameBoard->handleMouseClick(mousePosition);
		break;
	case Screen::EndScreen:
		endScreen->handleMouseClick(mousePosition);
		break;
	default:
		break;
	}
}

void Game::handleTextEntry()
{
}

