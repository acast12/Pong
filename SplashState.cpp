#include "SplashState.h"
#include "MainMenuState.h"
#include <sstream>
#include <iostream>

SplashState::SplashState(GameDataRef data) : _data(data) {}

void SplashState::init() {
    if (!_backgroundTexture.loadFromFile("images/SplashScreenBackground.png"))
    {
        std::cerr << "failed to load splash screen image" << std::endl;
        exit(1);
    }
    _background.setTexture(_backgroundTexture);
}

void SplashState::processEvents() {
    sf::Event event;
    while (_data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
            _data->window.close();
        }
    }
}

void SplashState::update(float dt) {
    if (_clock.getElapsedTime().asSeconds() > 3.0) {
        _data->machine.addState(StateRef(new MainMenuState(_data)), true);
    }
}

void SplashState::draw(float dt) {
    _data->window.clear();

    _data->window.draw(_background);

    _data->window.display();
}