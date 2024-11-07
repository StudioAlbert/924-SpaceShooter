#include "starship.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

Starship::Starship()
{
	texture_.loadFromFile("assets\\PNG\\playerShip2_blue.png");

	sprite_.setTexture(texture_);
	sprite_.setOrigin(texture_.getSize().x / 2, texture_.getSize().y / 2);

	setRotation(90);
	setScale(0.5f, 0.5f);

}

void Starship::Move(sf::Vector2f direction, float dt)
{
	move(direction * kSpeed * dt);
}

void Starship::SetPosition(sf::Vector2u position)
{
	setPosition(sf::Vector2f(position));
}

void Starship::CheckCollisions(const std::vector<Asteroid>& vector)
{
}

void Starship::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(sprite_, states);
}
