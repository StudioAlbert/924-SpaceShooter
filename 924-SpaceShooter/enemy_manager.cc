#include "enemy_manager.h"

#include <iostream>
#include <random>
#include <SFML/Graphics/RenderTarget.hpp>

#include "projectile.h"

constexpr double kSpawnPeriod = 3.f;

void EnemyManager::Refresh(const double dt, const sf::Vector2u& window_size, ProjectileManager& enemy_missiles_manager)
{

	spawn_dt_ += dt;
	if (enemies_.size() < 3 && spawn_dt_ > kSpawnPeriod)
	{
		enemies_.emplace_back();

		// Tirage al�atoire de Y
		// // Seed with a real random value, if available
		std::random_device rn_device;
		// Choose a random mean between 1 and 6
		std::default_random_engine engine(rn_device());
		std::uniform_real_distribution<float> uniform_dist(0, window_size.y);

		enemies_.back().SetPosition(window_size.x, uniform_dist(engine));

		spawn_dt_ = 0;
	}

	// Cleaning unused projectiles
	auto removed_elt = std::remove_if(
		enemies_.begin(),
		enemies_.end(),
		[](const Enemy& e) {return e.IsDead(); }
	);

	if (removed_elt != enemies_.end())
	{
		enemies_.erase(removed_elt, enemies_.end());
	}

	// Move remaining projectiles
	int i = 0;
	for (auto& e : enemies_)
	{
		e.Refresh(dt);
		e.Move(dt, window_size);

		//std::cout << i << " : " << e.ShootDt() << " :\t" << e.IsShootReady();

		if (e.IsShootReady())
		{
			//std::cout << "\tShoot!!!";
			enemy_missiles_manager.Spawn(e.GetPosition(), { -750, 0 });
		}

		i++;
		//std::cout << '\n';
	}

	//system("cls");

}

void EnemyManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// Move remaining projectiles
	for (auto& e : enemies_)
	{
		target.draw(e);
	}
}


