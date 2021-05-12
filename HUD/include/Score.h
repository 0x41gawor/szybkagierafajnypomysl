#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

namespace HUD
{
	class Score
	{
																							// D R A W I N G
		sf::Font font;																		// font of text displaying score
		sf::Text text;																		// text displaying score
		
	public:
		Score();
		void update(int deadEnemies);
		void draw(sf::RenderWindow& window);
	};
}



