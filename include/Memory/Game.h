#pragma once
#include <SFML/Graphics.hpp>
#include "StartScreen.h"
#include "Settings.h"

class StateManager;

class Game
{
public:
	Game();
	~Game();

	void run();

private:
	sf::RenderWindow window;

	void processInput();
	void update(sf::Time deltaTime);
	void render();

	void renderScreen();
	void handleMouseClick(sf::Vector2f mousePosition);
	void handleTextEntry(sf::Event::TextEvent textEvent);

	StateManager * stateManager;
};

