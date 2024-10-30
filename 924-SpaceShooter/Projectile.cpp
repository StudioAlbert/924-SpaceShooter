#include "Projectile.h"

#include <iostream>
#include <SFML/Graphics/RenderTarget.hpp>

sf::Texture Projectile::texture_;

Projectile::Projectile()
{
	texture_.loadFromFile("assets\\PNG\\Lasers\\laserBlue12.png");

	sprite_.setTexture(texture_);

	setRotation(90);
	setScale(0.5f, 0.5f);

	direction_ = { 1000 , 0 };

}


void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(sprite_, states);
}

void Projectile::Move(float dt, const sf::Vector2u& window_size)
{
	setPosition(getPosition() + direction_ * dt);

	sf::Vector2f position = getPosition();
	if(position.x < 0 || position.x > window_size.x || position.y < 0 || position.y > window_size.y)
	{
		is_dead_ = true;
	}

	// TODO : Tester les collisions avec des trucs ---

}



