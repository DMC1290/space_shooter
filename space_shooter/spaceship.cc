#include "spaceship.h"
#include<iostream>


SpaceShip::SpaceShip()
{
	
}

PlayerShip::PlayerShip()
{
	player_texture_.loadFromFile("assets\\sprites\\png_redux\\playerShip1_red.png");
	player_sprite_.setTexture(player_texture_);
	ship_.setTexture(&player_texture_);
	ship_.setSize(sf::Vector2f(player_texture_.getSize()));
	ship_.setOrigin(ship_.getSize() / 2.f);
	ship_.setPosition(sf::Vector2f(0,0));
}

void PlayerShip::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(ship_, states);
}

void PlayerShip::setPosition(sf::Vector2f position)
{
	ship_.setPosition(position);
}

EnemyShip::EnemyShip()
{

}

void EnemyShip::EnemyShipPosition()
{
	setPosition(getPosition());
}