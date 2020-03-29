#include "Player.h"

Player::Player() :largeur{ PLAYER_LARGEUR }, taille{ PLAYER_TAILLE }, ms{ PLAYER_MS }, color{ PLAYER_COLOR }
{
	body.setSize(sf::Vector2f(largeur, taille));
	body.setOrigin(largeur / 2, taille / 2);
	body.setPosition(WIN_X / 2, WIN_Y / 2);
	body.setFillColor(color);
}

void Player::draw(sf::RenderWindow& w)
{
	w.draw(body);
}

void Player::update(float dt, sf::RenderWindow& w)
{
	position = body.getPosition();

	//<  M O V E M E N T   C O N T R O L  >
	update__movement_control(w);
	//< / M O V E M E N T   C O N T R O L >

	body.move(movement * dt);
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
	}

	if (abs(body.getPosition().x - targetPoint.x) < 2 && abs(body.getPosition().y - targetPoint.y) < 2)
		movement = sf::Vector2f(0.f, 0.f);
}
