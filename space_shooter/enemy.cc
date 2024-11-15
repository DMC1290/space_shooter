#include "enemy.h"


sf::Texture Enemy::texture_;

constexpr double kShootPeriod = 0.2f;
constexpr double kBurstPeriod = 0.6f;

Enemy::Enemy()
{
	texture_.loadFromFile("assets\\sprites\\enemy_ship.png");

	sprite_.setTexture(texture_);
	sprite_.setOrigin(sprite_.getTextureRect().width / 2, sprite_.getTextureRect().height / 2);
	sprite_.setRotation(180);
	sprite_.setScale(3.f, 3.f);

	hit_box_.width = static_cast<float>(sprite_.getTextureRect().width) * sprite_.getScale().x;
	hit_box_.height = static_cast<float>(sprite_.getTextureRect().height) * sprite_.getScale().y;

	direction_ = { 0 , 150 };
}

void Enemy::Refresh(const double dt)
{
	shoot_dt_ += dt;
	burst_dt_ += dt;

	if (burst_dt_ >= kBurstPeriod)
	{
		burst_ready_ = !burst_ready_;
		burst_dt_ = 0;
	}

	if (shoot_dt_ >= kShootPeriod && burst_ready_)
	{
		shoot_dt_ = 0;
		is_shoot_ready_ = true;
	}
	else
	{
		is_shoot_ready_ = false;
	}
}

void Enemy::Damage(const int damage)
{
	hp_ -= damage;

	if (hp_ <= 0)
	{
		SetDeath();
	}
}

void Enemy::SetDeath()
{
	Entity::SetDeath();
}