#include "Gun.h"

Gun::Gun(float radius, sf::Color color, float Velocity, float damage, float attackSpeed)
	:radius{ radius }, color{ color }, Velocity{ Velocity }, damage{ damage }, attackSpeed{ attackSpeed }, timeSinceLastShot{ 0.f }
{
	;;
}

void Gun::update(float dt, sf::RenderWindow& w)
{
	for (int i = 0; i < (int)bullets.size(); i++)
	{
		bullets[i].update(dt);
		if (bullets[i].out_of_map())
			bullets.erase(bullets.begin() + i);
	}
	timeSinceLastShot += dt;
}

void Gun::draw(sf::RenderWindow& w)
{
	for (int i = 0; i < (int)bullets.size(); i++)
	{
		bullets[i].draw(w);
	}
}

void Gun::fire(sf::Vector2i aimPos, sf::Vector2f shooterPos, float dt)
{
	if (timeSinceLastShot > attackSpeed)
	{
		bullets.emplace_back(aimPos, shooterPos, Velocity, radius, color);
		timeSinceLastShot = 0.f;
	}
}
