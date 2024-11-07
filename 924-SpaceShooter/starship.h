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

constexpr double kSpeed = 500.f;

class Starship : public sf::Drawable, private sf::Transformable
{
private:
	sf::Texture texture_;
	sf::Sprite sprite_;
	sf::FloatRect hit_box_;

	double shoot_dt_ = 0.f;
	bool is_shoot_ready_ = false;

public:
	Starship();
	void Move(sf::Vector2f direction, const double dt);

	sf::FloatRect HitBox() const{ return hit_box_; }
	sf::Vector2f GetPosition() const { return getPosition(); }
	bool IsShootReady() const { return is_shoot_ready_; }
	void ShootConfirm() { is_shoot_ready_ = false; }

	void SetPosition(sf::Vector2u position);

	void UpdateHitBox();
	void Refresh(const double dt);
	void CheckCollisions(std::vector<Asteroid>& asteroids);
	void CheckCollisions(std::vector<Projectile>& projectiles);
	void CheckCollisions(std::vector<Enemy>& enemies);

	
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
