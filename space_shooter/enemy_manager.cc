#include "enemy_manager.h"

#include <iostream>
#include <random>
#include <SFML/Graphics/RenderTarget.hpp>

constexpr double kSpawnPeriod = 0.8f;


void EnemyManager::Refresh(const double dt, const sf::Vector2u& window_size, ProjectilesManager& enemy_projectiles_manager)
{
	spawn_dt_ += dt;
	sound_cooldown_ += dt;

	if (enemies_.size() < 30 && spawn_dt_ > kSpawnPeriod)
	{
		enemies_.emplace_back();

		std::random_device rn_device;

		std::default_random_engine engine(rn_device());
		std::uniform_real_distribution<float> uniform_dist(0, window_size.x);

		enemies_.back().SetPosition(uniform_dist(engine), 0);

		spawn_dt_ = 0;
	}

	//Clean unused projectiles
	auto removed_elt = std::remove_if
	(
		enemies_.begin(),
		enemies_.end(),
		[](const Enemy& e) { return e.IsDead(); }
	);

	if (removed_elt != enemies_.end())
	{
		enemies_.erase(removed_elt, enemies_.end());

	}

	// Move remaining projectiles
	int i = 0;
	for (auto& e : enemies_)
	{
		e.Refresh(dt);
		//p.setRotation(180);
		e.Move(dt, window_size);


		if (e.IsShootReady())
		{
			enemy_projectiles_manager.Spawn(e.GetPosition(), { 0, 500 });


			if (sound_cooldown_ >= kSoundInterval_)
			{
				sound_fx_laser_enemy_.loadFromFile("assets\\sound_effect\\kenney_sci-fi-sounds\\Audio\\laserSmall_000.ogg");
				laser_enemy_.setBuffer(sound_fx_laser_enemy_);
				laser_enemy_.play();
				laser_enemy_.setVolume(50);
				activeEnemySounds_.push_back(laser_enemy_);
				sound_cooldown_ = 0.2f;
			}

		}

		i++;

	}


	activeEnemySounds_.erase
		(
		std::remove_if(activeEnemySounds_.begin(), activeEnemySounds_.end(), [](const sf::Sound& s)
			{
				return s.getStatus() == sf::Sound::Stopped;
			}
		),
			activeEnemySounds_.end()
	);

}

void EnemyManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto& e : enemies_)
	{
		target.draw(e);
	}
}