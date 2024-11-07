#include "starship.h"

#include <iostream>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

constexpr double kShootPeriod = 0.15f;

Starship::Starship()
{
	texture_.loadFromFile("assets\\PNG\\playerShip2_blue.png");

	sprite_.setTexture(texture_);
	sprite_.setOrigin(texture_.getSize().x / 2, texture_.getSize().y / 2);
	sprite_.setRotation(90);
	sprite_.setScale(0.5f, 0.5f);

}

void Starship::Move(sf::Vector2f direction, const double dt)
{
	move(direction.x * kSpeed * dt, direction.y * kSpeed * dt);
	UpdateHitBox();
}

void Starship::SetPosition(sf::Vector2u position)
{
	setPosition(sf::Vector2f(position));
	UpdateHitBox();
}

void Starship::UpdateHitBox()
{
	hit_box_ = sprite_.getGlobalBounds();
	hit_box_.left += getPosition().x;
	hit_box_.top += getPosition().y;
}

void Starship::Refresh(const double dt)
{
	shoot_dt_ += dt;
	if(shoot_dt_ > kShootPeriod)
	{
		is_shoot_ready_ = true;
		shoot_dt_ = 0;
	}
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
	sf::RectangleShape rectangle({hit_box_.width, hit_box_.height});
	rectangle.setPosition(hit_box_.left, hit_box_.top);
	rectangle.setFillColor(sf::Color(255,255,255,0));
	rectangle.setOutlineColor(sf::Color(255,0,0,255));
	rectangle.setOutlineThickness(1);

	target.draw(rectangle);

	target.draw(sprite_, states);
}
