#include "../include/Score.h"

HUD::Score::Score()
{
	if (!font.loadFromFile("res/fonts/DS-DIGI.TTF")) std::cout << "Loading font gone wrong";

	text.setFont(font);

	text.setString("0");
	text.setCharacterSize(80);
}

void HUD::Score::update(int deadEnemies)
{
	text.setString(std::to_string(deadEnemies));
}

void HUD::Score::draw(sf::RenderWindow& window)
{
	window.draw(text);
}
