#include "projectiles.h"

sf::Texture Projectiles::texture_;


Projectiles::Projectiles(sf::Vector2f direction)
{
	texture_.loadFromFile("assets\\sprites\\png_redux\\Lasers\\laserRed12.png");

	sprite_.setTexture(texture_);
	sprite_.setColor(sf::Color(255, 255, 255, 255));
	sprite_.setOrigin(texture_.getSize().x / 2, 0);
	sprite_.setScale(0.5f, 0.5f);
	sprite_.setRotation(0);
	direction_ = direction;

}