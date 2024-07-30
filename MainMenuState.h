#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H


#include "SFML/Graphics.hpp"
#include "State.h"
#include "Game.h"


class MainMenuState : public State
{
public:
	MainMenuState(GameDataRef data);

	void init();

	void processEvents();
	void update(float dt);
	void draw(float dt);

private:
	GameDataRef _data;

	sf::Sprite _background;
	sf::Texture _backgroundTexture;
	
	sf::Sprite _playButton;
	sf::Texture _playButtonTexture;
};

#endif

