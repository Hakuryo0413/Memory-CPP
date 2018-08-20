#include "TableBorder.h"
#include "Settings.h"

TableBorder::TableBorder(std::vector<Player *> players) :
	players(players),
	currentPlayer(0),
	tableBorderView(new sf::View(sf::FloatRect(0, 0, WIDTH, HEIGHT)))
{
	tableRotation = new TableRotation(tableBorderView, sf::seconds(0.5f));
	createBackground();
	positionPlayers();
}

TableBorder::~TableBorder()
{
	delete tableRotation;
	delete tableBorderView;
}

const std::vector<sf::Vector2f> TableBorder::playerPositions = {{WIDTH / 2.f, HEIGHT - 25.f}, {WIDTH - 25.f, HEIGHT / 2.f}, {WIDTH / 2.f, 25.f}, {25.f, WIDTH / 2.f}};
const std::vector<float> TableBorder::playerRotations = {0.f, 270.f, 180.f, 90.f};

void TableBorder::renderTableBorder(sf::RenderWindow &window)
{
	window.setView(*tableBorderView);
	renderBackground(window);
	renderPlayers(window);
}

void TableBorder::updateTableBorder(sf::Time deltaTime)
{
	tableRotation->updateAnimated(deltaTime);
}

void TableBorder::callNextPlayer()
{
	if (players.size() == 2 || (players.size() == 3 && currentPlayer == 2))
	{
		tableRotation->startAnimation(180.f);
	}
	else
	{
		tableRotation->startAnimation(90.f);
	}


	if (players.size() > 4)
	{
		players[currentPlayer]->playerTag.setFillColor(sf::Color::Transparent);
		int newPlayer = currentPlayer + 4;
		if (newPlayer < players.size())
		{
			setPlayerLocation(players[newPlayer]->playerTag, newPlayer % 4);
			players[newPlayer]->playerTag.setFillColor(sf::Color::White);
		}
		else
		{
			setPlayerLocation(players[newPlayer - players.size()]->playerTag, newPlayer % 4);
			players[newPlayer - players.size()]->playerTag.setFillColor(sf::Color::White);
		}
	}

	if (currentPlayer + 1 < players.size())
	{
		currentPlayer++;
	}
	else
	{
		currentPlayer = 0;
	}
}

void TableBorder::score()
{
	players[currentPlayer]->increaseScore();
}

void TableBorder::positionPlayers()
{
	for (int i = 0; i < players.size(); i++)
	{
		players[i]->centarTag();

		if (i < 4)
		{
			setPlayerLocation(players[i]->playerTag, i);
		}
		else
		{
			players[i]->playerTag.setFillColor(sf::Color::Transparent);
		}
		if (players.size() == 2 && i == 1)
		{
			setPlayerLocation(players[i]->playerTag, 2);
		}
	}
}

void TableBorder::setPlayerLocation(sf::Text & playerTag, int position)
{
	playerTag.setPosition(playerPositions[position]);
	playerTag.setRotation(playerRotations[position]);
	playerTag.setFillColor(sf::Color::White);
}

void TableBorder::createBackground()
{
	for(size_t i = 0; i < 4; i++)
	{
		sf::RectangleShape backgroundShape;
		if (i % 2)
		{
			backgroundShape.setSize({ WIDTH - 50.f, 50.f });
			backgroundShape.setOrigin({ WIDTH / 2.f, 25.f });
		}
		else {
			backgroundShape.setSize({ HEIGHT - 50.f, 50.f });
			backgroundShape.setOrigin({ HEIGHT / 2.f, 25.f });
		}
		backgroundShape.setFillColor(sf::Color(0, 0, 0, 50));
		backgroundShape.setPosition(playerPositions[i]);
		backgroundShape.setRotation(playerRotations[i]);
		tableBorderBackground.push_back(backgroundShape);
	}
}

void TableBorder::renderBackground(sf::RenderWindow & window)
{
	for (size_t i = 0; i < tableBorderBackground.size(); i++)
	{
		window.draw(tableBorderBackground[i]);
	}
}

void TableBorder::renderPlayers(sf::RenderWindow & window)
{
	for (size_t i = 0; i < players.size(); i++)
	{
		players[i]->renderPlayer(window, Player::PlayerComponents::Name);
	}
}
