#include "starship.h"

#include <iostream>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

Starship::Starship()
{
	texture_.loadFromFile("assets\\PNG\\playerShip2_blue.png");

	sprite_.setTexture(texture_);
	sprite_.setOrigin(texture_.getSize().x / 2, texture_.getSize().y / 2);

	setRotation(90);
	setScale(0.5f, 0.5f);

	// Inversion width / height because of rotation
	hit_box_.height = (float)sprite_.getTextureRect().width * getScale().x;
	hit_box_.width = (float)sprite_.getTextureRect().height * getScale().y;

}

void Starship::Move(sf::Vector2f direction, float dt)
{
	move(direction * kSpeed * dt);
	hit_box_.left = getPosition().x - hit_box_.width / 2;
	hit_box_.top = getPosition().y - hit_box_.height / 2;

}

void Starship::SetPosition(sf::Vector2u position)
{
	setPosition(sf::Vector2f(position));
	hit_box_.left = getPosition().x - hit_box_.width / 2;
	hit_box_.top = getPosition().y - hit_box_.height / 2;

}

void Starship::CheckCollisions(std::vector<Asteroid>& asteroids)
{
	for (auto& a : asteroids)
	{
		if (a.IsDead() == false && hit_box_.intersects(a.HitBox()))
		{
			a.SetDeath(); // Death of the asteroid --------------------------
			// Starship damages ?????
		}
	}

}

void Starship::CheckCollisions(std::vector<Projectile>& projectiles)
{
	for (auto& p : projectiles)
	{
		if (p.IsDead() == false && hit_box_.intersects(p.HitBox()))
		{
			p.SetDeath(); // Death of the projectile --------------------------
			// Starship damages ?????
		}
	}
}

void Starship::CheckCollisions(std::vector<Enemy>& enemies)
{
	for (auto& e : enemies)
	{
		if (e.IsDead() == false && hit_box_.intersects(e.HitBox()))
		{
			e.Damage(5);
			// Starship damages ?????
		}
	}
}

void Starship::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	// Draw the hitbox
	//sf::RectangleShape rectangle({hit_box_.width, hit_box_.height});
	//rectangle.setPosition(hit_box_.left, hit_box_.top);
	//rectangle.setFillColor(sf::Color(255,255,255,0));
	//rectangle.setOutlineColor(sf::Color(255,0,0,255));
	//rectangle.setOutlineThickness(1);

	//target.draw(rectangle);

	target.draw(sprite_, states);
}
