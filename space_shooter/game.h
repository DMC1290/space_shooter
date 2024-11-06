#ifndef GAME_H
#define GAME_H
#include "projectiles_manager.h"
#include "spaceship.h"
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	void Loop();

private:
	sf::RenderWindow window_;
	ProjectilesManager projectiles_;
	//PlayerShip player_ship_;
	sf::Clock clock_;
	float dt_ = 0.016f;
};
#endif