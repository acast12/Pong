#include "MainMenuState.h"
#include "GameState.h"
#include <sstream>
#include <iostream>

MainMenuState::MainMenuState(GameDataRef data) : _data(data) {}

void MainMenuState::init() {
    if (!_backgroundTexture.loadFromFile("images/MainMenuBackground.png"))
    {
        std::cerr << "failed to load Main Menu image" << std::endl;
        exit(1);
    }
    _background.setTexture(_backgroundTexture);

    if (!_playButtonTexture.loadFromFile("images/playButtonTexture.png"))
    {
        std::cerr << "failed to load Play Button image" << std::endl;
        exit(1);
    }
    _playButton.setTexture(_playButtonTexture);

    _playButton.setPosition((858 / 2) - (_playButton.getGlobalBounds().width / 2), (525 / 2) - (_playButton.getGlobalBounds().height / 2) + 100);
}

void MainMenuState::processEvents() {
    sf::Event event;
    while (_data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
            _data->window.close();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::IntRect tempRect(_playButton.getPosition().x, _playButton.getPosition().y, _playButton.getGlobalBounds().width, _playButton.getGlobalBounds().height);

            if (tempRect.contains(sf::Mouse::getPosition(_data->window))) {
                _data->machine.addState(StateRef(new GameState(_data)), true);
            }
        }
    }
}

void MainMenuState::update(float dt) {
    
}

void MainMenuState::draw(float dt) {
    _data->window.clear();

    _data->window.draw(_background);
    _data->window.draw(_playButton);

    _data->window.display();
}