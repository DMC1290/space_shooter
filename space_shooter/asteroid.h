#ifndef ASTEROID_H
#define ASTEROID_H

#include "entity.h"

class Asteroid : public Entity
{

public:

	Asteroid();

	void Damage(int damage);
	void SetDeath();

private:

	static sf::Texture texture_;

	int hp_ = 10;

};
#endif