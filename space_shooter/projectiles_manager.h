#ifndef PROJECTILES_MANAGER_H
#define PROJECTILES_MANAGER_H

#include <vector>

#include "asteroid.h"
#include "enemy.h"
#include "projectiles.h"

class ProjectilesManager : public sf::Drawable, public sf::Transformable
{
public:
	std::vector<Projectiles>& GetEntities() { return projectiles_; }

	void Spawn(sf::Vector2f spawn_position, sf::Vector2f direction);
	void Refresh(const double dt, const sf::Vector2u& window_size);
	void CheckCollisions(std::vector<Asteroid>& asteroids);
	void CheckCollisions(std::vector<Enemy>& enemies);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	std::vector<Projectiles> projectiles_;
	
	double cooldown_dt_ = 0;
};
#endif