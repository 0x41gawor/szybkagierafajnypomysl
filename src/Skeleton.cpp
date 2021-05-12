#include "../include/Skeleton.h"

Skeleton::Skeleton(sf::Vector2f position, float largeur, float taille, float ms, float maxlaVie, sf::Color color,
	float gunRadius, sf::Color gunColor, float gunVelocity, float gunDamage,float gunAttackSpeed)
	:Enemy{ position,largeur,taille,ms,maxlaVie,color },
	gun{ gunRadius,sf::Color(gunColor),gunVelocity,gunDamage,gunAttackSpeed }
{
	;;
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

float Skeleton::get__gun_damage()
{
	return gun.get__damage();
}

std::vector<Bullet>* Skeleton::gun_share_bullets()
{
	return gun.share_bullets();
}
