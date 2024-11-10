#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H

#include<vector>

#include"enemy.h"
#include "projectiles_manager.h"

class EnemyManager : public sf::Drawable
{
public:
	std::vector<Enemy>& GetEntities() { return enemies_; }
	void Refresh(const double dt, const sf::Vector2u& window_size, ProjectilesManager& enemy_projectiles_manager);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	std::vector<Enemy> enemies_;
	double spawn_dt_ = 0;
};
#endif
