#ifndef PROJECTILES_H
#define PROJECTILES_H

#include "entity.h"

class Projectiles : public Entity
{

public:
	Projectiles(sf::Vector2f direction);
	

private:
	static sf::Texture texture_;

};
#endif