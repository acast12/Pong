#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "SFML/Graphics.hpp"
#include "State.h"
#include "Game.h"
#include "Paddle.h"
#include "Ball.h"
#include "Enemy.h"


class GameState : public State
{
public:
	GameState(GameDataRef data);

	void init();

	void processEvents();
	void update(float dt);
	void draw(float dt);

	int playerScore = 0;
	int enemyScore = 0;

private:
	GameDataRef _data;

	sf::Texture _backgroundTexture;
	sf::Sprite _background;

	sf::Texture _topWallTexture;
	sf::Sprite _topWall;

	sf::Texture _bottomWallTexture;
	sf::Sprite _bottomWall;

	Paddle* player;
	Enemy* enemy;
	Ball* ball;

	sf::Text playerScoreboard;
	sf::Text enemyScoreboard;
	sf::Font font;

};

#endif 