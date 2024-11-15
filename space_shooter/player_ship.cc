#include "player_ship.h"

#include <iostream>
#include <SFML/Audio.hpp>


sf::Texture PlayerShip::texture_;

constexpr double kShootPeriod = 0.15f;

PlayerShip::PlayerShip()
{
	texture_.loadFromFile("assets\\sprites\\space_ship.png");

	sprite_.setTexture(texture_);
	sprite_.setOrigin(texture_.getSize().x / 2, texture_.getSize().y / 2);
	sprite_.setRotation(0);
	sprite_.setScale(1.f, 1.f);
}

void PlayerShip::SetPosition(sf::Vector2u position)
{
	setPosition(sf::Vector2f(position));
	UpdateHitBox();
}

void PlayerShip::UpdateHitBox()
{
	hit_box_ = sprite_.getGlobalBounds();
	hit_box_.left += getPosition().x;
	hit_box_.top += getPosition().y;
}

void PlayerShip::Refresh(const double dt)
{
	shoot_dt_ += dt;

	if (shoot_dt_ > kShootPeriod)
	{
		shoot_dt_ = 0;
		is_shoot_ready_ = true;
	}

	if (is_hit_ == true)
	{
		hit_dt_ += dt;
		if (hit_dt_ >= 3.f)
		{
			is_hit_ = false;
			hit_dt_ = 0;
		}
		// invincibility only when player hits a laser
	}

	if (is_hit_)
	{
		sprite_.setColor(sf::Color(255, 100, 100, 200)); //pendant un court instant
	}
	else
	{
		sprite_.setColor(sf::Color(255, 255, 255, 255));
	}
}

void PlayerShip::HitPlayerShip()
{
	is_hit_ = true;
}

void PlayerShip::Damage(int damage)
{
	if (is_hit_ == true)
	{
		hp_ -= damage;

		std::cout << "Player has : " << hp_ << " HP" << '\n';
	}

	if (hp_ <= 0)
	{
		SetDeath();

		std::cout << "Player is dead\n";
	}

}

void PlayerShip::SetDeath()
{
	if (is_hit_)
	{
		Entity::SetDeath();
	}

	if (IsDead())
	{
		hp_ = 0;
		std::cout << "Player is dead!" << '\n';
	}
}

// killing asteroids by touching spaceship
void PlayerShip::CheckCollisions(std::vector<Asteroid>& asteroids)
{

	for (auto& a : asteroids)
	{
		if (a.IsDead() == false && hit_box_.intersects(a.HitBox()))
		{
			a.SetDeath();
			return;

		}
	}
}

// killing projectiles by touching spaceship
void PlayerShip::CheckCollisions(std::vector<Projectiles>& projectiles)
{
	for (auto& p : projectiles)
	{
		if (p.IsDead() == false && hit_box_.intersects(p.HitBox()))
		{
			p.SetDeath();
			return;
		}
	}
}

// killing enemies by touching spaceship
void PlayerShip::CheckCollisions(std::vector<Enemy>& enemies)
{

	for (auto& e : enemies)
	{
		if (e.IsDead() == false && hit_box_.intersects(e.HitBox()))
		{
			e.SetDeath();

		}
		
	}

}

// killing spaceship by touching asteroids
void PlayerShip::CheckCollisionsAsteroids(std::vector<Asteroid>& asteroids)
{
	for (auto& a : asteroids)
	{
		if (IsDead() == false && hit_box_.intersects(a.HitBox()))
		{
			HitPlayerShip();

			
				SetDeath();
			
			return;
		}
	}
}

// killing spaceship by touching projectiles
void PlayerShip::CheckCollisionsProjectiles(std::vector<Projectiles>& projectiles)
{
	if (is_hit_)
	{
		return;
	}

	for (auto& p : projectiles)
	{
		if (IsDead() == false && hit_box_.intersects(p.HitBox()))
		{
			HitPlayerShip();

				Damage(1);
			
			return;
		}
	}
}

// killing spaceship by touching enemies
void PlayerShip::CheckCollisionsEnemies(std::vector<Enemy>& enemies)
{
	for (auto& e : enemies)
	{
		if (IsDead() == false && hit_box_.intersects(e.HitBox()))
		{
			HitPlayerShip();
			
			
				SetDeath();
			
			return;
		}
	}
}


void PlayerShip::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	//Draw HitBox
	sf::RectangleShape rectangle({ hit_box_.width, hit_box_.height });
	rectangle.setPosition(hit_box_.left, hit_box_.top);
	rectangle.setFillColor(sf::Color(255, 255, 255, 0));
	rectangle.setOutlineColor(sf::Color(255, 0, 0, 255));
	rectangle.setOutlineThickness(1);

	//target.draw(rectangle);

	target.draw(sprite_, states);
}