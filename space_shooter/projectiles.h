#ifndef PROJECTILES_H
#define PROJECTILES_H

#include "entity.h"

class Projectiles : public Entity
{

public:
	Projectiles(sf::Vector2f direction);
	//void UpdateAnimation(const double dt);

private:
	static sf::Texture texture_;

	// animation projectile

	//static std::array<sf::Texture, 4> animation_;
	//float time_elapsed_ = 0.f;
	//int idx_texture_ = 0;
};
#endif