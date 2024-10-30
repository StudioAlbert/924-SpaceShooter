#ifndef PROJECTILE_MANAGER_H
#define PROJECTILE_MANAGER_H

#include <vector>

#include "Projectile.h"

class ProjectileManager : public sf::Drawable
{

private:
	std::vector<Projectile> projectiles_;

public:
	void Spawn(sf::Vector2f spawn_position);
	void Refresh(float dt);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

#endif // PROJECTILE_MANAGER_H
