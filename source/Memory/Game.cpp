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
	stateManager->gameSettings->boardSize = { 4, 4 };
	stateManager->switchScreen(StateManager::Screen::Gameboard);
	//stateManager->switchScreen(StateManager::Screen::StartScreen);
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
		case sf::Event::TextEntered:
			handleTextEntry(event.text);
			break;
		//case sf::Event::Resized:
		//	sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
		//	window.setView(sf::View(visibleArea));
		//	break;
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
	window.clear(sf::Color(255, 255, 255, 0));
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

void Game::handleTextEntry(sf::Event::TextEvent textEvent)
{
	stateManager->currentScreen->handleTextEntry(textEvent);
}
