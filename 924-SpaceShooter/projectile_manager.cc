#include "projectile_manager.h"

#include <SFML/Graphics/RenderTarget.hpp>

void ProjectileManager::Spawn(sf::Vector2f spawn_position)
{
	projectiles_.emplace_back();
	projectiles_.back().setPosition(spawn_position);
}

void ProjectileManager::Refresh(float dt)
{
	for (Projectile& p : projectiles_)
	{
		p.Move(dt);
	}
}

void ProjectileManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for(const Projectile& p : projectiles_)
	{
		target.draw(p);
	}
}


