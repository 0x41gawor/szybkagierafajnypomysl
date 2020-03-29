#pragma once
#include <SFML/Graphics.hpp>
#include "constants.h"

class Bullet
{
																							// D R A W I N G
	sf::CircleShape body;																	// circle for drawing representing a bullet

																							// M O V I N G
	sf::Vector2f velocity;																	// current velocity of bullet as vector
	

  public:
	Bullet(sf::Vector2i aimPos, sf::Vector2f shooterPos, float Velocity, float radius, sf::Color color);
	void update(float dt);
	void draw(sf::RenderWindow& window);
	bool out_of_map();
};

