#pragma once
#include <SFML/Graphics.hpp>
#include "GameScreen.h"
#include "StartScreen.h"
#include "GameBoard.h"
#include "EndScreen.h"

#define WIDTH 800
#define HEIGHT 600

class Game
{
public:
	Game();
	~Game();

	void run();
	
private:
	sf::RenderWindow window;

	void processInput();
	void update();
	void render();

	void renderScreen();
	void handlePlayerInput(sf::Keyboard::Key key);

	unsigned numberOfPlayers;
	sf::Vector2u boardSize;

	enum class Screen
	{
		StartScreen, GameBoard, EndScreen
	};

	Screen currentScreen;

	GameScreen *startScreen;
	GameScreen *gameBoard;
	GameScreen *endScreen;
};

