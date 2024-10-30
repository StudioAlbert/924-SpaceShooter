#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics/RenderWindow.hpp>

#include "projectile_manager.h"

class Game
{

private:
	sf::RenderWindow window_;
	ProjectileManager projectiles_;

	sf::Clock clock_;
	float dt_ = 0.016f;

public:
	Game();
	void Loop();
};


#endif // GAME_H
