#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>


class Entity : public sf::Drawable, public sf::Transformable
{

public:
	Entity();

	bool IsDead() const { return is_dead_; }


protected:

	sf::Texture texture_;
	sf::Vector2f direction_;
	sf::Sprite sprite_;
	bool is_dead_ = false;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
#endif
