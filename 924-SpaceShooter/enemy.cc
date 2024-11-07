#include "enemy.h"

sf::Texture Enemy::texture_;

constexpr float kShootPeriod = 0.01f;
constexpr float kBurstPeriod = 0.3f;

Enemy::Enemy()
{

	texture_.loadFromFile("assets\\PNG\\Enemies\\enemyRed2.png");
	sprite_.setTexture(texture_);
	sprite_.setOrigin(sprite_.getTextureRect().width / 2, sprite_.getTextureRect().height / 2);
	sprite_.setRotation(90);
	sprite_.setScale(0.6f, 0.6f);

	hit_box_.width = (float)sprite_.getTextureRect().width * sprite_.getScale().x;
	hit_box_.height = (float)sprite_.getTextureRect().height * sprite_.getScale().y;

	direction_ = { -150, 0 };

}

sf::Vector2f Enemy::GetPosition()
{
	return getPosition();
}

void Enemy::Refresh(float dt)
{
	shoot_dt_ += dt;

	burst_dt_ += dt;
	if(burst_dt_ >= kBurstPeriod)
	{
		wait_shoot_ = !wait_shoot_;
		burst_dt_ = 0;
	}
}

void Enemy::Damage(int damage)
{
	hp_ -= damage;

	if (hp_ <= 0)
	{
		SetDeath();
	}
}

bool Enemy::IsShootReady()
{

	if (shoot_dt_ >= kShootPeriod && !wait_shoot_)
	{
		shoot_dt_ = 0;
		return true;
	}

	return false;

}


void Enemy::SetDeath()
{
	Entity::SetDeath();
}
