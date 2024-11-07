#ifndef STARSHIP_H
#define STARSHIP_H

#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include "asteroid.h"

constexpr float kSpeed = 500.f;

class Starship : public sf::Drawable, private sf::Transformable
{
private:
	sf::Texture texture_;
	sf::Sprite sprite_;

public:
	Starship();
	void Move(sf::Vector2f direction, float dt);

	void SetPosition(sf::Vector2u position);
	sf::Vector2f GetPosition() { return getPosition(); }
	void CheckCollisions(const std::vector<Asteroid>& vector);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
