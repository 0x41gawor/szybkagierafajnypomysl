#include "../include/Player.h"

Player::Player() :largeur{ PLAYER_LARGEUR }, taille{ PLAYER_TAILLE }, ms{ PLAYER_MS }, color{ PLAYER_COLOR }, maxlaVie{1000.f}, laVie{1000.f},
gun{ 4,sf::Color(P_GUN_COLOR),P_GUN_VELOCITY,P_GUN_DAMAGE,P_GUN_AS }, isDead{false}
{
	body.setSize(sf::Vector2f(largeur, taille));
	frame.setSize(sf::Vector2f(largeur, taille));
	body.setOrigin(largeur / 2, taille / 2);
	frame.setOrigin(largeur / 2, taille / 2);
	body.setPosition(WIN_X / 2, WIN_Y / 2);
	frame.setPosition(WIN_X / 2, WIN_Y / 2);
	body.setFillColor(color);
	frame.setFillColor(sf::Color::Transparent);
	frame.setOutlineThickness(1);
	frame.setOutlineColor(sf::Color(255, 255, 255));
}

void Player::draw(sf::RenderWindow& w)
{
	w.draw(body);
	w.draw(frame);
	gun.draw(w);
}

void Player::update(float dt, sf::RenderWindow& w)
{
	position = body.getPosition();

	//<    C O N T R O L  >
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		gun.fire(sf::Mouse::getPosition(w), body.getPosition(), dt);
	}
	update__movement_control(w);
	//< /  C O N T R O L >

	gun.update(dt, w);

	body.move(movement * dt);
	frame.move(movement * dt);

	float percent = laVie / maxlaVie;
	body.setSize(sf::Vector2f(percent * largeur, taille));

	if (laVie < 0.f)
	{
		isDead = true;
	}
}

void Player::take_damage(float dmg)
{
	laVie -= dmg;
	if (laVie > maxlaVie)
		laVie = maxlaVie;
}

sf::Vector2f Player::get__position()
{
	return body.getPosition();
}

float Player::get__gun_damage()
{
	return gun.get__damage();
}

bool Player::get__isDead()
{
	return isDead;
}

std::vector<Bullet>* Player::gun_share_bullets()
{
	return gun.share_bullets();
}

sf::FloatRect Player::get__Global_Bounds()
{
	return body.getGlobalBounds();
}

void Player::update__movement_control(sf::RenderWindow& w)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		targetPoint = sf::Mouse::getPosition(w);

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
	}

	if (abs(body.getPosition().x - targetPoint.x) < 2 && abs(body.getPosition().y - targetPoint.y) < 2)
		movement = sf::Vector2f(0.f, 0.f);
}
