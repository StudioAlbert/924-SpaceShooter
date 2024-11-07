#include "projectile_manager.h"

#include <iostream>
#include <SFML/Graphics/RenderTarget.hpp>

#include "asteroid.h"

constexpr float kCooldown_limit_ = 0.25f;

void ProjectileManager::Spawn(sf::Vector2f spawn_position, sf::Vector2f direction)
{

	if(cooldwon_dt_ < kCooldown_limit_)
		return;

	projectiles_.emplace_back(direction);
	projectiles_.back().setPosition(spawn_position);
	cooldwon_dt_ = 0;

}

void ProjectileManager::Refresh(float dt, const sf::Vector2u& window_size)
{

	cooldwon_dt_ += cooldown_timer_.restart().asSeconds();
	//std::cout << "Cooldown Timer : " << cooldwon_dt_ << '\n';


	// Cleaning unused projectiles
	auto removed_elt = std::remove_if(
		projectiles_.begin(), 
		projectiles_.end(), 
		[](const Projectile& p) {return p.IsDead(); }
	);

	if(removed_elt != projectiles_.end())
	{
		projectiles_.erase(removed_elt, projectiles_.end());
	}

	//erase_if(projectiles_, [](const Projectile& p) {return p.IsDead(); });

	// Move remaining projectiles
	for (Projectile& p : projectiles_)
	{
		p.Move(dt, window_size);
		p.UpdateAnimation(dt);
	}

	std::cout << "nb projectiles ? " << projectiles_.size() << '\n';

}

void ProjectileManager::CheckAsteroidsCollisions(std::vector<Asteroid>& asteroids)
{
	for(auto& p : projectiles_)
	{
		for(auto& a : asteroids)
		{
			if (p.IsDead()==false && a.IsDead()==false && p.Intersects(a.HitBox()))
			{
				p.SetDeath();
				a.SetDeath();
			}
		}
	}

}

void ProjectileManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// Move remaining projectiles
	for (const Projectile& p : projectiles_)
	{
		target.draw(p);
	}
}




