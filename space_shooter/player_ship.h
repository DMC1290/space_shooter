#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <vector>

#include "entity.h"
#include "asteroid.h"
#include "enemy.h"
#include "projectiles_manager.h"

class PlayerShip : public Entity
{
public:

	PlayerShip();

	sf::FloatRect HitBox() const { return hit_box_; }
	sf::Vector2f GetPosition() const { return getPosition(); }

	bool IsShootReady() const { return is_shoot_ready_; }
	double Shoot() const { return shoot_dt_; }
	void ShootConfirm() { is_shoot_ready_ = false; }
	int GetHP() { return hp_; }

	void SetPosition(sf::Vector2u position);

	void UpdateHitBox();
	void Refresh(const double dt);
	void HitPlayerShip();
	void Damage(int damage);
	void SetDeath();

	void CheckCollisions(std::vector<Asteroid>& asteroids);
	void CheckCollisions(std::vector<Projectiles>& projectiles);
	void CheckCollisions(std::vector<Enemy>& enemies);
	void CheckCollisionsAsteroids(std::vector<Asteroid>& asteroids);
	void CheckCollisionsProjectiles(std::vector<Projectiles>& projectiles);
	void CheckCollisionsEnemies(std::vector<Enemy>& enemies);

protected:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:

	static sf::Texture texture_;
	sf::FloatRect hit_box_;

	double shoot_dt_ = 0.f;
	double hit_dt_ = 0.f;

	bool is_shoot_ready_ = false;
	bool is_hit_ = false;

	float blink_interval_ = 0.1f;
	float blink_duration_ = 1.f;
	

	int hp_ = 3;
};
#endif