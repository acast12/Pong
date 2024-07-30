#ifndef SPLASHSTATE_H
#define SPLASHSTATE_H

#include "SFML/Graphics.hpp"
#include "State.h"
#include "Game.h"


class SplashState : public State
{
public:
	SplashState(GameDataRef data);

	void init();

	void processEvents();
	void update(float dt);
	void draw(float dt);

private:
	GameDataRef _data;

	sf::Clock _clock;
	sf::Texture _backgroundTexture;
	sf::Sprite _background;
};

#endif 