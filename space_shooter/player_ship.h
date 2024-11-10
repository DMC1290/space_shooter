#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <vector>

#include <SFML/Graphics.hpp>

#include "asteroid.h"
#include "enemy.h"
#include "projectiles_manager.h"

constexpr double kSpeed = 500.0f;

class PlayerShip : public sf::Drawable, public sf::Transformable
{
public:

	PlayerShip();
	//void Move(sf::Vector2f direction, const double dt);

	bool IsShootReady() const { return is_shoot_ready_; }
	void ShootConfirm() { is_shoot_ready_ = false; }

	sf::FloatRect HitBox() const { return hit_box_; }
	sf::Vector2f GetPosition() const { return getPosition(); }

	void SetPosition(sf::Vector2u position);

	void Refresh(const double dt);
	
	void UpdateHitBox();
	void CheckCollisions(std::vector<Asteroid>& asteroids);
	void CheckCollisions(std::vector<Projectiles>& projectiles);
	void CheckCollisions(std::vector<Enemy>& enemies);

protected:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:

	sf::Texture texture_;
	sf::Sprite sprite_;
	sf::FloatRect hit_box_;

	double shoot_dt_ = 0.f;
	bool is_shoot_ready_ = false;
};
#endif