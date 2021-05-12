#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

namespace HUD
{
	class Cursor
	{
																							// D R A W I N G
		sf::Sprite body;																	// sprite representing cursor
		sf::Texture tex;																	// texture for `body`

	public:
		Cursor();
		void update(sf::Vector2i pos);
		void draw(sf::RenderWindow& window);
	};
}



