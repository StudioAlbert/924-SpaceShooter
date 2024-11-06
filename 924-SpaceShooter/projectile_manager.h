#ifndef PROJECTILE_MANAGER_H
#define PROJECTILE_MANAGER_H

#include <vector>
#include <SFML/System/Clock.hpp>

#include "asteroid.h"
#include "Projectile.h"

class ProjectileManager : public sf::Drawable
{

private:
	std::vector<Projectile> projectiles_;
	sf::Clock cooldown_timer_;
	float cooldwon_dt_ = 0;

public:
	void Spawn(sf::Vector2f spawn_position);
	void Refresh(float dt, const sf::Vector2u& window_size);
	void CheckAsteroidsCollisions(std::vector<Asteroid>& asteroids);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

#endif // PROJECTILE_MANAGER_H
