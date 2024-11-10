#include "player_ship_manager.h"

#include <iostream>


void PlayerShipManager::Refresh(const double dt, const sf::Vector2u& window_size, ProjectilesManager& player_projectiles_manager)
{
		player_.Refresh(dt);

		if(player_.IsShootReady())
		{
			std::cout << "Player Shoot!\n";
			
			player_projectiles_manager.Spawn(player_.GetPosition(), { 0, -1000 });
			player_.ShootConfirm();
		}
}

void PlayerShipManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	
}
