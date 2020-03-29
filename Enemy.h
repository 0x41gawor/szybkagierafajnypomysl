#pragma once
#include <SFML/Graphics.hpp>
#include "constants.h"

class Enemy
{
  protected:
																							// D R A W I N G
	sf::RectangleShape body;
	sf::RectangleShape frame;
	float largeur;
	float taille;
	sf::Color color;
																							// M O V I N G
	sf::Vector2f position;
																							// G A M E
	float ms;
	float laVie;
	float maxlaVie;
	bool dead;

  public:
																							// I N T E R F A C E
	  Enemy(sf::Vector2f position,float largeur,float taille,float ms, float maxlaVie, sf::Color color);
	  virtual void draw(sf::RenderWindow& w);
	  virtual void update(float dt, sf::RenderWindow& w, sf::Vector2f playerPos);

	  void take_damage(float dmg);

	  bool get__dead();
	  sf::FloatRect get__Global_Bounds();
};

