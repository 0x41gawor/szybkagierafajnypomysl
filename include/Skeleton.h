#pragma once
#include "Enemy.h"
#include "Gun.h"
class Skeleton: public Enemy
{
	Gun gun;

  public:
	Skeleton(sf::Vector2f position, float largeur, float taille, float ms, float maxlaVie, sf::Color color,
		float gunRadius, sf::Color gunColor, float gunVelocity, float gunDamage, float gunAttackSpeed);
	void draw(sf::RenderWindow& w);
	void update(float dt, sf::RenderWindow& w, sf::Vector2f playerPos);

	float get__gun_damage();
	std::vector<Bullet>* gun_share_bullets();
};

