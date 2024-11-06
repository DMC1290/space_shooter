#include "projectiles_manager.h"

#include "asteroid.h"


void ProjectilesManager::Spawn(sf::Vector2f spawn_position)
{
	projectiles_.emplace_back();
	projectiles_.back().setPosition(spawn_position);
}

void ProjectilesManager::Refresh(float dt, const sf::Vector2u& window_size)
{
	auto removed_elt = std::remove_if
	(
		projectiles_.begin(),
		projectiles_.end(),
		[](const Projectiles& p) {return p.IsDead(); }
	);


	if (removed_elt != projectiles_.end())
	{
		projectiles_.erase(removed_elt);
	}

	for (Projectiles& p : projectiles_)
	{
		p.PlayerProjectilesMove(dt, window_size);
	}
}


void ProjectilesManager::CheckAsteroidsCollisions(std::vector<Asteroid>& asteroids)
{
	for(auto& p : projectiles_)
	{
		for(auto& a : asteroids)
		{
			if (p.isDead()==false && a.IsDead()==false && p.Intersects(a.HitBox))
			{
				p.SetDeath();
				a.SetDeath();
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
