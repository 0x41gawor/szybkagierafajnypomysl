#include "Zombie.h"

Zombie::Zombie(sf::Vector2f position, float largeur, float taille, float ms, float maxlaVie, sf::Color color)
	:Enemy{position,largeur,taille,ms,maxlaVie,color}
{
}

void Zombie::draw(sf::RenderWindow& w)
{
	Enemy::draw(w);
}

void Zombie::update(float dt, sf::RenderWindow& w, sf::Vector2f playerPos)
{
	Enemy::update(dt, w, playerPos);
}
