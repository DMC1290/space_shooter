#include "game.h"

#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

Game::Game()
{
	window_.create(sf::VideoMode(1200, 720), "Space Shooter");
	std::cout << "hello world" << '\n';
}

void Game::Loop()
{
	PlayerShip player;

	while (window_.isOpen())
	{

		
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window_);
		player.setPosition({ static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y) });


		sf::Event event;
		while (window_.pollEvent(event))
		{

			if (event.type == sf::Event::MouseButtonPressed)
			{
				projectiles_.Spawn(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
			}

			if (event.type == sf::Event::Closed)
			{
				window_.close();
			}
		}

		projectiles_.Refresh(dt_, window_.getSize());

		window_.clear();
		window_.draw(projectiles_);
		window_.draw(player);
		window_.display();

		dt_ = clock_.restart().asSeconds();
	}
}