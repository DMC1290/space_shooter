#ifndef PLAYER_SHIP_MANAGER_H
#define PLAYER_SHIP_MANAGER_H

#include "player_ship.h"


class PlayerShipManager : public sf::Drawable
{
public:
	void Refresh(const double dt, const sf::Vector2u& window_size, ProjectilesManager& player_projectiles_manager);
	
protected:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	std::vector<PlayerShip> player_projectiles_;
	PlayerShip player_;
};
#endif