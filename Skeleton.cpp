#include "Skeleton.h"

Skeleton::Skeleton(sf::Vector2f position, float largeur, float taille, float ms, float maxlaVie, sf::Color color,
	float gunRadius, sf::Color gunColor, float gunVelocity, float gunDamage,float gunAttackSpeed)
	:Enemy{ position,largeur,taille,ms,maxlaVie,color },
	gun{ 4,sf::Color(P_GUN_COLOR),P_GUN_VELOCITY,P_GUN_DAMAGE,P_GUN_AS }
{
}

void Skeleton::draw(sf::RenderWindow& w)
{
	Enemy::draw(w);
	gun.draw(w);
}

void Skeleton::update(float dt, sf::RenderWindow& w, sf::Vector2f playerPos)
{
	Enemy::update(dt, w, playerPos);
	gun.fire(static_cast<sf::Vector2i> (playerPos), body.getPosition(), dt);
	gun.update(dt, w);
}
