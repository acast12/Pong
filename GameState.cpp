#include "GameState.h"
#include "EndState.h"
#include <sstream>
#include <iostream>

GameState::GameState(GameDataRef data) : _data(data) {}

void GameState::init() {
    if (!_backgroundTexture.loadFromFile("images/gameBackground.png")) {
        std::cerr << "failed to load game screen image" << std::endl;
        exit(1);
    }
    _background.setTexture(_backgroundTexture);

    player = new Paddle(_data);
    player->setTexture("images/PaddleTexture.png");

    ball = new Ball(_data);
    ball->setTexture("images/ballTexture.png");

    enemy = new Enemy(_data);
    enemy->setTexture("images/PaddleTexture.png");

    font.loadFromFile("fonts/Minecraftia.ttf");
    playerScoreboard.setFont(font);
    playerScoreboard.setCharacterSize(24);
    playerScoreboard.setPosition(214, 40);
    playerScoreboard.setString(std::to_string(playerScore));

    enemyScoreboard.setFont(font);
    enemyScoreboard.setCharacterSize(24);
    enemyScoreboard.setPosition(643, 40);
    enemyScoreboard.setString(std::to_string(enemyScore));
    
}

void GameState::processEvents() {
    sf::Event event;
    while (_data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
            _data->window.close();
        }

        if (playerScore == 10 || enemyScore == 10) {
            _data->machine.addState(StateRef(new EndState(_data)), true);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
           player->setMoveUp(true);
        }
        else {
            player->setMoveUp(false);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            player->setMoveDown(true);
        }
        else {
            player->setMoveDown(false);
        }
    }
}

void GameState::update(float dt) {
    player->Update(dt);
    ball->Update(dt, player->getPosition(), enemy->getPosition(), playerScore, enemyScore);
    enemy->Update(dt, ball->getPosition());
    playerScoreboard.setString(std::to_string(playerScore));
    enemyScoreboard.setString(std::to_string(enemyScore));
}

void GameState::draw(float dt) {
    _data->window.clear();

    _data->window.draw(_background);
    _data->window.draw(playerScoreboard);
    _data->window.draw(enemyScoreboard);
    player->DrawPaddle();
    enemy->DrawEnemy();
    ball->DrawBall();

    _data->window.display();
}