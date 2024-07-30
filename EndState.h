#ifndef ENDSTATE_H
#define ENDSTATE_H

#include "SFML/Graphics.hpp"
#include "State.h"
#include "Game.h"


class EndState : public State
{
public:
	EndState(GameDataRef data);

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