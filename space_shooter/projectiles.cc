#include "projectiles.h"

sf::Texture Projectiles::texture_;
// animation projectile
//std::array<sf::Texture, 4> Projectiles::animation_;


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

// animation projectile

//void ProjectileAnimation(float dt)
//{
//	time_elapsed_ += dt;
//	if(time_elapsed_ > 0.25f)
//	{
//		idx_texture_++;
//		if(idx_texture_ >= animation_.size())
//		{
//			idx_texture_ = 0;
//		}
//
//		time_elapsed_ = 0;
//		sprite_.setTexture(animation_[idx_texture_]);
//	}
//}