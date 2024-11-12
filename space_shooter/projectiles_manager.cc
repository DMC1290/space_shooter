#include "projectiles_manager.h"

#include <iostream>

#include "asteroid.h"


void ProjectilesManager::Spawn(sf::Vector2f spawn_position, sf::Vector2f direction)
{
	projectiles_.emplace_back(direction);
	projectiles_.back().setPosition(spawn_position);
}

void ProjectilesManager::Refresh(const double dt, const sf::Vector2u& window_size)
{

	// Cleaning unused projectiles
	auto removed_elt = std::remove_if
	(
		projectiles_.begin(),
		projectiles_.end(),
		[](const Projectiles& p) {return p.IsDead(); }
	);


	if (removed_elt != projectiles_.end())
	{
		projectiles_.erase(removed_elt, projectiles_.end());
	}

	for (Projectiles& p : projectiles_)
	{
		p.Move(dt, window_size);
		//p.UpdateAnimation(dt);
	}

}

void ProjectilesManager::CheckCollisions(std::vector<Asteroid>& asteroids)
{
	for(auto& p : projectiles_)
	{
		for(auto& a : asteroids)
		{
			if (p.IsDead() == false && a.IsDead() == false && p.Intersects(a.HitBox()))
			{
				p.SetDeath();
				a.Damage(1);
			}
		}
	}
}

void ProjectilesManager::CheckCollisions(std::vector<Enemy>& enemies)
{
	for (auto& p : projectiles_)
	{
		for(auto& e : enemies)
		{
			if (p.IsDead() == false && e.IsDead() == false && p.Intersects(e.HitBox()))
			{
				p.SetDeath();
				e.Damage(1);
			}
		}
	}
}

void ProjectilesManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for(const Projectiles& p : projectiles_)
	{
		target.draw(p);
	}
}