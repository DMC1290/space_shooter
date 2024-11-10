#ifndef ASTEROID_H
#define ASTEROID_H

#include "entity.h"

class Asteroid : public Entity
{

public:

	Asteroid();

private:

	static sf::Texture texture_;

};
#endif