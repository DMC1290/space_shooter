#include "asteroid_manager.h"

#include <random>

void AsteroidManager::Refresh(const double dt, const sf::Vector2u& window_size)
{

	spawn_dt_ += dt;
	if(spawn_dt_ > 1)
	{
		asteroids_.emplace_back();

		//tirage aléatoire de Y
		std::random_device rn_device;
		std::default_random_engine engine(rn_device());
		std::uniform_real_distribution <float> uniform_dist(500, 1500);

		asteroids_.back().SetPosition(uniform_dist(engine), 0);

		spawn_dt_ = 0;
	}

	auto removed_elt = std::remove_if
	(
		asteroids_.begin(),
		asteroids_.end(),
		[](const Asteroid& a) {return a.IsDead(); }
	);

	if (removed_elt != asteroids_.end())
	{
		asteroids_.erase(removed_elt, asteroids_.end());
	}

	for (Asteroid& a: asteroids_)
	{
		a.Move(dt, window_size);
	}
}

void AsteroidManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto& myAsteroid : asteroids_)
	{
		target.draw(myAsteroid);
	}
}