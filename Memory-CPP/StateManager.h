#pragma once
#include "Player.h"

class GameScreen;

class StateManager
{
public:
	StateManager();
	~StateManager();

	enum class Screen
	{
		StartScreen,
		Gameboard,
		EndScreen
	};

	void switchScreen(Screen nextScreen);
	std::vector<Player *> getPlayers();
	void setPlayers(std::vector<Player *> players);
	void setBoardSize(sf::Vector2u boardSize);
	void clearSettings();

	GameScreen* currentScreen;

	struct GameSettings
	{
		GameSettings() {};
		GameSettings(std::vector<Player *> players) : players(players) {};
		GameSettings(std::vector<Player *> players, sf::Vector2u boardSize) : players(players), boardSize(boardSize) {};
		std::vector<Player *> players;
		sf::Vector2u boardSize;
	};

	GameSettings * gameSettings;
};

