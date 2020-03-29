#pragma once
#include <SFML/Graphics.hpp>
#include "constants.h"

#include "Bullet.h"

class Gun
{
																							//<  B U L L E T   I N F O  >

																							// D R A W I N G 
	float radius;																			// radius of each bullet
	sf::Color color;																		// color of each bullet

																							// M O V I N G
	float Velocity;																			// velocity of each bullet

																							// G A M E
	float damage;																			//damage from each bullet

																							//< / B U L L E T   I N F O >

	std::vector<Bullet> bullets;															//vector of bullets fired														
		
																							// A T T A C K   S P E E D
	float attackSpeed;																		// time between firing a bullets
	float timeSinceLastShot;

  public:
																							// I N T E R F A C E
	Gun(float radius, sf::Color color, float Velocity, float damage, float attackSpeed);
	void update(float dt, sf::RenderWindow& w);
	void draw(sf::RenderWindow& w);
	void fire(sf::Vector2i aimPos, sf::Vector2f shooterPos, float dt);
};

