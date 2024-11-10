#include "asteroid.h"

#include <random>

sf::Texture Asteroid::texture_;

Asteroid::Asteroid()
{

	texture_.loadFromFile("assets\\sprites\\png_redux\\Meteors\\meteorGrey_big4.png");
	sprite_.setTexture(texture_);
	sprite_.setOrigin( texture_.getSize().x / 2, texture_.getSize().y / 2);
	sprite_.setScale( 1.0f, 1.0f);

	std::random_device rn_device;

	std::default_random_engine engine(rn_device());
	std::uniform_real_distribution <float> rnd_x(-200.0, 200.0);
	std::uniform_real_distribution <float> rnd_y(250.0, 800);

	direction_ = { rnd_x(engine) , rnd_y(engine) };
}