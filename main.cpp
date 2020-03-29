#include <SFML/Graphics.hpp>
#include "constants.h"
#include "Player.h"
#include "Zombie.h"
#include "Skeleton.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIN_X, WIN_Y), "test&recognize");

	Player player;
	Zombie zombie(sf::Vector2f(100.f, 100.f), 30.f, 80.f, 200.f, 1000.f, sf::Color(255, 20, 90));
	Skeleton skeleton(sf::Vector2f(800.f, 800.f), 30.f, 80.f, 120.f, 1000.f, sf::Color(187, 186, 187), 4, sf::Color(187, 186, 187), 350.f, 200.f, 0.8f);

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
		zombie.update(dt, window, player.get__position());
		skeleton.update(dt, window, player.get__position());
		//< / U P D A T E   S E C T I O N >

		//<  D R A W   S E C T I O N  >
		window.clear();
		player.draw(window);
		zombie.draw(window);
		skeleton.draw(window);
		window.display();
		//< / D R A W   S E C T I O N >
	}

	return 0;
}