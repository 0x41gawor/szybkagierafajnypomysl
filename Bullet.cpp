#include "Bullet.h"

Bullet::Bullet(sf::Vector2i aimPos, sf::Vector2f shooterPos, float Velocity, float radius, sf::Color color):dead{false}
{
	body.setFillColor(color);
	body.setPosition(shooterPos);
	body.setRadius(radius);
	body.setOrigin(sf::Vector2f(body.getGlobalBounds().width / 2, body.getGlobalBounds().height / 2));

	float a = (abs(shooterPos.y - aimPos.y)) / (abs(aimPos.x - shooterPos.x));
	float angle = atan(a);

	velocity.x = Velocity * cos(angle);
	velocity.y = Velocity * sin(angle);

	if (aimPos.x <= shooterPos.x)
	{
		velocity.x *= -1;
		if (aimPos.y < shooterPos.y)
			velocity.y *= -1;
	}
	else
	{
		if (aimPos.y < shooterPos.y)
			velocity.y *= -1;
	}
}

void Bullet::update(float dt)
{
	body.move(velocity.x * dt, velocity.y * dt);
}

void Bullet::draw(sf::RenderWindow& w)
{
	w.draw(body);
}

bool Bullet::out_of_map()
{
	return(body.getPosition().x < 0 || body.getPosition().y < 0 || body.getPosition().x>WIN_X || body.getPosition().y > WIN_Y);
}

sf::Vector2f Bullet::get__position()
{
	return body.getPosition();
}

bool Bullet::get__dead()
{
	return dead;
}

void Bullet::set__dead(bool dead)
{
	this->dead = dead;
}
