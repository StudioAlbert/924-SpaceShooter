#include "Projectile.h"

#include <SFML/Graphics/RenderTarget.hpp>

Projectile::Projectile()
{
	texture_.loadFromFile("assets\\PNG\\Lasers\\laserBlue12.png");

	sprite_.setTexture(texture_);
	setRotation(90);
	setScale(0.5f, 0.5f);

	direction_ = { 10 , 0 };

}


void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(sprite_, states);
}

void Projectile::Move(float dt)
{
	setPosition(getPosition() + direction_ * dt);
}



