#include "game.h"

#include <SFML/Window/Event.hpp>


constexpr float kCooldown_limit_ = 0.15f;

Game::Game()
{

	window_.create(sf::VideoMode::getDesktopMode(), "Space Shooter", sf::Style::Fullscreen);

	music_1.openFromFile("assets\\foozle\\Foozle_Space_Music\\track_01\\v1.0_full_song.wav");
	music_1.setLoop(true);
	music_1.play();


	font_.loadFromFile("assets\\fonts\\arcade_classic_2\\ARCADECLASSIC.TTF");

	score_.setString("Score");// set the string to display
	score_.setFont(font_);
	score_.setCharacterSize(40); // set the character size in pixels, not points!
	score_.setFillColor(sf::Color::White);// set the color
	score_.setPosition(50, 50);

	hp_.setString("HP");// set the string to display
	hp_.setFont(font_);
	hp_.setCharacterSize(40); // set the character size in pixels, not points!
	hp_.setFillColor(sf::Color::White);// set the color
	hp_.setPosition(window_.getSize().x - 150, 50);

	game_over_.setString("Game Over!");// set the string to display
	game_over_.setFont(font_); 	// select the font
	game_over_.setCharacterSize(100); // set the character size in pixels, not points!
	game_over_.setFillColor(sf::Color::Green);// set the color
	game_over_.setPosition(window_.getSize().x / 2 - 250, window_.getSize().y / 2 - 50);

	sound_fx_laser_.loadFromFile("assets\\sound_effect\\kenney_sci-fi-sounds\\Audio\\laserSmall_002.ogg");
	laser_.setBuffer(sound_fx_laser_);
	laser_.setVolume(50);
}

void Game::Loop()
{
	window_.setMouseCursorVisible(false);

	double dt = 0.016f;

	int score_points = 0;

	int health_points = 0;


	while (window_.isOpen())
	{

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (player_ship_.IsShootReady())
			{
				player_projectiles_.Spawn(player_ship_.GetPosition(), { 0, -1500 });
				player_ship_.ShootConfirm();

				laser_.play();
			}
		}

		sf::Event event;
		while (window_.pollEvent(event))
		{

			if (event.type == sf::Event::MouseMoved)
				player_ship_.SetPosition(sf::Vector2u(event.mouseMove.x, event.mouseMove.y));

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					window_.close();
				}
			}
		}

		if (player_ship_.GetHP() > 0)
		{
			player_ship_.Refresh(dt);
		}

		asteroids_.Refresh(dt, window_.getSize());
		player_projectiles_.Refresh(dt, window_.getSize());

		projectiles_.Refresh(dt, window_.getSize());
		enemy_projectiles_.Refresh(dt, window_.getSize());
		enemy_ship_.Refresh(dt, window_.getSize(), enemy_projectiles_);


		if (player_ship_.GetHP() > 0)
		{
			// collisions for enemies
			player_ship_.CheckCollisions(asteroids_.GetEntities());
			player_ship_.CheckCollisions(enemy_projectiles_.GetEntities());
			player_ship_.CheckCollisions(enemy_ship_.GetEntities());

			//collisions for player
			player_ship_.CheckCollisionsAsteroids(asteroids_.GetEntities());
			player_ship_.CheckCollisionsProjectiles(enemy_projectiles_.GetEntities());
			player_ship_.CheckCollisionsEnemies(enemy_ship_.GetEntities());

		}

		player_manager_.Refresh(dt, window_.getSize(), player_projectiles_);

		//score
		score_points += player_projectiles_.CheckCollisions(asteroids_.GetEntities());

		score_points += 10 * player_projectiles_.CheckCollisions(enemy_ship_.GetEntities());

		score_.setString("Score " + std::to_string(score_points));

		//hp
		health_points = player_ship_.GetHP();

		hp_.setString("HP " + std::to_string(health_points));

		window_.clear();
		window_.draw(back_ground_);
		window_.draw(player_projectiles_);
		window_.draw(enemy_projectiles_);
		window_.draw(asteroids_);
		window_.draw(enemy_ship_);

		if (player_ship_.GetHP() > 0)
		{
			window_.draw(player_ship_);
			
		}
		else
		{
			window_.draw(game_over_);
		}
		
		window_.draw(score_);
		window_.draw(hp_);
		window_.display();

		dt = clock_.restart().asSeconds();
	}
	window_.setMouseCursorVisible(true);
}