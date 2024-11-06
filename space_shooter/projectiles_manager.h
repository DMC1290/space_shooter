#ifndef PROJECTILES_MANAGER_H
#define PROJECTILES_MANAGER_H
#include "projectiles.h"
#include <vector>
#include <SFML/Graphics.hpp>

#include "asteroid.h"

class ProjectilesManager : public sf::Drawable
{
public:
	void Spawn(sf::Vector2f spawn_position);
	void Refresh(float dt, const sf::Vector2u& window_size);

protected:

	void CheckAsteroidsCollisions(std::vector<Asteroid>& asteroids);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	std::vector<Projectiles> projectiles_;

};
#endif