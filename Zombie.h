#pragma once
#include "Enemy.h"
class Zombie : public Enemy
{
public:
	Zombie(sf::Vector2f position, float largeur, float taille, float ms, float maxlaVie, sf::Color color);
	void draw(sf::RenderWindow& w);
	void update(float dt, sf::RenderWindow& w, sf::Vector2f playerPos);
};

