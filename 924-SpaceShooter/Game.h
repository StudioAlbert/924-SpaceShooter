#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics/RenderWindow.hpp>

#include "Projectile.h"

class Game
{

private:
	sf::RenderWindow window_;
	Projectile laser1_;

	sf::Clock clock_;
	float dt_ = 0.016f;

public:
	Game();
	void Loop();
};


#endif // GAME_H
