#ifndef ASTEROID_H
#define ASTEROID_H
#include <vector>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System.hpp>

class AsteroidManager
{
public:
	void Spawn(sf::Vector2f spawn_position);
	void Refresh(float dt, const sf::Vector2u& window_size);

protected:
	//void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	std::vector<AsteroidManager> projectiles_;
	//sf::Clock
	float cooldown_dt_ = 0;


};

#endif // ASTEROID_H
