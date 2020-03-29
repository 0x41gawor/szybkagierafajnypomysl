#include <SFML/Graphics.hpp>
#include "constants.h"
#include "Player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIN_X, WIN_Y), "test&recognize");

	Player player;

	sf::Clock clock;
	float dt{ 0.f };
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		dt = clock.restart().asSeconds();

		//<  U P D A T E   S E C T I O N  >
		player.update(dt, window);
		//< / U P D A T E   S E C T I O N >

		//<  D R A W   S E C T I O N  >
		window.clear();
		player.draw(window);
		window.display();
		//< / D R A W   S E C T I O N >
	}

	return 0;
}