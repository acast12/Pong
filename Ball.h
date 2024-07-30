#ifndef BALL_H
#define BALL_H

#include "SFML/Graphics.hpp"
#include "Game.h"

class Ball
{
public:
	Ball(GameDataRef data);

	void DrawBall();
	void setTexture(std::string);

	sf::FloatRect getPosition();
	void bounceSides();
	void bouncePaddle();

	void Update(float dt, sf::FloatRect playerPos, sf::FloatRect enemyPos, int &playerScore, int &enemyScore);

private:
	GameDataRef _data;
	sf::Sprite _ball;
	sf::Texture _ballTexture;

	sf::Vector2f position;
	float ballSpeed = 500.0f;
	float xDirection = 1.0f;
	float yDirection = 0.0f;

	sf::Clock _clock;

	int maxAngle = 50;
};

#endif
