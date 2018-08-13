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
	GameScreen* currentScreen;

	struct GameSettings
	{
		GameSettings() {};
		GameSettings(std::vector<Player *> players) : players(players) {};
		GameSettings(std::vector<Player *> players, sf::Vector2u boardSize) : players(players), boardSize(boardSize) {};
		std::vector<Player *> players;
		sf::Vector2u boardSize;
		void clearSettings()
		{
			players.clear();
			boardSize = { 0, 0 };
		}
	};

	void setGameSettings(GameSettings * gameSettings);
	GameSettings * getGameSettings();

private:
	GameSettings * gameSettings;
};

