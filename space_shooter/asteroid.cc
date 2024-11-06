#include "asteroid.h"

#include <random>
#include <SFML/Graphics.hpp>

Asteroid::Asteroid()
{


	texture_.loadFromFile("assets\\sprites\\png_redux\\Meteors\\meteorGrey_med1");
	sprite_.setTexture(texture_);



	std::random_device rn_device;
	
}