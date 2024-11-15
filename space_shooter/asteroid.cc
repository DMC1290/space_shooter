#include "asteroid.h"

#include <random>

sf::Texture Asteroid::texture_;

Asteroid::Asteroid()
{

	texture_.loadFromFile("assets\\foozle\\Foozle_EnvironmentPack\\Asteroids\\PNGs\\Asteroid 01 - Base.png");
	sprite_.setTexture(texture_);
	sprite_.setOrigin( texture_.getSize().x / 2, texture_.getSize().y / 2);
	sprite_.setScale( 2.0f, 2.0f);

	std::random_device rn_device;

	std::default_random_engine engine(rn_device());
	std::uniform_real_distribution <float> rnd_x(-200.0, 200.0);
	std::uniform_real_distribution <float> rnd_y(150.0, 300);

	direction_ = { rnd_x(engine) , rnd_y(engine) };
}

void Asteroid::Damage(const int damage)
{
	hp_ -= damage;

	if (hp_ <= 0)
	{
		SetDeath();
	}
}

void Asteroid::SetDeath()
{
	Entity::SetDeath();
}