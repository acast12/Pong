#include "Paddle.h"
#include <iostream>

Paddle::Paddle(GameDataRef data) : _data(data) {
	_paddle.setOrigin(5, 25);
	position.x = 20;
	position.y = 262;
	_paddle.setPosition(position);
}

void Paddle::DrawPaddle() {
	_data->window.draw(_paddle);
}

void Paddle::setTexture(std::string texture) {

	if (!_playerTexture.loadFromFile(texture)) {
		std::cerr << "failed to load paddle screen image" << std::endl;
		exit(1);
	}
	_paddle.setTexture(_playerTexture);
}

sf::FloatRect Paddle::getPosition() {
	return _paddle.getGlobalBounds();
}

void Paddle::setMoveUp(bool moving) {
	isMovingUp = moving;
}
void Paddle::setMoveDown(bool moving) {
	isMovingDown = moving;
}

void Paddle::Update(float dt) {
	if (isMovingDown == true && _paddle.getPosition().y <= 500) {
		position.y += paddleSpeed * dt;
		_paddle.setPosition(position);
	}
	if (isMovingUp == true && _paddle.getPosition().y >= 25) {
		position.y -= paddleSpeed * dt;
		_paddle.setPosition(position);
	}
}