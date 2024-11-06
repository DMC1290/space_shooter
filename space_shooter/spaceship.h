#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include "projectiles_manager.h"
#include "enemy.h"
#include "game.h"


class SpaceShip : public sf::Drawable, public sf::Transformable
{
public:
	
	SpaceShip();

protected:

private:

};


class PlayerShip : public SpaceShip
{
public:
	PlayerShip();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void setPosition(sf::Vector2f position);
private:
	sf::Sprite player_sprite_;
	sf::Texture player_texture_;
	sf::RectangleShape ship_;
};


class EnemyShip : protected SpaceShip, protected Enemy
{
public:
	EnemyShip();
	void EnemyShipPosition();

private:

};
#endif