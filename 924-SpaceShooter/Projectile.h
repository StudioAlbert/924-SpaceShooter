#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Transformable.hpp>



class Projectile : public sf::Drawable, public sf::Transformable
{

private:
	static sf::Texture texture_;

	sf::Vector2f direction_;
	sf::Sprite sprite_;

public:
	Projectile();

	void Move(float dt);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	// TODO : IsDead ????????

};

#endif
