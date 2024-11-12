#include "player_ship.h"

#include <iostream>


sf::Texture PlayerShip::texture_;

constexpr double kShootPeriod = 0.15f;

PlayerShip::PlayerShip()
{
	texture_.loadFromFile("assets\\sprites\\png_redux\\playerShip1_red.png");

	sprite_.setTexture(texture_);
	sprite_.setOrigin(texture_.getSize().x / 2, texture_.getSize().y / 2);
	sprite_.setRotation(0);
	sprite_.setScale(0.5f, 0.5f);
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
}

void PlayerShip::Damage(int damage)
{
	hp_ -= damage;

	if (hp_ <= 0)
	{
		SetDeath();

		std::cout << "Player is dead\n";
	}
}

void PlayerShip::SetDeath()
{
	Entity::SetDeath();

	if (PlayerShip::IsDead())
	{
		std::cout << "Player is dead" << '\n';
	}
}

void PlayerShip::CheckCollisions(std::vector<Asteroid>& asteroids)
{
	for (auto& a : asteroids)
	{
		if (a.IsDead() == false && hit_box_.intersects(a.HitBox()))
		{
			a.SetDeath();
		}
	}
}

void PlayerShip::CheckCollisions(std::vector<Projectiles>& projectiles)
{
	for (auto& p : projectiles)
	{
		if (p.IsDead() == false && hit_box_.intersects(p.HitBox()))
		{
			p.SetDeath();
		}
	}
}

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

void PlayerShip::CheckCollisionsAsteroids(std::vector<Asteroid>& asteroids)
{
	for (auto& a : asteroids)
	{
		if (PlayerShip::IsDead() == false && hit_box_.intersects(a.HitBox()))
		{
			PlayerShip::SetDeath();
		}
	}
}

void PlayerShip::CheckCollisionsProjectiles(std::vector<Projectiles>& projectiles)
{
	for (auto& p : projectiles)
	{
		if (PlayerShip::IsDead() == false && hit_box_.intersects(p.HitBox()))
		{
			PlayerShip::Damage(1);
		}
	}
}

void PlayerShip::CheckCollisionsEnemies(std::vector<Enemy>& enemies)
{
	for (auto& e : enemies)
	{
		if (PlayerShip::IsDead() == false && hit_box_.intersects(e.HitBox()))
		{
			PlayerShip::SetDeath();
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

	target.draw(rectangle);

	target.draw(sprite_, states);
}