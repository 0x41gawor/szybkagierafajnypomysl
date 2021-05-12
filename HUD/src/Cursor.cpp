#include "../include/Cursor.h"

HUD::Cursor::Cursor()
{
	tex.loadFromFile("res/tex/cursor.png");
	body.setTexture(tex);
	body.setOrigin(5.f, 5.f);
}

void HUD::Cursor::update(sf::Vector2i pos)
{
	body.setPosition(static_cast<sf::Vector2f>(pos));
}


void HUD::Cursor::draw(sf::RenderWindow& window)
{
	window.draw(body);
}
