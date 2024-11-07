#ifndef STARSHIP_H
#define STARSHIP_H

#include <vector>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include "asteroid.h"
#include "enemy.h"
#include "projectile.h"

constexpr float kSpeed = 500.f;

class Starship : public sf::Drawable, private sf::Transformable
{
private:
	sf::Texture texture_;
	sf::Sprite sprite_;
	sf::FloatRect hit_box_;

public:
	Starship();
	void Move(sf::Vector2f direction, float dt);

	void SetPosition(sf::Vector2u position);
	sf::Vector2f GetPosition() { return getPosition(); }

	sf::FloatRect HitBox() { return hit_box_; }
	void CheckCollisions(std::vector<Asteroid>& asteroids);
	void CheckCollisions(std::vector<Projectile>& projectiles);
	void CheckCollisions(std::vector<Enemy>& enemies);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
