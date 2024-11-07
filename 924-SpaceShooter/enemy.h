#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>

#include "entity.h"

class Enemy : public Entity
{

private:
	static sf::Texture texture_;
	int hp_ = 10;

	double shoot_dt_ = 0.f;
	double burst_dt_ = 0.f;
	bool burst_ready_ = false;
	bool is_shoot_ready_ = false;

	void SetDeath();

public:
	Enemy();

	bool IsShootReady() const { return is_shoot_ready_; }
	double ShootDt() const { return shoot_dt_; }
	sf::Vector2f GetPosition() const { return getPosition(); }

	void Refresh(const double dt);
	void Damage(int damage);

	
};

#endif // ENNEMY_H
