#ifndef GAME_H
#define GAME_H

#include <SFML/Audio.hpp>

#include "projectiles_manager.h"
#include "asteroid_manager.h"
#include "back_ground.h"
#include "enemy_manager.h"
#include "player_ship_manager.h"

class Game
{
public:
	Game();
	void Loop();

private:
	sf::RenderWindow window_;

	BackGround back_ground_;

	ProjectilesManager projectiles_;
	ProjectilesManager player_projectiles_;
	ProjectilesManager enemy_projectiles_;

	AsteroidManager asteroids_;

	Enemy enemy_;
	EnemyManager enemy_ship_;

	PlayerShip player_ship_;
	PlayerShipManager player_manager_;

	sf::Clock clock_;

	sf::Music music_1;


	sf::SoundBuffer sound_fx_laser_;
	sf::Sound laser_;

	sf::SoundBuffer game_end_;
	sf::Sound over_;
	

	sf::Font font_;
	sf::Text score_;
	sf::Text hp_;
	sf::Text game_over_;
};
#endif