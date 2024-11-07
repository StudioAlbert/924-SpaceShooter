#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "projectile_manager.h"
#include "starship.h"
#include "asteroid_manager.h"
#include "enemy.h"
#include "enemy_manager.h"

class Game
{

private:
	sf::RenderWindow window_;

	ProjectileManager player_missiles_;
	ProjectileManager enemy_missiles_;

	AsteroidManager asteroids_;
	EnemyManager enemy_manager_;

	Starship starship_;

	sf::Clock clock_;

public:
	Game();
	void Loop();
};


#endif // GAME_H
