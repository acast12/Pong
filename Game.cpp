#include "Game.h"
#include "SplashState.h""

Game::Game() {
	_data->window.create(sf::VideoMode(858, 525), "SFML PONG", sf::Style::Close | sf::Style::Titlebar);
	_data->machine.addState(StateRef(new SplashState(this->_data)));
	this->run();
}

void Game::run() {
	float newTime, frameTime, interpolation;
	float currentTime = this->_clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	while (this->_data->window.isOpen()) {
		this->_data->machine.processStateEvents();

		newTime = this->_clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;

		if (frameTime > 0.25f) {
			frameTime = 0.25f;
		}

		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= dt) {
			this->_data->machine.getActiveState()->processEvents();
			this->_data->machine.getActiveState()->update(dt);
			accumulator -= dt;
		}

		interpolation = accumulator / dt;
		this->_data->machine.getActiveState()->draw(interpolation);
	}
}