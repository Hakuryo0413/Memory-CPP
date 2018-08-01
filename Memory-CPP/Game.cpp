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
			handlePlayerInput(event.key.code);
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

void Game::handlePlayerInput(sf::Keyboard::Key key)
{
}

