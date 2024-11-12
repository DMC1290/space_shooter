#include "player_ship_manager.h"

#include <iostream>


void PlayerShipManager::Refresh(const double dt, const sf::Vector2u& window_size, ProjectilesManager& player_projectiles_manager)
{
	//Clean unused projectiles
	auto removed_elt = std::remove_if
	(
		player_projectiles_.begin(),
		player_projectiles_.end(),
		[](const PlayerShip& p) { return p.IsDead(); }
	);

	if (removed_elt != player_projectiles_.end())
	{
		player_projectiles_.erase(removed_elt, player_projectiles_.end());
	}

	//Move remaining projectiles
	int i = 0;
	for (auto& p : player_projectiles_)
	{
		p.Refresh(dt);

		p.Move(dt, window_size);

		if (p.IsShootReady())
		{

			player_projectiles_manager.Spawn(p.GetPosition(), { 0, -1000 });
			p.ShootConfirm();
		}

		i++;
	}
}

void PlayerShipManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for(auto& p : player_projectiles_)
	{
		target.draw(p);
	}
}
