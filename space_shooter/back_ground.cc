
#include "back_ground.h"


sf::Texture BackGround::texture_;

BackGround::BackGround()
{
	texture_.loadFromFile("assets\\sprites\\space_background.jpeg");

	sprite_.setTexture(texture_);
	sprite_.setOrigin(0, 0);
	sprite_.setPosition(0,0);
	sprite_.setScale(1.0f, 1.0f);
	sprite_.setColor(sf::Color (250, 250, 250, 200));
}


void BackGround::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw( sprite_, states );

}