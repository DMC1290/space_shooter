#ifndef GAME_H
#define GAME_H

#include "projectiles_manager.h"
#include "player_ship.h"
#include "asteroid_manager.h"
#include "enemy_manager.h"
#include "player_ship_manager.h"

class Game
{
public:
	Game();
	void Loop();

private:
	sf::RenderWindow window_;

	ProjectilesManager projectiles_;
	ProjectilesManager player_projectiles_;
	ProjectilesManager enemy_projectiles_;

	AsteroidManager asteroids_;
	EnemyManager enemy_ship_;

	PlayerShip player_ship_;
	PlayerShipManager player_manager_;
	sf::Clock clock_;
};
#endif