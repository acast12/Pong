#include "Enemy.h"
#include <iostream>

Enemy::Enemy(GameDataRef data) : _data(data) {
	_paddle.setOrigin(5, 25);
	position.x = 838;
	position.y = 262;
	_paddle.setPosition(position);
}

void Enemy::DrawEnemy() {
	_data->window.draw(_paddle);
}

void Enemy::setTexture(std::string texture) {

	if (!_playerTexture.loadFromFile(texture)) {
		std::cerr << "failed to load paddle screen image" << std::endl;
		exit(1);
	}
	_paddle.setTexture(_playerTexture);
}

sf::FloatRect Enemy::getPosition() {
	return _paddle.getGlobalBounds();
}


void Enemy::Update(float dt, sf::FloatRect ballPos) {
	if (ballPos.getPosition().y > _paddle.getPosition().y && _paddle.getPosition().y <= 500) {
		position.y += paddleSpeed * dt;
		_paddle.setPosition(position);
	}
	if (ballPos.getPosition().y < _paddle.getPosition().y && _paddle.getPosition().y >= 25) {
		position.y -= paddleSpeed * dt;
		_paddle.setPosition(position);
	}
}