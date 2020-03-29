#pragma once
#include <SFML/Graphics.hpp>
#include "constants.h"

#include "Gun.h"

class Player
{
																							// D R A W I N G
	sf::RectangleShape body;																//rectangle for drawing, representing player
	sf::RectangleShape frame;																//rectangle for drawing frame around player
	float largeur;																			//height of body
	float taille;																			//width of body
	sf::Color color;																		//color of body

																							// M O V I N G
	sf::Vector2f position;																	//current position of body
	sf::Vector2f movement;																	//shift vector of body
	sf::Vector2i targetPoint;																//point clicked by user, indicates direction of movement

																							// G A M E
	float ms;																				//movement speed of body
	Gun gun;

  public:
																							// I N T E R F A C E
	  Player();																				
	  void draw(sf::RenderWindow& w);														
	  void update(float dt, sf::RenderWindow& w);

	  sf::Vector2f get__position();

  private:

	 void update__movement_control(sf::RenderWindow& w);



};

