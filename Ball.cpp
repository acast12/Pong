#include "Ball.h"
#include <cmath>
#include <iostream>

Ball::Ball(GameDataRef data) : _data(data) {
	_ball.setOrigin(5,5);
	position.x = 429;
	position.y = 262;
	_ball.setPosition(position);
}

void Ball::DrawBall() {
	_data->window.draw(_ball);
}

void Ball::setTexture(std::string texture) {

	if (!_ballTexture.loadFromFile(texture)) {
		std::cerr << "failed to load paddle screen image" << std::endl;
		exit(1);
	}
	_ball.setTexture(_ballTexture);
}

sf::FloatRect Ball::getPosition() {
	return _ball.getGlobalBounds();
}

void Ball::bounceSides() {
	yDirection = -yDirection;
}

void Ball::bouncePaddle() {
	xDirection = -xDirection;
}



void Ball::Update(float dt, sf::FloatRect playerPos, sf::FloatRect enemyPos, int &playerScore, int &EnemyScore) {
	if (_ball.getGlobalBounds().top < 0 || (_ball.getGlobalBounds().top + _ball.getGlobalBounds().height) > 525) {
		bounceSides();
	}
	if (_ball.getGlobalBounds().intersects(playerPos)) {
		float relativeIntersectY = playerPos.getPosition().y + 25 - _ball.getGlobalBounds().getPosition().y - 5;
		float normalizedRelativeIntersectY = relativeIntersectY / 25;
		float bounceAngle = normalizedRelativeIntersectY * maxAngle;
		xDirection = -xDirection;
		yDirection = -sin(bounceAngle);
	}
	if (_ball.getGlobalBounds().intersects(enemyPos)) {
		float relativeIntersectY = enemyPos.getPosition().y + 25 - _ball.getGlobalBounds().getPosition().y;
		float normalizedRelativeIntersectY = relativeIntersectY / 25;
		float bounceAngle = normalizedRelativeIntersectY * maxAngle;
		xDirection = -xDirection;
		yDirection = -sin(bounceAngle);
	}
	// reset ball if past bounds, increase score
	if (_ball.getGlobalBounds().left + 10 < playerPos.getPosition().x) {
		++EnemyScore;
		position.x = 429;
		position.y = 262;
		xDirection = 1.0f;
	}
	if (_ball.getGlobalBounds().left > enemyPos.getPosition().x) {
		++playerScore;
		position.x = 429;
		position.y = 262;
		xDirection = 1.0f;
	}
	position.x += xDirection * ballSpeed * dt;
	position.y += yDirection * ballSpeed * dt;

	_ball.setPosition(position);
}
