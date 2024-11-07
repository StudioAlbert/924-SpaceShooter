#ifndef ENTITY_H
#define ENTITY_H

#define _USE_MATH_DEFINES

#include <math.h>

#include <SFML/Graphics/Sprite.hpp>

class Entity : public sf::Drawable, public sf::Transformable
{

	// Members -----------------
protected:
	sf::Vector2f direction_;
	sf::Sprite sprite_;

	bool is_dead_ = false;

	// Methods -----------------
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
	//Entity();
	bool IsDead() const { return is_dead_; }
	void SetDeath() { is_dead_ = true; }

	void Move(float dt, const sf::Vector2u& window_size);
	bool Intersects(sf::FloatRect hitBox) const;
	sf::FloatRect HitBox() const;

};

#endif // ENTITY_H
