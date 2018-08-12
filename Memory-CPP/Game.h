#pragma once
#include <SFML/Graphics.hpp>
#include "StartScreen.h"

#define WIDTH 600
#define HEIGHT 800
#define FRAMERATE 60

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
	void handleTextEntry();
	void handleEnterPressed();

	StateManager * stateManager;
};

