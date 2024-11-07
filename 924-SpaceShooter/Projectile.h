#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "entity.h"


class Projectile : public Entity
{
	
private:
	static sf::Texture texture_;

	// Animation ---------------------------------------------
	static std::array<sf::Texture, 4> animation_;
	double animation_time_ = 0.f;
	int idx_texture_ = 0;

public:
	Projectile(sf::Vector2f direction);
	void UpdateAnimation(const double dt);

};

#endif
