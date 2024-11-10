#include "game.h"


#include <SFML/Window/Event.hpp>


constexpr float kCooldown_limit_ = 0.15f;

Game::Game()
{
	window_.create(sf::VideoMode::getDesktopMode(), "Space Shooter", sf::Style::Fullscreen);
}


void Game::Loop()
{

	window_.setMouseCursorVisible(false);

	double dt = 0.016f;

	while (window_.isOpen())
	{

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (player_ship_.IsShootReady())
			{
				player_projectiles_.Spawn(player_ship_.GetPosition(), { 0, -1500 });
				player_ship_.ShootConfirm();
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

		projectiles_.Refresh(dt, window_.getSize());
		asteroids_.Refresh(dt, window_.getSize());
		enemy_projectiles_.Refresh(dt, window_.getSize());
		enemy_ship_.Refresh(dt, window_.getSize(), enemy_projectiles_);

		enemy_projectiles_.Refresh(dt, window_.getSize());
		enemy_ship_.Refresh(dt, window_.getSize(), enemy_projectiles_);

		player_ship_.CheckCollisions(asteroids_.GetEntities());
		player_ship_.CheckCollisions(enemy_ship_.GetEntities());
		player_ship_.CheckCollisions(enemy_projectiles_.GetEntities());

		player_projectiles_.Refresh(dt, window_.getSize());
		player_projectiles_.CheckCollisions(asteroids_.GetEntities());
		player_projectiles_.CheckCollisions(enemy_ship_.GetEntities());


		window_.clear();

		window_.draw(player_projectiles_);
		window_.draw(enemy_projectiles_);
		window_.draw(asteroids_);
		window_.draw(enemy_ship_);
		window_.draw(player_ship_);
		window_.display();

		dt = clock_.restart().asSeconds();
	}
	window_.setMouseCursorVisible(true);
}