#ifndef ENEMY_H
#define ENEMY_H

#include "SFML/Graphics.hpp"
#include "Game.h"

class Enemy
{
public:
	Enemy(GameDataRef data);

	void DrawEnemy();
	void setTexture(std::string);

	sf::FloatRect getPosition();

	void Update(float dt, sf::FloatRect ballPos);

private:
	GameDataRef _data;
	sf::Sprite _paddle;
	sf::Texture _playerTexture;

	sf::Vector2f position;
	float paddleSpeed = 450.0f;
};

#endif