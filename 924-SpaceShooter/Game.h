#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics/RenderWindow.hpp>

#include "projectile_manager.h"
#include "starship.h"
#include "asteroid_manager.h"

class Game
{

private:
	sf::RenderWindow window_;

	ProjectileManager projectiles_;
	AsteroidManager asteroids_;
	Starship starship_;

	sf::Clock clock_;

public:
	Game();
	void Loop();
};


#endif // GAME_H
