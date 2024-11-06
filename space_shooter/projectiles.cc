#include "projectiles.h"

#include <set>


sf::Texture Projectiles::texture_;

Projectiles::Projectiles()
{
	texture_.loadFromFile("assets\\sprites\\png_redux\\Lasers\\laserGreen10.png");

	sprite_.setTexture(texture_);

	//std::setOrigin(0,texture_.getSize(y / 2))
	setRotation(0);
	setScale(0.5f, 0.5f);

	direction_ = { 0 , -1000 };

}


void Projectiles::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(sprite_, states);
}


void Projectiles::PlayerProjectilesMove(float dt, const sf::Vector2u& window_size)
{
	setPosition(getPosition() + direction_ * dt);

	sf::Vector2f position = getPosition();
	if(position.x < 0 || position.x > window_size.x || position.y < 0 || position.y > window_size.y)
	{
		is_dead_ = true;
	}

	// TODO : Tester les collisions avec des trucs...
}