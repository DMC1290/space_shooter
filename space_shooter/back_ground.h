#ifndef BACK_GROUND_H
#define BACK_GROUND_H

#include <SFML/Graphics.hpp>


class BackGround : public sf::Drawable
{
public:

	BackGround();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:

	static sf::Texture texture_;
	sf::Sprite sprite_;
};
#endif