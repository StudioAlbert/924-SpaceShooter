#ifndef PROJECTILE_MANAGER_H
#define PROJECTILE_MANAGER_H

#include <vector>
#include <SFML/System/Clock.hpp>

#include "asteroid.h"
#include "enemy.h"
#include "Projectile.h"

class ProjectileManager : public sf::Drawable
{

private:
	std::vector<Projectile> projectiles_;
	double cooldwon_dt_ = 0;

public:
	std::vector<Projectile>& GetEntities() { return projectiles_; }

	void Spawn(sf::Vector2f spawn_position, sf::Vector2f direction);
	void Refresh(const double dt, const sf::Vector2u& window_size);

	int CheckCollisions(std::vector<Asteroid>& asteroids);
	int CheckCollisions(std::vector<Enemy>& enemies);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

#endif // PROJECTILE_MANAGER_H
