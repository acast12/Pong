#ifndef GAME_H
#define GAME_H

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"

struct GameData
{
	StateMachine machine;
	sf::RenderWindow window;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
public:
	Game();

private:
	const float dt = 1.0f / 60.0f;
	sf::Clock _clock;

	GameDataRef _data = std::make_shared<GameData>();

	void run();
};

#endif

