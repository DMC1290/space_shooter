#ifndef PROJECTILES_H
#define PROJECTILES_H
#include <SFML/Graphics.hpp>


class Projectiles : public sf::Drawable, public sf::Transformable
{

public:

	Projectiles();
	void PlayerProjectilesMove(float dt, const sf::Vector2u& window_size);
	bool IsDead() const { return is_dead_; }

protected:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:

	static sf::Texture texture_;
	sf::Vector2f direction_;
	sf::Sprite sprite_;
	bool is_dead_ = false;
};
#endif