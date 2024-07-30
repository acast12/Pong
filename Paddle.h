#ifndef PADDLE_H
#define PADDLE_H

#include "SFML/Graphics.hpp"
#include "Game.h"

class Paddle
{
public:
	Paddle(GameDataRef data);

	void DrawPaddle();
	void setTexture(std::string);

	void Update(float dt);

	void setMoveUp(bool);
	void setMoveDown(bool);

	sf::FloatRect getPosition();
private:
	GameDataRef _data;
	sf::Sprite _paddle;
	sf::Texture _playerTexture;

	sf::Vector2f position;
	float paddleSpeed = 450.0f;

	bool isMovingUp;
	bool isMovingDown;
};

#endif