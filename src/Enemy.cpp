#include "../include/Enemy.h"

Enemy::Enemy(sf::Vector2f position, float largeur, float taille, float ms, float maxlaVie, sf::Color color)
	:dead{false},position{position},largeur{largeur},taille{taille},maxlaVie{maxlaVie},laVie{maxlaVie},color{color},ms{ms}
{
	body.setSize(sf::Vector2f(largeur, taille));
	frame.setSize(sf::Vector2f(largeur, taille));
	body.setOrigin(largeur / 2, taille / 2);
	frame.setOrigin(largeur / 2, taille / 2);
	frame.setPosition(position);

	body.setPosition(position);
	body.setFillColor(color);

	frame.setOutlineThickness(1);
	frame.setFillColor(sf::Color::Transparent);
	frame.setOutlineColor(sf::Color(255, 255, 255));
}

void Enemy::draw(sf::RenderWindow& w)
{
	w.draw(body);
	w.draw(frame);
}

void Enemy::update(float dt, sf::RenderWindow& w, sf::Vector2f playerPos)
{
	sf::Vector2f movement{ sf::Vector2f(0.f,0.f) };
	position = body.getPosition();
	sf::Vector2f targetPoint = playerPos;

	float a = (abs(position.y - targetPoint.y)) / (abs(position.x - targetPoint.x));
	float angle = atan(a);

	movement.x = ms * cos(angle);
	movement.y = ms * sin(angle);

	if (targetPoint.x <= position.x)
	{
		movement.x *= -1;
		angle *= -1;
		if (targetPoint.y < position.y)
		{
			movement.y *= -1;
			angle *= -1;
		}

	}
	else
	{
		if (targetPoint.y < position.y)
		{
			movement.y *= -1;
			angle *= -1;
		}
	}

	body.setRotation(angle * 57.29f);
	frame.setRotation(angle * 57.29f);


	if (abs(body.getPosition().x - targetPoint.x) < 2 && abs(body.getPosition().y - targetPoint.y) < 2)
		movement = sf::Vector2f(0.f, 0.f);

	
	body.move(movement * dt);
	frame.move(movement * dt);

	if (laVie < 0.f)
		dead = true;

	float percent = laVie / maxlaVie;

	body.setSize(sf::Vector2f(percent * largeur, taille));
}

void Enemy::take_damage(float dmg)
{
	laVie -= dmg;
}

bool Enemy::get__dead()
{
	return dead;
}

sf::FloatRect Enemy::get__Global_Bounds()
{
	return body.getGlobalBounds();
}

