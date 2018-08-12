#include "stdafx.h"
#include "Game.h"

Game::Game() : 
	window(sf::VideoMode(WIDTH, HEIGHT), "Memory"),
	stateManager(new StateManager())
{
	window.setFramerateLimit(FRAMERATE);
}


Game::~Game()
{
	delete stateManager;
}

void Game::run()
{
	sf::Clock clock;
	stateManager->switchScreen(new StartScreen(stateManager));
	while (window.isOpen())
	{
		sf::Time deltaTime = clock.restart();
		processInput();
		update(deltaTime);
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
				sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
				handleMouseClick(mousePosition);
			}
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Enter)
			{
				handleEnterPressed();
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

void Game::update(sf::Time deltaTime)
{
	stateManager->currentScreen->updateScreen(deltaTime);
}

void Game::render()
{
	window.clear();
	renderScreen();
	window.display();
}

void Game::renderScreen()
{
	stateManager->currentScreen->renderScreen(window);
}

void Game::handleMouseClick(sf::Vector2f mousePosition)
{
	stateManager->currentScreen->handleMouseClick(mousePosition);
}

void Game::handleTextEntry()
{
}

void Game::handleEnterPressed()
{
	stateManager->currentScreen->handleEnterPressed();
}

