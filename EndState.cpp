#include "EndState.h"

#include <sstream>
#include <iostream>

EndState::EndState(GameDataRef data) : _data(data) {}

void EndState::init() {
    if (!_backgroundTexture.loadFromFile("images/EndScreen.png"))
    {
        std::cerr << "failed to load end screen image" << std::endl;
        exit(1);
    }
    _background.setTexture(_backgroundTexture);
}

void EndState::processEvents() {
    sf::Event event;
    while (_data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
            _data->window.close();
        }
        if (_clock.getElapsedTime().asSeconds() > 3.0) {
            exit(1);
        }
    }
}

void EndState::update(float dt) {
    
}

void EndState::draw(float dt) {
    _data->window.clear();

    _data->window.draw(_background);

    _data->window.display();
}