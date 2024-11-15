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

int ProjectilesManager::CheckCollisions(std::vector<Asteroid>& asteroids)
{
	int destroyed_asteroid = 0;

	for(auto& p : projectiles_)
	{
		for(auto& a : asteroids)
		{
			if (p.IsDead() == false && a.IsDead() == false && p.Intersects(a.HitBox()))
			{
				p.SetDeath();
				a.Damage(1);
				destroyed_asteroid++;
			}
		}
	}
	return destroyed_asteroid;
}

int ProjectilesManager::CheckCollisions(std::vector<Enemy>& enemies)
{
	int destroyed_enemy = 0;
	for (auto& p : projectiles_)
	{
		for(auto& e : enemies)
		{
			if (p.IsDead() == false && e.IsDead() == false && p.Intersects(e.HitBox()))
			{
				p.SetDeath();
				e.Damage(1);
				destroyed_enemy++;
			}
		}
	}
	return destroyed_enemy;
}

void ProjectilesManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for(const Projectiles& p : projectiles_)
	{
		target.draw(p);
	}
}